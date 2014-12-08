#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Vector.hpp"
using namespace std;

int64_t getUTime();

const int kSize = 1000 * 1000;
//int arr[kSize];

void test0() //
{   
    int arr[kSize];  //bad_alloc
    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        arr[i] = i;
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;

    cout << "test0 cost : " << diffTime << " us" << endl;
}

void test1() //
{   
    int *arr = new int[kSize];  //bad_alloc
    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        arr[i] = i;
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;
    delete[] arr;
    cout << "test1 cost : " << diffTime  << " us" << endl;
}

void test2()
{
    vector<int> coll;

    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        coll.push_back(i);
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;
    cout << "test2 cost : " << diffTime  << " us" << endl;
}

void test3()
{
    vector<int> coll(kSize);

    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        coll[i] = i;
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;
    cout << "test3 cost : " << diffTime  << " us" << endl;
}

void test4()
{
    Vector<int> coll;

    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        coll.push_back(i);
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;
    cout << "test4 cost : " << diffTime  << " us" << endl;
}

void test5()
{
    Vector<int> coll(kSize);

    int64_t startTime = getUTime();
    for(int i = 0; i != kSize; ++i)
    {
        coll[i] = i;
    }
    int64_t endTime = getUTime();
    int64_t diffTime = endTime - startTime;
    cout << "test5 cost : " << diffTime  << " us" << endl;
}


int main(int argc, char const *argv[])
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
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