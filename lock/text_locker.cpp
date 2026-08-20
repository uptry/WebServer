#include "lock/locker.h"
#include <cstdio>

int main(){
    locker mtx;
    sem s(2);

    mtx.lock();
    printf("locked\n");
    mtx.unlock();

    s.wait();
    s.wait();
    printf("拿到2个资源\n");

    printf("locker.h OK\n");
    return 0;
}