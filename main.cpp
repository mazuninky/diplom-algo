#include "tsan_rtl_dd_impoved.h"

int thread_count = 1;
unsigned long mutex_count = 0;

int create_thread() {
    auto tid = thread_count++;
    __dd::PerformCreateThread(tid);
    return tid;
}

unsigned long create_mutex() {
    auto mutex_addr = mutex_count++;
    __dd::PerformCreateMutex(mutex_addr);
    return mutex_addr;
}

void mutex_lock(int tid, unsigned long mutex_addr) {
    __dd::PerformBeforeLock(tid, mutex_addr);
    __dd::PerformAfterLock(tid, mutex_addr);
}

void mutex_wait_lock(int tid, unsigned long mutex_addr) {
    __dd::PerformBeforeLock(tid, mutex_addr);
}

void mutex_unlock(int tid, unsigned long mutex_addr) {
    __dd::PerformUnlock(tid, mutex_addr);
}

/*
 * Deadlock
 * T1: m1, m2, m3
 * T2: m3, m1
 */
void example1_deadlock() {
    auto t1 = create_thread();
    auto t2 = create_thread();

    auto m1 = create_mutex();
    auto m2 = create_mutex();
    auto m3 = create_mutex();

    mutex_lock(t1, m1);
    mutex_lock(t1, m2);

    mutex_lock(t2, m3);
    mutex_wait_lock(t1, m3);

    mutex_wait_lock(t2, m1); // <== Deadlock
}

int main() {
    example1_deadlock();
    return 0;
}