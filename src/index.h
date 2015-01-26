/******************************************************************************
 * index.h
 ******************************************************************************
 * dbf Reader and Converter for dBASE files
 * Author: Chris Richards <chris@yellowfeather.co.uk>
 *
 ******************************************************************************
 * This includes enable dbf to generate an index file
 ******************************************************************************/

#ifndef _INDEX_H_
#define _INDEX_H_

#include "dbf.h"

int writeIndexHeader (FILE *fp, P_DBF * p_dbf,
    const char *input, const char *output);

int writeIndexLine (FILE *fp, P_DBF * p_dbf, const unsigned char *value,
    int header_length, const char *input, const char *output,
    const unsigned int dataset_deleted);

#endif
