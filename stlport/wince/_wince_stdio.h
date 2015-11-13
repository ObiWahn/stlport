#ifndef _STLP_INTERNAL_WINCE_STDIO_H
#define _STLP_INTERNAL_WINCE_STDIO_H

#if  _WIN32_WCE >= 0x500

#include <stl/config/user_config.h>
#include <stl/config/declspec.h>

#if defined(_STLP_USE_WINCE_CRT_FUNCTIONS)

#  if defined(__cplusplus)
extern "C" {
#  endif

/* File functions that we are adding for Windows CE */
_STLP_DECLSPEC int _STLP_CALL remove(char const * filename);
_STLP_DECLSPEC int _STLP_CALL rename(char const * oldname, char const * newname);

#  if defined(__cplusplus)
}
#  endif

#endif  /* _STLP_USE_WINCE_CRT_FUNCTIONS */

#endif  /* _WIN32_WCE >= 0x500 */

#endif  /* _STLP_INTERNAL_WINCE_STDIO_H */
