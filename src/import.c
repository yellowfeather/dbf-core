/****************************************************************************
 * import.c
 ****************************************************************************
 * dbf Reader and Converter for dBASE files
 * Implementation
 *
 * Author: Bjoern Berg <clergyman@gmx.de>
 * Modifications: Uwe Steinmann <uwe@steinmann.cx>
 *
 ****************************************************************************
 * Functions to write import csv
 ***************************************************************************/

#include <ctype.h>
#include <string.h>
#include <time.h>
#include <libdbf/libdbf.h>
#include "csv.h"
#include "hash.h"
#include "import.h"

static int business_unit_id = 0;

/* setBusinessUnitId() {{{
 * set the business unit id
 */
int
setBusinessUnitId(FILE *output, P_DBF *p_dbf,
    const char *filename, const char *id)
{
  business_unit_id = atoi(id);
  return 0;
}

/* writeImportHeader() {{{
 * creates the CSV Header with the information provided by DB_FIELD
 */
int
writeImportHeader (FILE *fp, P_DBF *p_dbf,
    const char *in /* __unused */, const char *out /* __unused */)
{
  int i, columns;

  columns = dbf_NumCols(p_dbf);
  for (i = 0; i < columns; i++) {
    const char *field_name;
    field_name = dbf_ColumnName(p_dbf, i);
    char *p;
    for (p = (char *)field_name ; *p; ++p) { *p = tolower(*p); }
    fprintf(fp, "%s,", field_name);
  }

  fprintf(fp, "business_unit_id,");
  fprintf(fp, "csv_hash,");
  fprintf(fp, "created_at,");
  fprintf(fp, "updated_at");

  fputs("\n", fp);

  return 0;
}
/* }}} */
/* writeImportLine {{{
 * creates a line in the hash document for each data set
 */
int
writeImportLine(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */,
    const unsigned int dataset_deleted)
{
    writeCSVValues(fp, p_dbf, value, record_length, in, out, dataset_deleted);

    // business_unit_id
    fprintf(fp, ",%d,", business_unit_id);

    // csv_hash
    char hash[(MD5_DIGEST_LENGTH * 2) + 1];
    generate_md5_digest(value, record_length, hash);
    fprintf(fp, "%s,", hash);

    // created_at
    time_t ltime;
    struct tm *Tm;

    ltime = time(NULL);
    Tm = localtime(&ltime);

    fprintf(fp, "%04d-%02d-%02dT%02d:%02d:%02dZ,",
      1900 + Tm->tm_year, Tm->tm_mon + 1, Tm->tm_mday,
      Tm->tm_hour, Tm->tm_min, Tm->tm_sec);

    // updated_at
    fprintf(fp, "%04d-%02d-%02dT%02d:%02d:%02dZ",
      1900 + Tm->tm_year, Tm->tm_mon + 1, Tm->tm_mday,
      Tm->tm_hour, Tm->tm_min, Tm->tm_sec);

    fputs("\n", fp);
    return 0;
}
