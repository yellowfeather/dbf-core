/****************************************************************************
 * index.c
 ****************************************************************************
 * dbf Reader and Converter for dBASE files
 * Implementation
 *
 * Author: Bjoern Berg <clergyman@gmx.de>
 * Modifications: Uwe Steinmann <uwe@steinmann.cx>
 *
 ****************************************************************************
 * Functions to write index
 ***************************************************************************/

#include <string.h>
#include <libdbf/libdbf.h>
#include "index.h"

static int row_number = 0;

int
writeIndexHeader (FILE *fp, P_DBF *p_dbf,
    const char *in /* __unused */, const char *out /* __unused */)
{
  row_number = 0;
  return 0;
}

/* writeIndexLine {{{
 * creates a line in the hash document for each data set
 */
int
writeIndexLine(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */,
    const unsigned int dataset_deleted)
{
  if (dataset_deleted != 1) {
    fprintf(fp, "%08d\n", row_number);
  }

  ++row_number;

  return 0;
}
