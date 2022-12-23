#ifndef CURRENTPATH_H
#define CURRENTPATH_H
#include <limits.h>
#include <string.h>
#include <unistd.h>

void currentPath(char *str, char *path) 
{
	//get path
	char cwd[PATH_MAX];
	char *cwd_ = cwd;
	getcwd(cwd, sizeof(cwd));
	
	
	//get user and host name
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);
	
	strcpy(str, username);
	strcat(str, "@");
	strcat(str, hostname);
	strsep(&cwd_, "//");
	strsep(&cwd_, "//");
	strsep(&cwd_, "//");
	
	
	strcpy(path, cwd_);
}

#endif
