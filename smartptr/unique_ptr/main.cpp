#include "UniquePtr.hpp"
#include "iostream"
#include "vector"
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
	vector<UniquePtr<Test> > coll;
	coll.push_back(UniquePtr<Test>(new Test));
	
	return 0;
}