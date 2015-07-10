#include <iostream>
#include "MutexLock.h"
#include "Thread.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
using namespace std;

int64_t getUTime();

//多线程下具有隐患
class Singleton
{
public:
    static Singleton *getInstance()
    {
        mutex_.lock();
        if(pInstance_ == NULL) //线程的切换
            pInstance_ = new Singleton;
        mutex_.unlock();
        return pInstance_;
    }
private:
    Singleton() { }

    static Singleton *pInstance_;
    static MutexLock mutex_;
};

Singleton *Singleton::pInstance_ = NULL;
MutexLock Singleton::mutex_;

class TestThread : public Thread
{
public:
    void run()
    {
        const int kCount = 1000 * 1000;
        for(int ix = 0; ix != kCount; ++ix)
        {
            Singleton::getInstance();
        }
    }
};

int main(int argc, char const *argv[])
{
    //Singleton s; ERROR

    int64_t startTime = getUTime();

    const int KSize = 100;
    TestThread threads[KSize];
    for(int ix = 0; ix != KSize; ++ix)
    {
        threads[ix].start();
    }

    for(int ix = 0; ix != KSize; ++ix)
    {
        threads[ix].join();
    }

    int64_t endTime = getUTime();

    int64_t diffTime = endTime - startTime;
    cout << "cost : " << diffTime / 1000 << " ms" << endl;

    return 0;
}



int64_t getUTime()
{
    struct timeval tv;
    ::memset(&tv, 0, sizeof tv);
    if(gettimeofday(&tv, NULL) == -1)
    {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }
    int64_t current = tv.tv_usec;
    current += tv.tv_sec * 1000 * 1000;
    return current;
}