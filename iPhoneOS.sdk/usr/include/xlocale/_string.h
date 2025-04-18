/*
 * Copyright (c) 2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _XLOCALE__STRING_H_
#define _XLOCALE__STRING_H_

#include <sys/cdefs.h>
#include <_bounds.h>
#include <sys/_types/_size_t.h>
#include <__xlocale.h>

_LIBC_SINGLE_BY_DEFAULT()

__BEGIN_DECLS
int	 strcoll_l(const char *, const char *, locale_t);
size_t	 strxfrm_l(char *_LIBC_COUNT(__n), const char *, size_t __n, locale_t);
int	 strcasecmp_l(const char *, const char *, locale_t);
char    *strcasestr_l(const char *, const char *, locale_t);
int	 strncasecmp_l(const char *_LIBC_UNSAFE_INDEXABLE,
        const char *_LIBC_UNSAFE_INDEXABLE, size_t, locale_t);
__END_DECLS

#endif /* _XLOCALE__STRING_H_ */
