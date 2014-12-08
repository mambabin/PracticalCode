#include "SimplePtr.hpp"
#include "iostream"
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

};

int main(int argc, char const *argv[])
{
	SimplePtr<Test> ptr(new Test);
	
	return 0;
}