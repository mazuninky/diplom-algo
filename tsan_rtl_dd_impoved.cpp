#include "sanitizer_common/sanitizer_common.h"
#include "tsan_rtl_dd_impoved.h"

namespace __dd {

    void PerformBeforeLock() {
        __sanitizer::Printf("Lock\n");
    }

    void PerformAfterLock() {

    }

    void PerformUnlock() {

    }

    void PerformDestroy() {

    }
}