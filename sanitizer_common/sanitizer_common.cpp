#include "sanitizer_common.h"
#include <iostream>
#include <cstdarg>

namespace __sanitizer {
    void Printf(const char *format, ...) {
        va_list(args_list);
        va_start(args_list, format);
        vprintf(format, args_list);
        va_end(args_list);
    }
} // namespace __sanitizer
