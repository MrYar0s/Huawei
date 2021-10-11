#include "../include/stack.hpp"
#include <iostream>

namespace stack
{

template <class T>
Stack::Stack()
{
	size_ = START_SIZE;
	data_ = new T [size_];
	cur_ = 0;
}

template <class T>
Stack::Stack(T* data, int size)
{
	if(size < 0)
		size = START_SIZE;
	size_ = size;
	data_ = new T [size_];
	cur_ = 0;
}

template <class T>
Stack::Stack(const Stack &other)
{
	size_ = other.size_;
	data_ = new T [size_];
	cur_ = other.cur_;
	for (int i = 0; i < cur_; i++)
	{
		data_[i] = other.data_[i];
	}
}

template <class T>
Stack::Stack(Stack &&other)
{
	data_ = other.data_;
	size_ = other.size_;
	cur_ = other.cur_;

	other.data_ = nullptr;
}

template <class T>
Stack::~Stack()
{
	delete [] data_;
	size_ = 0;
	cur_ = 0;
}

template <class T>
Stack & Stack::operator=(const Stack &other)
{
	if(*this == other)
	{
		return *this;
	}
	size_ = other.size_;
	cur_ = other.cur_;

	delete [] data_;
	data_ = new T [size_];
	
	for (int i = 0; i < cur_; i++)
	{
		data_[i] = other.data_[i];
	}
	
	return *this;
}

template <class T>
Stack & Stack::operator=(Stack &&other)
{
	if(*this == other)
	{
		return *this;
	}
	size_ = other.size_;
	cur_ = other.cur_;

	delete [] data_;
	data_ = other.data_;
	other.data_ = nullptr;

	return *this;
}

template <class T>
void Stack::push(T n)
{
	cur_++;
	if(cur_ > size_)
	{
		expand();
	}
	data[cur_ - 1] = n;
}

template <class T>
int Stack::pop()
{
	cur_--;

	T n = data_[cur_];
	data_[cur_] = 0;

	return n;
}

template <class T>
void Stack::info() const
{
	std::cout<<"maximum size = " << size_ << std::endl;
	std::cout<<"current size = " << cur_ << std::endl;
	for(int i = 0; i < cur_; i++)
		std::cout<<"data["<<i<<"] = "<<data_[i]<<std::endl;
}

template <class T>
int Stack::size() const
{
	return cur_;
}

template <class T>
T& Stack::top() const
{
	return data[cur_ - 1];
}

template <class T>
const T& Stack::top() const
{
	return data[cur_ - 1];
}

template <class T>
bool Stack::operator==(const Stack & other) const
{
	if(size_ > other.cur_ || other.size_ > cur_)
	{
		return false;
	}
	if(cur_ != other.cur_)
	{
		return false;
	}
	for (int i = 0; i < cur_; ++i)
	{
		if(data_[i] != other.data_[i])
			return false;
	}
	return true;
}

template <class T>
bool Stack::operator!=(const Stack &other) const
{
	if(!(*this == other))
	{
		return true;
	}
	return false;
}

template <class T>
bool Stack::stackOK() const
{
	if(this == nullptr)
	{
		return false;
	}
	if(cur_ > size_)
	{
		return false;
	}
	if(data_ == nullptr)
	{
		return false;
	}
	if(cur_ < 0)
	{
		return false;
	}
	return true;
}

template <class T>
void expand()
{
	cur_ *= MEMORY_MULT;
	other_data_ = new T [cur_];
	for (int i = 0; i < size_; ++i)
	{
		other_data_[i] = data_[i];
	}
	delete [] data_;
	data_ = other_data_;
}

}//namespace stack