#ifndef __PROC_WINDOWS_H__
#define __PROC_WINDOWS_H__

#include "pipe_io.h"
#include <windows.h>

namespace subprocess {

class windows_pipe {
public:
    void init(SECURITY_ATTRIBUTES &attrs, int which);

    ~windows_pipe() {
        close();
    }

    int read(size_t bytes, void *buffer);
    int write(size_t bytes, const void *buffer);
    void close(int which = -1);

private:
    HANDLE m_handles[2] = {0};

    friend class windows_process;
};

class windows_process {
public:
    windows_process();
    windows_process(const char *args[]);

    ~windows_process() {
        abort();
    }

public:
    void open(const char *args[]);
    void close();
    int wait_finished();
    void abort();
    explicit operator bool() const;

private:
    windows_pipe pipe_stdout, pipe_stderr, pipe_stdin;
    HANDLE process = nullptr;

public:
    pipe_istream<windows_pipe> stream_out, stream_err;
    pipe_ostream<windows_pipe> stream_in;
};

}

#endif