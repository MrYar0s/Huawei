#include "../include/stack.hpp"
#include "../include/stack-impl.hpp"
#include <iostream>

void void_init()
{
	stack::Stack<int> a;
	if(a.max_size() != stack::START_SIZE || a.size() != 0)
	{
		std::cerr<<"Test void_init failed"<<std::endl;
	}
}

void init()
{
	int size = 17;
	stack::Stack<int> a(size);
	if(a.max_size() != size || a.size() != 0)
	{
		std::cerr<<"Test init failed"<<std::endl;
	}
}

void init_other()
{
	int size = 17;
	stack::Stack<int> a(size);
	stack::Stack<int> b(a);
	if(b.max_size() != a.max_size() || b.size() != a.size())
	{
		std::cerr<<"Test init_other failed"<<std::endl;
	}
}

void is_equal_operator()
{
	int size = 17;
	stack::Stack<int> a(size);
	stack::Stack<int> b(size);
	for(int i = 0; i < size; i++)
	{
		a.push(i);
		b.push(i);
	}
	if(a != b)
	{
		std::cerr<<"Test is_equal_operator failed"<<std::endl;
	}
	b.pop();
	b.push(-1);
	if(a == b)
	{
		std::cerr<<"Test is_not_equal_operator failed"<<std::endl;
	}
}

void equal_operator()
{
	int size = 17;
	stack::Stack<int> a(size);
	a.push(5);
	stack::Stack<int> b;
	b = a;
	if(b != a)
	{
		std::cerr<<"Test equal_operator failed"<<std::endl;
	}
}

void push_pop()
{
	stack::Stack<int> a;
	int start = 16;
	for (int i = 0; i < 2*start; ++i)
	{
		a.push(i);
	}
	for (int i = 2*start - 1; i >= 0; --i)
	{
		if(i != a.top())
		{
			std::cerr<<"Test push_pop failed"<<std::endl;
			std::cerr<<"Pop error"<<std::endl;
			std::cerr<<"Error with data["<<i<<"] == "<< a.top()<<std::endl;
		}
		a.pop();
	}
}

void size_test()
{
	stack::Stack<int> a;
	if(a.max_size() != stack::START_SIZE)
	{
		std::cerr<<"Test size_test failed"<<std::endl;
	}
}

void top_test()
{
	int value1 = 144324;
	int value2 = 215523;
	int value3 = -21454;
	stack::Stack<int> a;
	a.push(value1);
	a.push(value2);
	a.push(value3);
	if(a.top() != value3)
	{
		std::cerr<<"Test top_test failed"<<std::endl;
	}
}

int main()
{
	void_init();
	init();
	init_other();
	is_equal_operator();
	equal_operator();
	push_pop();
	size_test();
	top_test();
	return 0;
}
