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

#include "general.h"  /* must always come first */
#include "vstring.h"

#ifdef HAVE_ICONV

extern boolean isConverting ();
extern boolean openConverter (char*);
extern boolean convertString (vString *const);
extern void closeConverter ();

#endif /* HAVE_ICONV */
