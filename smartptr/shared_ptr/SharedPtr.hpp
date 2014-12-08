#ifndef SHARED_PTR_
#define SHARED_PTR_ 

#include "stddef.h"
using namespace std;

template <typename T>
class SharedPtr
{
public:
	typedef T element_type;
	typedef T* pointer;
	typedef T& reference;

	explicit SharedPtr(T *ptr = NULL);
	SharedPtr(const SharedPtr<T> &other);
	~SharedPtr();

	SharedPtr<T>& operator=(const SharedPtr<T> &other);

	reference operator*() const throw()
	{
		return *ptr_;
	}
	pointer operator->() const throw()
	{
		return ptr_;
	}

	size_t count() const
	{
		return *count_;
	}
	void swap(SharedPtr<T> &other) throw()
	{
		swap(ptr_, other.ptr_);
		swap(count_, other.count_);
	}

	void reset(T *ptr = NULL) throw()
	{
		dispose();
		ptr_ = ptr;
		count_ = new size_t(1);
	}

	pointer getPtr() const throw()
	{
		return ptr_;
	}

	bool unique() const throw()
	{
		return *count_ == 1;
	}

	operator bool()
	{
		return ptr_!= NULL;
	}


private:
	void dispose()
	{
		if(--*count_ == 0)
		{
			delete ptr_;
			delete count_;
		}
	}

	element_type *ptr_;
	size_t *count_;
};

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr)
:ptr_(ptr), count_(new size_t(1))
{
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other)
:ptr_(other.ptr_), count_(other.count_)
{
	++*count_;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
	dispose();
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
	++*other.count_;
	dispose();
	ptr_ = other.ptr_;
	count_ = other.count_;

	return *this;
}






#endif //SHARED_PTR_