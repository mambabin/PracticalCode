#ifndef UNIQUE_PTR_
#define UNIQUE_PTR_

#include "algorithm"
#include "stddef.h"

template <typename T>
class UniquePtr
{
public:
	typedef T elementType;
	typedef T* pointer;
	typedef T& reference;

	explicit UniquePtr(T *ptr = NULL) throw()
	: ptr_(ptr)
	{
	}

	UniquePtr(UniquePtr &&u) throw()
	: ptr_(u.ptr_)
	{
		u.ptr_ = NULL;
	}

	UniquePtr& operator=(UniquePtr &&u) throw()
	{
		if(this != &u)
		{
			delete ptr_;
			ptr_ = u.ptr_;
			u.ptr_ = NULL;
		}
		return *this;
	}

	~UniquePtr() throw()
	{
		delete ptr_;
	}

	reference operator*() const throw()
	{
		return *ptr_;
	}

	pointer operator->() const throw()
	{
		return ptr_;
	}

	pointer getPtr() const throw()
	{
		return ptr_;
	}	

	pointer release() throw()
	{
		pointer temp(ptr_);
		ptr_ = NULL;
		return temp;
	}

	void resetPtr(T *ptr = NULL)
	{
		if(ptr_ != ptr)
		{
			delete ptr_;
			ptr_ = ptr;
		}
	}

	void swap(UniquePtr &other)
	{
		std::swap(ptr_, other.ptr_);
	}

private:
	UniquePtr(const UniquePtr &);
	void operator=(const UniquePtr &);

	T *ptr_;
};
#endif //UNIQUE_PTR_