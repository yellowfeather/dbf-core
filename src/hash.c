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


const unsigned char *md5sum(const char *chaine, size_t len)
 {
     struct md5_ctx ctx;
     unsigned char digest[16];
     md5_init(&ctx);
     ctx.size = len?len:strlen(chaine);
     strcpy(ctx.buf, chaine);
     md5_update(&ctx);
     md5_final(digest, &ctx);
     return digest;
 }

 /* writeHashLine {{{
 * creates a line in the hash document for each data set
 */
int
writeHashLine(FILE *fp, P_DBF *p_dbf,
    const unsigned char *value, int record_length,
    const char *in /* unused */, const char *out /* unused */)
{
	const unsigned char *digest = md5sum(value, record_length);

	for (int i = 0; i < 16; ++i) {
		fprintf(fp, "%02x", digest[i]);
	}

	fputs("\n", fp);
}
