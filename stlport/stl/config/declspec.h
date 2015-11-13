 /*
  *
  * Copyright (c) 1994
  * Hewlett-Packard Company
  *
  * Copyright (c) 1996,1997
  * Silicon Graphics Computer Systems, Inc.
  *
  * Copyright (c) 1997
  * Moscow Center for SPARC Technology
  *
  * Copyright (c) 1999
  * Boris Fomitchev
  *
  * This material is provided "as is", with absolutely no warranty expressed
  * or implied. Any use is at your own risk.
  *
  * Permission to use or copy this software for any purpose is hereby granted
  * without fee, provided the above notices are retained on all copies.
  * Permission to modify the code and to distribute modified code is granted,
  * provided the above notices are retained, and a notice that the code was
  * modified is included with the above copyright notice.
  *
  */

#ifndef _STLP_DECLSPEC_H
#define _STLP_DECLSPEC_H

#if defined (__BUILDING_STLPORT)
/*  if we are rebuilding right now, place everything here */
#  undef  _STLP_DESIGNATED_DLL
#  define _STLP_DESIGNATED_DLL 1
#endif

/* shared library tune-up */
#ifndef _STLP_IMPORT_DECLSPEC
#  define _STLP_IMPORT_DECLSPEC
#endif

#ifdef _STLP_USE_NO_IOSTREAMS
/*
 * If we do not use iostreams we do not use the export/import
 * techniques to avoid build of the STLport library.
 */
#  undef _STLP_USE_DECLSPEC
/* We also undef USE_DYNAMIC_LIB macro as this macro add some code
 * to use the dynamic (shared) STLport library for some platform/compiler
 * configuration leading to problem when not linking to the STLport lib.
 */
#  undef _STLP_USE_DYNAMIC_LIB
#endif

#if defined (_STLP_USE_DECLSPEC) /* using export/import technique */

#  ifndef _STLP_EXPORT_DECLSPEC
#    define _STLP_EXPORT_DECLSPEC
#  endif
#  ifndef _STLP_IMPORT_DECLSPEC
#    define _STLP_IMPORT_DECLSPEC
#  endif
#  ifndef _STLP_CLASS_EXPORT_DECLSPEC
#    define _STLP_CLASS_EXPORT_DECLSPEC
#  endif
#  ifndef _STLP_CLASS_IMPORT_DECLSPEC
#    define _STLP_CLASS_IMPORT_DECLSPEC
#  endif
#  if defined (_STLP_DESIGNATED_DLL) /* This is a lib which will contain STLport exports */
#    define  _STLP_DECLSPEC        _STLP_EXPORT_DECLSPEC
#    define  _STLP_CLASS_DECLSPEC  _STLP_CLASS_EXPORT_DECLSPEC
#  else
#    define  _STLP_DECLSPEC        _STLP_IMPORT_DECLSPEC   /* Other modules, importing STLport exports */
#    define  _STLP_CLASS_DECLSPEC  _STLP_CLASS_IMPORT_DECLSPEC
#  endif

#else /* Not using DLL export/import specifications */

#  define _STLP_DECLSPEC
#  define _STLP_CLASS_DECLSPEC

#endif

#endif /* _STLP_DECLSPEC_H */
