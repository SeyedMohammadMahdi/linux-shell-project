#ifndef CURRENTPATH_H
#define CURRENTPATH_H
#include <limits.h>
#include <string.h>

void currentPath(char *str) {
   char cwd[PATH_MAX];
   getcwd(cwd, sizeof(cwd));
   strcpy(str, cwd);
}

#endif
