#ifndef _LINUX_H_
#define _LINUX_H_
#include <string.h>
#include <strings.h>
#include <glob.h>
#include <stdlib.h>
#include <stdio.h>

#define stricmp(str1, str2) strcasecmp(str1, str2)
#define _stricmp(str1, str2) strcasecmp(str1, str2)
#define strcpy_s(dest, destsz, src) strcpy(dest, src)
#define strcat_s(dest, destsz, src) strcat(dest, src)
#define sprintf_s(dest, size, format, ...) sprintf(dest, format, __VA_ARGS__)
#define rand_s(seed) rand_r(seed)
#define _stat stat
#define _getcwd( buf, size) getcwd(buf, size)
#define GetCurrentProcessId getpid

struct _lite_finddata_t {
    char name[20];
};

typedef struct _lite_finddata_t lite_finddata_t;

extern int findpos;

#define FINDDATA _lite_finddata_t
#define FINDHANDLE glob_t*
#define FIND_SUCCESS(x)	((x) != NULL)
#define FINDFIRST(mask, buf) _libc_findfirst(mask, buf)
#define FINDNEXT(handle, buf) _libc_findnext(handle, buf) == 0
#define FINDCLOSE(handle, buf) _libc_findclose(handle, buf)


glob_t* _libc_findfirst(char* filemask, struct _lite_finddata_t* buf);
int _libc_findnext(glob_t* globbuf, struct _lite_finddata_t* buf);
void _libc_findclose(glob_t* globbuf, struct _lite_finddata_t* buf);

#endif