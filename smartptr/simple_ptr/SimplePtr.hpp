#ifndef SIMPLE_PTR_
#define SIMPLE_PTR_

#include "stddef.h"

template <typename T>
class SimplePtr
{
public:
	SimplePtr(T *ptr = NULL);

	~SimplePtr()
	{
		delete ptr_;
	}

	T& operator*()
	{
		return *ptr_;
	}

	const T& operator*() const
	{
		return *ptr_;
	}

	T* operator->()
	{
		return ptr_;
	}

	const T* operator->() const
	{
		return ptr_;
	}

	void resetPtr(T *ptr = NULL);

	const T* getPtr() const
	{
		return ptr_;
	}

private:
	SimplePtr(const SimplePtr &);
	SimplePtr& operator=(const SimplePtr &);

	T *ptr_;
};

template <typename T>
SimplePtr<T>::SimplePtr(T *ptr)
:ptr_(ptr)
{
}

template <typename T>
void SimplePtr<T>::resetPtr(T *ptr)
{
	if(ptr_ != ptr)
	{
		delete ptr_;
		ptr_ = ptr;
	}
}

#endif  /* SIMPLE_PTR_ */