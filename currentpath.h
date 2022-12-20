#ifndef CURRENTPATH_H
#define CURRENTPATH_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void currentPath(char *str) {
   char cwd[PATH_MAX];
   getcwd(cwd, sizeof(cwd));
   strcpy(str, cwd);
}

#endif
