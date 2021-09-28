#include "../include/stack.hpp"
#include <cstdio>
#include <cassert>

void void_init_test()
{
	Stack<int> a;
	assert(a.data != nullptr);
	assert(a.max_size == START_SIZE);
	assert(a.cur_size == 0);
	assert(a.min_size == 0);
	for (int i = 0; i < START_SIZE; ++i)
	{
		assert(a.data[i] == 0);
	}
}

void init_test()
{
	Stack<int> a(30);
	assert(a.data != nullptr);
	assert(a.max_size == 30);
	assert(a.cur_size == 0);
	assert(a.min_size == 0);
	for(int i = 0; i < a.max_size; ++i)
	{
		assert(a.data[i] == 0);
	}
}

void copy_test()
{
	Stack<int> a(17);
	Stack<int> b(a);
	assert(b.data != nullptr);
	assert(b.max_size == a.max_size);
	assert(b.cur_size == a.cur_size);
	assert(b.min_size == a.min_size);
	for(int i = 0; i < b.max_size; ++i)
	{
		assert(b.data[i] == a.data[i]);
	}
}

void push_pop_test()
{
	const int max_counter = 100000000;
	Stack<int> a(1000);
	a.info();
	for(int i = 0; i < max_counter; ++i)
	{
		a.push(i);
		assert(a.data[i] == i);
	}
	for(int i = max_counter-1; i >= 0; i--)
	{
		int top = a.get_top();
		int poped = a.pop();
		assert(top == poped);
	}
	a.info();
}

void eq_test()
{
	const int max_counter = 100000000;
	Stack<int> a(100000);
	for (int i = 0; i < max_counter; ++i)
	{
		a.push(i);
		assert(a.data[i] == i);
	}
	Stack<int> b;
	b = a;
	assert(b.max_size == a.max_size);
	assert(b.min_size == a.min_size);
	assert(b.cur_size == a.cur_size);
	for(int i = 0; i < max_counter; ++i)
	{
		assert(a.data[i] == b.data[i]);
	}
}

int main()
{
	void_init_test();
	init_test();
	copy_test();
	push_pop_test();
	eq_test();
	return 0;
}