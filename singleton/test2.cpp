#include <iostream>
#include "Thread.h"
#include <stdlib.h>
using namespace std;

//多线程下具有隐患
class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(pInstance_ == NULL) //线程的切换
        {
            ::sleep(1);
            pInstance_ = new Singleton;
        }
            
        return pInstance_;
    }
private:
    Singleton() { }

    static Singleton *pInstance_;
};

Singleton *Singleton::pInstance_ = NULL;


class TestThread : public Thread
{
public:
    void run()
    {
        cout << Singleton::getInstance() << endl;
        cout << Singleton::getInstance() << endl;
    }
};

int main(int argc, char const *argv[])
{
    //Singleton s; ERROR


    //测试证明了多线程下本代码存在竞争问题

    TestThread threads[12];
    for(int ix = 0; ix != 12; ++ix)
    {
        threads[ix].start();
    }

    for(int ix = 0; ix != 12; ++ix)
    {
        threads[ix].join();
    }
    return 0;
}