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

extern const int MD5_DIGEST_LENGTH;

void generate_md5_digest(const unsigned char *value, int length, char *output);

int writeHashLine (FILE *fp, P_DBF * p_dbf, const unsigned char *value,
    int header_length, const char *input, const char *output,
    const unsigned int dataset_deleted);

#endif
