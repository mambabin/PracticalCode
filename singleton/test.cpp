#include <iostream>
using namespace std;

//可以生成对象，而且外部无法直接生成
//但是对象不唯一
class Singleton
{
public:
    static Singleton *getInstance()
    {
        return new Singleton;
    }
private:
    Singleton() { }
};

int main(int argc, char const *argv[])
{
    //Singleton s; ERROR
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}