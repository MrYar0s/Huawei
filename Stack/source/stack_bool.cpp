#include <climits>
#include <iostream>
#include <cstring>
#include "../include/stack.hpp"

namespace stack
{

Stack<bool>::Stack()
{
	size_ = START_SIZE;
	data_ = new unsigned char [size_t(START_SIZE/CHAR_BIT)];
	cur_ = 0;
}

Stack<bool>::Stack(size_t size)
{
	size_ = size;
	data_ = new unsigned char [size_t(size_/CHAR_BIT)];
	cur_ = 0;
}

Stack<bool>::Stack(const Stack &other)
{
	size_ = other.size_;
	data_ = new unsigned char [size_/CHAR_BIT];
	cur_ = other.cur_;
	for (size_t i = 0; i < size_/CHAR_BIT; i++)
	{
		data_[i] = other.data_[i];
	}
}

Stack<bool>::Stack(Stack &&other)
{
	data_ = other.data_;
	size_ = other.size_;
	cur_ = other.cur_;

	other.data_ = nullptr;
}

Stack<bool>::~Stack()
{
	delete [] data_;
}

Stack<bool> & Stack<bool>::operator=(const Stack &other)
{
	if(*this == other)
	{
		return *this;
	}
	size_ = other.size_;
	cur_ = other.cur_;

	delete [] data_;
	data_ = new unsigned char [size_/CHAR_BIT];

	for (size_t i = 0; i < size_/CHAR_BIT; i++)
	{
		data_[i] = other.data_[i];
	}

	return *this;
}

Stack<bool> & Stack<bool>::operator=(Stack &&other)
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

void Stack<bool>::push(bool n)
{
	cur_++;
	if(cur_ > size_)
	{
		expand();
	}
	if(n)
	{
		data_[(cur_)/CHAR_BIT] |= (1 << (cur_%CHAR_BIT));
	}
	else
	{
		data_[(cur_)/CHAR_BIT] &= ~(1 << (cur_%CHAR_BIT));
	}	
}

void Stack<bool>::pop()
{
	cur_--;

	data_[(cur_+1)/CHAR_BIT] &= ~(1 << ((cur_+1)%CHAR_BIT));
}

void Stack<bool>::info() const
{
	std::cout<<"maximum size = " << size_ << std::endl;
	std::cout<<"current size = " << cur_ << std::endl;
	for (size_t i = 1; i <= cur_; i++)
		std::cout << "data[" << i << "] = " << (bool)((1<<(i%CHAR_BIT)) & data_[i/CHAR_BIT]) << std::endl;
}

size_t Stack<bool>::max_size() const
{
	return size_;
}

size_t Stack<bool>::size() const
{
	return cur_;
}

bool Stack<bool>::top() const
{
	return (bool)((1<<(cur_%CHAR_BIT)) & data_[cur_/CHAR_BIT]);
}

bool Stack<bool>::operator==(const Stack & other) const
{
	if(cur_ != other.cur_)
	{
		return false;
	}
	for (size_t i = 1; i <= cur_; ++i)
	{
		if(((1<<(i%CHAR_BIT)) & data_[i/CHAR_BIT]) != ((1<<(i%CHAR_BIT)) & other.data_[i/CHAR_BIT]))
			return false;
	}
	return true;
}

bool Stack<bool>::operator!=(const Stack &other) const
{
	return !(*this == other);
}

void Stack<bool>::expand()
{
	size_ = (size_t)(MEMORY_MULT* (long double)size_);
	unsigned char* other_data_ = new unsigned char [size_/CHAR_BIT];
	for(size_t i = 0; i < cur_; i++)
	{
		if(data_[i/CHAR_BIT] & (1<<(i%CHAR_BIT)))
       		{
                	other_data_[i/CHAR_BIT] |= (1 << (i%CHAR_BIT));
        	}
        	else
        	{
                	other_data_[i/CHAR_BIT] &= ~(1 << (i%CHAR_BIT));
        	}
	}
	delete [] data_;
	data_ = other_data_;
}

}//namespace stack
