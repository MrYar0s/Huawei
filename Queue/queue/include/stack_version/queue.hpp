#ifndef QUEUE_INCLUDE_STACK_VERSION_QUEUE_HPP
#define QUEUE_INCLUDE_STACK_VERSION_QUEUE_HPP

#include <cstdlib>

#include "stack-impl.hpp"

namespace queue_stack
{
template <class T>
class Queue
{
	public:
	Queue() = default;
	Queue(const Queue &other) = default;
	Queue(Queue &&other) noexcept = default;
	~Queue() = default;

	Queue &operator=(const Queue &other);
	Queue &operator=(Queue &&other) noexcept;

	bool operator==(const Queue &other) const;
	bool operator!=(const Queue &other) const;

	void push(const T &val);
	void pop();

	const T &front() const;
	T &front();

	bool is_empty() const;
	size_t size() const;

	private:
	stack::Stack<T> input_stack_{};
	stack::Stack<T> output_stack_{};

	void refresh();
};
}  // namespace queue_stack

#endif  // QUEUE_INCLUDE_STACK_VERSION_QUEUE_HPP
