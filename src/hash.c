/****************************************************************************
 * hash.c
 ****************************************************************************
 * dbf Reader and Converter for dBASE files
 * Implementation
 *
 * Author: Bjoern Berg <clergyman@gmx.de>
 * Modifications: Uwe Steinmann <uwe@steinmann.cx>
 *
 ****************************************************************************
 * Functions to write hash
 ***************************************************************************/

#include <string.h>
#include <libdbf/libdbf.h>
#include "hash.h"
#include "md5.h"

const int MD5_DIGEST_LENGTH = 16;

void generate_md5_digest(const unsigned char *value, int length, char *output)
{
    static const char hexDigits[16] = "0123456789abcdef";

    unsigned char digest[MD5_DIGEST_LENGTH];

    struct md5_ctx ctx;
    md5_init(&ctx);
    ctx.size = length;
    memcpy(ctx.buf, value, length);
    md5_update(&ctx);
    md5_final(digest, &ctx);

    // Convert the hash into a hex string form
    int i;
    for( i = 0; i < MD5_DIGEST_LENGTH; i++ )
    {
        output[i * 2]   = hexDigits[(digest[i] >> 4) & 0xF];
        output[i * 2 + 1] = hexDigits[digest[i] & 0xF];
    }
    output[MD5_DIGEST_LENGTH * 2] = '\0';
}


/* writeHashLine {{{
 * creates a line in the hash document for each data set
 */
int
writeHashLine(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */,
    const unsigned int dataset_deleted)
{
    char hash[(MD5_DIGEST_LENGTH * 2) + 1];

    generate_md5_digest(value, record_length, hash);
    fprintf(fp, "%s\n", hash);

    return 0;
}
