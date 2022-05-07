#ifndef __SUBPROCESS_H__
#define __SUBPROCESS_H__

#include "arguments.h"

#ifdef _WIN32

#include "proc_windows.h"
using subprocess = windows_process;

#else

#include "proc_linux.h"
using subprocess = linux_process;

#endif

#endif