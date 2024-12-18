#include <stdio.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif

#include <time.h>
#include <errno.h>
#include <iostream>
#include <stdbool.h>
#include <sys/time.h>
#include "ModBusRTUController.hpp"

#define FMT_HEADER_ONLY
#include "fmt/core.h"
#include "fmt/format.h"
#include "fmt/printf.h"


#define CALC_FPS(tips)                                                                                     \
{                                                                                                          \
	static int fcnt = 0;                                                                                   \
	fcnt++;                                                                                                \
	static struct timespec ts1, ts2;                                                                       \
	clock_gettime(CLOCK_MONOTONIC, &ts2);                                                                  \
	if ((ts2.tv_sec * 1000 + ts2.tv_nsec / 1000000) - (ts1.tv_sec * 1000 + ts1.tv_nsec / 1000000) >= 1000) \
	{                                                                                                      \
		fmt::printf("%s => H26X FPS:%d     \r\n", tips, fcnt);                                             \
		ts1 = ts2;                                                                                         \
		fcnt = 0;                                                                                          \
	}                                                                                                      \
}



/* 全局变量 */
typedef struct
{

} __global_variable__;


/*全局函数*/
uint32_t getPlatformTicks();

