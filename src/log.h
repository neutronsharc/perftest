/**
* Copyright 2021 by HoneycombData Inc.
* Created by Shawn on 2021/12/11.
*/

#ifndef PERFTEST_LOG_H
#define PERFTEST_LOG_H

#include <inttypes.h>
#include <pthread.h>
#include <syscall.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


void GetThreadName(void* buf, int size);

uint64_t NowInUsec();

void DateTimeString(char* buf, int buflen);

#define LOG(fmt, ...)                                                 \
  do {                                                                \
    char timebuf[200];                                                \
    char tname[60];                                                   \
    pid_t tid = syscall(SYS_gettid);                                  \
    GetThreadName(tname, 60);                                         \
    DateTimeString(timebuf, 200);                                     \
    fprintf(stderr, "[%s][%s %d] " fmt " [%s:%s(%d)]\n", timebuf,     \
            tname, tid, ##__VA_ARGS__, __FILE__, __func__, __LINE__); \
    fflush(stderr);                                                   \
  } while (0)


#endif  // PERFTEST_LOG_H

