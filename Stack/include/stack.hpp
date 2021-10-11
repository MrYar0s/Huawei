#ifndef STACK_SORCE_STACK_HPP
#define STACK_SORCE_STACK_HPP

namespace stack
{

const int START_SIZE = 16;
const int MEMORY_MULT = 2;

template <class T>
class Stack
{
public:
	Stack();
	Stack(T* data, int size);
	Stack(const Stack &other);
	Stack(Stack &&other);
	~Stack();

	Stack & operator=(const Stack &other);
	Stack & operator=(Stack &&other);

	void push(T n);
	T pop();

	void info() const;
	int size() const;
	T& top() const;
	const T& top() const;

	bool operator==(const Stack &other) const;
	bool operator!=(const Stack &other) const;

	bool stackOK() const;

	void expand();

private:
	T* data_;
	int size_;
	int cur_;
};

}//namespace stack

#endif //STACK_SORCE_STACK_HPP