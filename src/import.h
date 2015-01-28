/******************************************************************************
 * import.h
 ******************************************************************************
 * dbf Reader and Converter for dBASE files
 * Author: Chris Richards <chris@yellowfeather.co.uk>
 *
 ******************************************************************************
 * This includes enable dbf to write import csv
 ******************************************************************************/

#ifndef _IMPORT_H_
#define _IMPORT_H_

#include "dbf.h"

int
setBusinessUnitId(FILE *output, P_DBF *p_dbf,
    const char *filename, const char *id);

int
writeImportHeader (FILE *fp, P_DBF *p_dbf,
    const char *in /* __unused */, const char *out /* __unused */);

int writeImportLine (FILE *fp, P_DBF * p_dbf, const unsigned char *value,
    int header_length, const char *input, const char *output,
    const unsigned int dataset_deleted);

#endif
