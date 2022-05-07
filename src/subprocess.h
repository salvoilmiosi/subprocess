#ifndef __SUBPROCESS_H__
#define __SUBPROCESS_H__

#include "arguments.h"

#ifdef _WIN32

#include "proc_windows.h"
namespace subprocess {
using process = windows_process;
}

#else

#include "proc_linux.h"
namespace subprocess {
using process = linux_process;
}

#endif

#endif