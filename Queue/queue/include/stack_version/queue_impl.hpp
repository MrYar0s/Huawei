#ifndef QUEUE_STACK_VERSION_INCLUDE_QUEUE_IMPL_HPP
#define QUEUE_STACK_VERSION_INCLUDE_QUEUE_IMPL_HPP

#include "queue.hpp"

namespace queue_stack
{
template <class T>
Queue<T> &Queue<T>::operator=(const Queue &other)
{
	if (this == &other)
	{
		return *this;
	}

	input_stack_ = other.input_stack_;
	output_stack_ = other.output_stack_;

	return *this;
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue &&other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	input_stack_ = std::move(other.input_stack_);
	output_stack_ = std::move(other.output_stack_);

	return *this;
}

template <class T>
bool Queue<T>::operator==(const Queue &other) const
{
	if (this == &other)
	{
		return true;
	}
	return (input_stack_ == other.input_stack_) &&
	       (output_stack_ == other.output_stack_);
}

template <class T>
bool Queue<T>::operator!=(const Queue &other) const
{
	if (this == &other)
	{
		return false;
	}
	return (input_stack_ != other.input_stack_) ||
	       (output_stack_ != other.output_stack_);
}

template <class T>
void Queue<T>::push(const T &val)
{
	input_stack_.push(val);
}

template <class T>
void Queue<T>::pop()
{
	if (output_stack_.is_empty())
	{
		refresh();
		if (output_stack_.is_empty())
		{
			std::cerr << "POP error" << std::endl;
			return;
		}
	}

	output_stack_.pop();
}

template <class T>
const T &Queue<T>::front() const
{
	if (output_stack_.is_empty())
	{
		refresh();
	}

	return output_stack_.top();
}

template <class T>
T &Queue<T>::front()
{
	if (output_stack_.is_empty())
	{
		refresh();
	}

	return output_stack_.top();
}

template <class T>
bool Queue<T>::is_empty() const
{
	return (output_stack_.is_empty()) && (input_stack_.is_empty());
}

template <class T>
size_t Queue<T>::size() const
{
	return output_stack_.size() + input_stack_.size();
}

template <class T>
void Queue<T>::refresh()
{
	T top_value = 0;
	while (!input_stack_.is_empty())
	{
		top_value = input_stack_.top();
		output_stack_.push(top_value);
		input_stack_.pop();
	}
}

}  // namespace queue_stack
#endif  // QUEUE_STACK_VERSION_INCLUDE_QUEUE_IMPL_HPP
