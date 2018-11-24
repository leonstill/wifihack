#ifndef RESERVE_TIME_H
#define RESERVE_TIME_H

#include <stdio.h>
#include <fcntl.h>
#include <utime.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct stat statbuf;

int save_time(const char *filename);
int restore_time(const char *filename);

#endif
