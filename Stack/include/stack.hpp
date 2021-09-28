#define START_SIZE 20

#include <iostream>
#include <cstdlib>
int counter = 0;
template<typename T>
struct Stack
{
	T* data;
	int max_size;
	int min_size;
	int cur_size;

	Stack()
	{
		data = (T*) std::calloc(START_SIZE, sizeof(T));
		max_size = START_SIZE;
		min_size = 0;
		cur_size = 0;
	}

	Stack(int size)
	{
		if(size < 1)
			size = START_SIZE;
		data = (T*) std::calloc(size, sizeof(T));
		max_size = size;
		min_size = 0;
		cur_size = 0;
	}

	Stack(Stack<T> const& stk)
	{
		data = (T*) std::calloc(stk.max_size, sizeof(T));
		max_size = stk.max_size;
		for (int i = 0; i < stk.cur_size; i++)
		{
			data[i] = stk.data[i];
			cur_size++;
		}
	}

	~Stack()
	{
		std::free(data);
		max_size = 0;
		min_size = 0;
		cur_size = 0;
	}

	void push(T n)
	{
		cur_size++;
		if(cur_size > max_size)
		{
			min_size = (max_size*3)/4;
			max_size *= 2;
			data = (T*) std::realloc(data, sizeof(T) * max_size);
		}
		data[cur_size - 1] = n;
		counter++;
	}

	T pop()
	{
		cur_size--;
		if(cur_size < min_size)
		{
			if(cur_size < 7)
				min_size = 0;
			max_size /= 2;
			min_size /= 2;

			data = (T*) std::realloc(data, sizeof(T) * max_size);
		}

		T n = data[cur_size];
		data[cur_size] = 0;

		return n;
	}

	void info()
	{
		std::cout<<"max size = " << max_size << std::endl;
		std::cout<<"min size = " << min_size << std::endl;
		std::cout<<"cur size = " << cur_size << std::endl;
		for(int i = 0; i < cur_size; i++)
			std::cout<<"data["<<i<<"] = "<<data[i]<<std::endl;
	}

	int size() const
	{
		return cur_size;
	}

	int get_top() const
	{
		return data[cur_size-1];
	}

	Stack & operator=(Stack<T> const & stk)
	{
		data = (T*) std::realloc(data, stk.max_size * sizeof(T));
		max_size = stk.max_size;
		min_size = stk.min_size;
		for (int i = 0; i < stk.cur_size; i++)
		{
			data[i] = stk.data[i];
			cur_size++;
		}
		return *this;
	}

	bool operator==(Stack<T> const & stk) const
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

	bool operator!=(Stack<T> const & stk) const
	{
		if(min_size != stk.max_size)
			return true;
		if(max_size != stk.max_size)
			return true;
		if(cur_size != stk.cur_size)
			return true;
		for(int i = 0; i < cur_size; ++i)
		{
			if(data[i] != stk.data[i])
				return true;
		}
		return false;
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