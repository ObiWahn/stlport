#ifndef _STLP_INTERNAL_WINCE_ERRNO_H
#define _STLP_INTERNAL_WINCE_ERRNO_H

#include <stl/config/user_config.h>

#if defined(_STLP_USE_WINCE_CRT_FUNCTIONS)

/* Define Error Codes that should be in errno.h */
#define EPERM           1
#define ENOENT          2
#define ESRCH           3
#define EINTR           4
#define EIO             5
#define ENXIO           6
#define E2BIG           7
#define ENOEXEC         8
#define EBADF           9
#define ECHILD          10
#define EAGAIN          11
#define ENOMEM          12
#define EACCES          13
#define EFAULT          14
#define EBUSY           16
#define EEXIST          17
#define EXDEV           18
#define ENODEV          19
#define ENOTDIR         20
#define EISDIR          21
#define ENFILE          23
#define EMFILE          24
#define ENOTTY          25
#define EFBIG           27
#define ENOSPC          28
#define ESPIPE          29
#define EROFS           30
#define EMLINK          31
#define EPIPE           32
#define EDOM            33
#define EDEADLK         36
#define ENAMETOOLONG    38
#define ENOLCK          39
#define ENOSYS          40
#define ENOTEMPTY       41

#endif  /* _STLP_USE_WINCE_CRT_FUNCTIONS */

#endif  /* _STLP_INTERNAL_WINCE_ERRNO_H */

/* Local Variables:
 * mode:C++
 * End:
 */
