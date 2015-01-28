/******************************************************************************
 * csv.h
 ******************************************************************************
 * dbf Reader and Converter for dBASE files
 * Author: Bjoern Berg <clergyman@gmx.de>
 *
 ******************************************************************************
 * This includes enable dbf to write CSV files
 ******************************************************************************
 * $Id: csv.h,v 1.8 2004/09/07 15:54:01 steinm Exp $
 ******************************************************************************/

#ifndef _CSV_H_
#define _CSV_H_

#include "dbf.h"

int setCSVSep (FILE *fp, P_DBF * p_dbf,
    const char *input, const char *separator);

int
writeCSVValues(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */,
    const unsigned int dataset_deleted);

int writeCSVHeader (FILE *fp, P_DBF * p_dbf,
    const char *input, const char *output);
int writeCSVLine (FILE *fp, P_DBF * p_dbf, const unsigned char *value,
    int header_length, const char *input, const char *output,
    const unsigned int dataset_deleted);
#endif
