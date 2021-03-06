
/*Error Checking, signal catching, types
* */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>      // printf, fflush, stderr, stdout
#include <stdlib.h>     // exit
#include <errno.h>      // errno, perror
#include <sys/wait.h>   // waitpid, WHOHANG
#include <signal.h>     // signal
#include <stdint.h>     // UINTPTR_MAX
#include <stdarg.h>     // va_args

#include "logger.h"     // Logger is a utility.

#if UINTPTR_MAX == 0xffffffff
    typedef long PTR_SIZE;      // 32 bit
#elif UINTPTR_MAX == 0xffffffffffffffff
    typedef long long PTR_SIZE; // 64 bit
#else
    typedef short PTR_SIZE;     // 16bit?
#endif


typedef unsigned char uchar;


// exit with a message along with errno message if
// it's set
void die(const char *msg,...);

// Handler to reap zombie processes
void sigchldHandler(int sig);

// Handler for alarms
void timeoutHandler(int sig);

#endif
