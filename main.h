#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFSIZE 1024
#define TOK_BUFFER
#define TOK_DELIM "\t\r\n\a"

/*points to an array of pointers to strings called the environment*/
extern char **environ:

/**
 * struct data - struct that contain all relevant data on runtime
 * @av: argrument vector
 * @input: command
 */

#endif
