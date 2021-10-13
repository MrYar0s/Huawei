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
Stack<T>::Stack(T* data, int size)
{
	if(size < 0)
		size = START_SIZE;
	size_ = size;
	data_ = new T [size_];
	cur_ = 0;
}

template <class T>
Stack<T>::Stack(const Stack &other)
{
	size_ = other.size_;
	data_ = new T [size_];
	cur_ = other.cur_;
	for (int i = 0; i < size_; i++)
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
	size_ = 0;
	cur_ = 0;
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
	
	for (int i = 0; i < size_; i++)
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
T Stack<T>::pop()
{
	cur_--;

	T n = data_[cur_];
	data_[cur_] = 0;

	return n;
}

template <class T>
void Stack<T>::info() const
{
	std::cout<<"maximum size = " << size_ << std::endl;
	std::cout<<"current size = " << cur_ << std::endl;
	for(int i = 0; i < cur_; i++)
		std::cout<<"data["<<i<<"] = "<<data_[i]<<std::endl;
}

template <class T>
int Stack<T>::size() const
{
	return size_;
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
	for (int i = 0; i < cur_; ++i)
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
bool Stack<T>::stackOK() const
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
void Stack<T>::expand()
{
	size_ *= MEMORY_MULT;
	T* other_data_ = new T [size_];
	for (int i = 0; i < cur_; ++i)
	{
		other_data_[i] = data_[i];
	}
	delete [] data_;
	data_ = other_data_;
}

}//namespace stack
