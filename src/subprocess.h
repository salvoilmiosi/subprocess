#ifndef __SUBPROCESS_H__
#define __SUBPROCESS_H__

#include "proc_windows.h"
#include "proc_linux.h"
#include "arguments.h"

#ifdef _WIN32
typedef windows_process subprocess;
#else
typedef linux_process subprocess;
#endif

#endif