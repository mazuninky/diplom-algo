#include "sanitizer_common.h"
#include <iostream>

namespace __sanitizer {
    static void Printf(const char *string) {
        std::cout << string << std::endl;
    }
}
