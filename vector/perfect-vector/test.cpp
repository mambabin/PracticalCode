#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> coll(34); 
    coll.reserve(100);

    cout << "size = " << coll.size() << endl;
    cout << "capacity = " << coll.capacity() << endl;


    vector<int>(coll).swap(coll);


    cout << "size = " << coll.size() << endl;
    cout << "capacity = " << coll.capacity() << endl;


    return 0;
}


