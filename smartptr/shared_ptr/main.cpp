#include "SharedPtr.hpp"
#include "iostream"
#include "assert.h"
using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Test..." << endl;
	}
	~Test()
	{
		cout << "~Test..." << endl;
	}
private:
	Test(const Test &);
	void operator=(const Test &);
};

int main(int argc, char const *argv[])
{
	SharedPtr<Test> ptr(new Test);
	cout << ptr.count() << endl;
	assert(ptr.count() == 1);

	SharedPtr<Test> ptr2(ptr);
	cout << ptr.count() << endl;

	SharedPtr<Test> ptr3;
	ptr3 = ptr;
	cout << ptr.count() << endl;

	if(ptr)
	{
		cout << "ptr is not NULL" << endl;
	}

	assert(!ptr.unique());
	return 0;
}