/*
*   $Id$
*
*   Copyright (c) 1996-2003, Darren Hiebert
*
*   This source code is released for free distribution under the terms of the
*   GNU General Public License.
*
*   This module contains functions for checking multibyte character set.
*/

/*
*   INCLUDE FILES
*/

#ifdef SUPPORT_MULTIBYTE

#include <stdio.h>
#include <iconv.h>
#include "options.h"
#include "routines.h"
#include "mbcs.h"

static iconv_t iconv_fd = (iconv_t) -1;

extern boolean openConverter (char* encoding)
{
	if (!encoding)
		return FALSE;
	iconv_fd = iconv_open("UTF-8", encoding);
	return iconv_fd != (iconv_t) -1;
}

extern boolean convertString (vString *const string)
{
	size_t utf8_len = 0, mbcs_len, utf8_size;
	char *utf8, *mbcs, *utf8ptr;
	if (iconv_fd == (iconv_t) -1)
		return FALSE;
	mbcs_len = vStringLength (string);
	utf8_len = mbcs_len * 4;
	utf8ptr = utf8 = xCalloc (utf8_len, char);
	if (!utf8)
		return FALSE;
	mbcs = vStringValue (string);
	if (iconv (iconv_fd, &mbcs, &mbcs_len, &utf8ptr, &utf8_len) == (size_t) -1)
	{
	  	eFree (utf8);
		return FALSE;
	}
	utf8_size = utf8ptr - utf8;

	vStringClear (string);
	while (vStringSize (string) <= utf8_size + 1)
		vStringAutoResize (string);
	memcpy (vStringValue (string), utf8, utf8_size + 1);
	vStringLength (string) = utf8_size;
  	eFree (utf8);

	iconv (iconv_fd, NULL, NULL, &utf8ptr, &utf8_len);

	return TRUE;
}

extern void closeConverter ()
{
	if (iconv_fd != (iconv_t) -1)
		iconv_close(iconv_fd);
	iconv_fd = (iconv_t) -1;
}

#endif	/* SUPPORT_MULTIBYTE */
