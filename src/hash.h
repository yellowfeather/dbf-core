/******************************************************************************
 * hash.h
 ******************************************************************************
 * dbf Reader and Converter for dBASE files
 * Author: Chris Richards <chris@yellowfeather.co.uk>
 *
 ******************************************************************************
 * This includes enable dbf to write hash of each line
 ******************************************************************************/

#ifndef _HASH_H_
#define _HASH_H_

#include "dbf.h"

int writeHashLine (FILE *fp, P_DBF * p_dbf, const unsigned char *value,
    int header_length, const char *input, const char *output);

#endif
