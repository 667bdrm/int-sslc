#include "linux.h"

glob_t* _libc_findfirst(char* filemask, struct _lite_finddata_t* buf) {
    glob_t *globbuf;
    globbuf = (glob_t*)malloc(sizeof(glob_t));
    findpos = 0;
    glob(filemask, GLOB_DOOFFS, NULL, globbuf);
    memcpy(buf->name, globbuf->gl_pathv[0], strlen(globbuf->gl_pathv[0]) + 1);
    findpos = 1;
    return globbuf;
}


int _libc_findnext(glob_t* globbuf, struct _lite_finddata_t* buf) {
    if (findpos < globbuf->gl_pathc) {
        memcpy(buf->name, globbuf->gl_pathv[findpos], strlen(globbuf->gl_pathv[findpos]) + 1);

        findpos++;
        return 0;
    }

    return -1;
}

void _libc_findclose(glob_t* globbuf, struct _lite_finddata_t* buf) {
    return;
}