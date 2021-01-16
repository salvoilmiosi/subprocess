#ifndef __ARGUMENTS_H__
#define __ARGUMENTS_H__

#include <concepts>
#include <cstddef>
#include <cassert>

template<typename T>
concept string_t = requires (T str) {
    { str.c_str() } -> std::convertible_to<const char*>;
};

template<size_t Maxsize>
class arguments {
private:
    const char *data[Maxsize + 1] = {0};
    size_t numargs = 0;

    void add_arg_impl(const char *arg) {
        assert(numargs < Maxsize);
        data[numargs++] = arg;
    }

public:
    template<typename ... Ts>
    arguments(const Ts & ... others) {
        add_args(others ...);
    }

public:
    void add_arg(const char *arg) {
        add_arg_impl(arg);
    }

    void add_arg(const string_t auto &arg) {
        add_arg_impl(arg.c_str());
    }

    void add_arg(string_t auto &&arg) = delete;

    template<typename T, typename ... Ts>
    void add_args(const T &first, Ts & ... others) {
        add_arg(first);

        if constexpr(sizeof...(others) != 0) {
            add_args(others ...);
        }
    }

    operator const char **() {
        return data;
    }
};

template<typename ... Ts> arguments(const Ts & ... args) -> arguments<sizeof ... (args)>;

#endif