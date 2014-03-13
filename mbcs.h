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

#include "vstring.h"

#ifdef SUPPORT_MULTIBYTE

extern boolean isConverting ();
extern boolean openConverter (char*);
extern boolean convertString (vString *const);
extern void closeConverter ();

#endif /* SUPPORT_MULTIBYTE */
