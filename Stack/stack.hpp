#include <iostream>
#include <cassert>
#include <stdlib.h>

#define START_SIZE 20

template<typename T>
struct Stack
{
	T* data;
	int max_size;
	int min_size;
	int cur_size;

	Stack()
	{
		data = (T*) calloc(START_SIZE, sizeof(T));
		max_size = START_SIZE;
		min_size = 0;
		cur_size = 0;
	}
	Stack(int size)
	{
		data = (T*) calloc(START_SIZE, sizeof(T));
		max_size = size;
		min_size = 0;
		cur_size = 0;
	}
	Stack(Stack const& stk)
	{
		data = (T*)calloc(stk.max_size, sizeof(T));
		max_size = stk.max_size;
		for (int i = 0; i < stk.cur_size; i++)
		{
			data[i] = stk.data[i];
			cur_size++;
		}
	}

	~Stack()
	{
		free(data);
		max_size = 0;
		min_size = 0;
		cur_size = 0;
	}

	void push(T n)
	{
		cur_size++;
		if(cur_size >= max_size)
		{
			min_size = (max_size*3)/4;
			max_size = max_size*2;

			data = (T*)realloc(data, sizeof(T) * max_size);
		}
		data[cur_size - 1] = n;
	}

	T pop()
	{
		cur_size--;
		if(cur_size < min_size)
		{
			if(cur_size < 7)
				cur_size = 0;
			max_size /= 2;
			min_size /= 2;

			data = (T*)realloc(data, sizeof(T) * max_size);
		}

		T n = data[cur_size];
		data[cur_size] = 0;

		return n;
	}

	void print()
	{
		std::cout<<"max size = " << max_size << "\n";
		std::cout<<"min size = " << min_size << "\n";
		std::cout<<"cur size = " << cur_size << "\n";
		for(int i = 0; i < cur_size; i++)
			std::cout<<"data["<<i<<"] = "<<data[i]<<"\n";
	}

	int size() const
	{
		return cur_size;
	}

	Stack & operator= (Stack const & stk)
	{
		data = (T*)calloc(stk.max_size, sizeof(T));
		max_size = stk.max_size;
		min_size = stk.min_size;
		for (int i = 0; i < stk.cur_size; i++)
		{
			data[i] = stk.data[i];
			cur_size++;
		}
		return *this;
	}

	bool operator== (Stack const & stk) const
	{
		if(min_size != stk.min_size)
			return false;
		if(max_size != stk.max_size)
			return false;
		if(cur_size != stk.cur_size)
			return false;
		for (int i = 0; i < cur_size; ++i)
		{
			if(data[i] != stk.data[i])
				return false;
		}
		return true;
	}

	bool is_stackOK()
	{
		if(cur_size > max_size)
			return false;
		if(cur_size < min_size)
			return false;
		if(data == nullptr)
			return false;
		return true;
	}
};