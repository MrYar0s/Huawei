#include <iostream>
#include <cassert>
#include <cstdlib>

template<typename T>
struct Stack
{
	T* data;
	int max_size;
	int min_size;
	int cur_size;

	Stack();
	Stack(int size);
	Stack(Stack const& stk);
	~Stack();

	void push(T n);
	T pop();

	void info();
	int size() const;

	Stack & operator= (Stack const & stk);

	bool operator== (Stack const & stk) const;
	bool operator!= (Stack const & stk) const;

	bool is_stackOK();
};