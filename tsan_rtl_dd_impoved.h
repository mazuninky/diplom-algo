#ifndef DD_IMPROVED_H
#define DD_IMPROVED_H

namespace __dd {

    void PerformBeforeLock();

    void PerformAfterLock();

    void PerformUnlock();

    void PerformDestroy();
}  // namespace __dd

#endif  // DD_IMPROVED_H