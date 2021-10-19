#ifndef STACK_INCLUDE_STACK_IMPL_HPP
#define STACK_INCLUDE_STACK_IMPL_HPP
#include <iostream>

namespace stack
{

template <class T>
Stack<T>::Stack()
{
	size_ = START_SIZE;
	data_ = new T [size_];
	cur_ = 0;
}

template <class T>
Stack<T>::Stack(size_t size)
{
	data_ = new T [size];
	size_ = size;
	cur_ = 0;
}

template <class T>
Stack<T>::Stack(const Stack &other)
{
	size_ = other.size_;
	data_ = new T [size_];
	cur_ = other.cur_;
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = other.data_[i];
	}
}

template <class T>
Stack<T>::Stack(Stack &&other)
{
	data_ = other.data_;
	size_ = other.size_;
	cur_ = other.cur_;

	other.data_ = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
	delete [] data_;
}

template <class T>
Stack<T> & Stack<T>::operator=(const Stack &other)
{
	if(*this == other)
	{
		return *this;
	}
	size_ = other.size_;
	cur_ = other.cur_;

	delete [] data_;
	data_ = new T [size_];
	
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = other.data_[i];
	}
	
	return *this;
}

template <class T>
Stack<T> & Stack<T>::operator=(Stack &&other)
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
void Stack<T>::push(T n)
{
	cur_++;
	if(cur_ > size_)
	{
		expand();
	}
	data_[cur_ - 1] = n;
}

template <class T>
void Stack<T>::pop()
{
	cur_--;

	data_[cur_] = 0;
}

template <class T>
void Stack<T>::info() const
{
	std::cout<<"maximum size = " << size_ << std::endl;
	std::cout<<"current size = " << cur_ << std::endl;
	for(size_t i = 0; i < cur_; i++)
		std::cout<<"data["<<i<<"] = "<<data_[i]<<std::endl;
}

template <class T>
size_t Stack<T>::max_size() const
{
	return size_;
}

template <class T>
size_t Stack<T>::size() const
{
	return cur_;
}

template <class T>
T& Stack<T>::top()
{
	return data_[cur_ - 1];
}

template <class T>
const T& Stack<T>::top() const
{
	return data_[cur_ - 1];
}

template <class T>
bool Stack<T>::operator==(const Stack & other) const
{
	if(cur_ != other.cur_)
	{
		return false;
	}
	for (size_t i = 0; i < cur_; ++i)
	{
		if(data_[i] != other.data_[i])
			return false;
	}
	return true;
}

template <class T>
bool Stack<T>::operator!=(const Stack &other) const
{
	return !(*this == other);
}

template <class T>
void Stack<T>::expand()
{
	size_ = (size_t)(MEMORY_MULT*(long double)size_);
	T* other_data_ = new T [size_];
	for (size_t i = 0; i < cur_; ++i)
	{
		other_data_[i] = data_[i];
	}
	delete [] data_;
	data_ = other_data_;
}

}//namespace stack

#endif//STACK_INCLUDE_STACK_IMPL_HPP
