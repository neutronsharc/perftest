/**
* Copyright 2021 by HoneycombData Inc.
* Created by Shawn on 2021/12/13.
*/

#include <stdio.h>
#include "log.h"

void DateTimeString(char* buf, int buflen) {
  struct tm nt;
  time_t ltime;
  ltime = time(&ltime);
  localtime_r(&ltime, &nt);
  struct timeval tv;
  gettimeofday(&tv, NULL);
  size_t len = strftime(buf, buflen, "%Y", &nt);
  snprintf(buf + len, buflen - len,
           "-%02d-%02d %02d:%02d:%02d.%06ld+%s",
           nt.tm_mon, nt.tm_mday, nt.tm_hour, nt.tm_min, nt.tm_sec, tv.tv_usec, nt.tm_zone);
}

void GetThreadName(void* buf, int size) {
  pthread_getname_np(pthread_self(), buf, size);
}

uint64_t NowInUsec() {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);
  return t.tv_sec * 1000000UL + t.tv_nsec / 1000;
}

