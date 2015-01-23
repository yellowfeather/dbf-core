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

static const int MD5_DIGEST_LENGTH = 16;

/* writeHashLine {{{
 * creates a line in the hash document for each data set
 */
int
writeHashLine(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */)
{
    struct md5_ctx ctx;
    unsigned char digest[MD5_DIGEST_LENGTH];

    md5_init(&ctx);
    ctx.size = record_length;
    memcpy(ctx.buf, value, record_length);
    md5_update(&ctx);
    md5_final(digest, &ctx);

    int i;
	for (i = 0; i < 16; ++i) {
		fprintf(fp, "%02x", digest[i]);
	}

	fputs("\n", fp);

	return 0;
}
