#ifndef QUEUE_LIST_VERSION_INCLUDE_QUEUE_IMPL_HPP
#define QUEUE_LIST_VERSION_INCLUDE_QUEUE_IMPL_HPP

#include <iostream>

#include "queue.hpp"

namespace queue_list
{
template <class T>
Queue<T>::Queue() : front_(), back_()
{
}

template <class T>
Queue<T>::Queue(const Queue& other) : size_(other.size_)
{
	if (!is_empty())
	{
		front_ = new Node{};

		Node* cur_node = front_;
		Node* cur_other_node = other.front_;

		cur_node->data_ = cur_other_node->data_;
		for (size_t i = 1; i < size_; i++)
		{
			cur_node->next_ = new Node{};

			cur_node = cur_node->next_;
			cur_other_node = cur_other_node->next_;

			cur_node->data_ = cur_other_node->data_;
		}
		back_ = cur_node;
	}
}

template <class T>
Queue<T>::Queue(Queue&& other) noexcept
    : size_(other.size_), front_(other.front_), back_(other.back_)
{
	other.size_ = 0;
	other.front_ = nullptr;
	other.back_ = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
	delete_nodes();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete_nodes();
	size_ = other.size_;

	if (!is_empty())
	{
		front_ = new Node{};

		Node* cur_node = front_;
		Node* cur_other_node = other.front_;

		cur_node->data_ = cur_other_node->data_;

		for (size_t i = 1; i < size_; i++)
		{
			cur_node->next_ = new Node{};

			cur_node = cur_node->next_;
			cur_other_node = cur_other_node->next_;

			cur_node->data_ = cur_other_node->data_;
		}
		back_ = cur_node;
	}
	else
	{
		back_ = nullptr;
		front_ = nullptr;
	}
	return *this;
}

template <class T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	delete_nodes();

	size_ = other.size_;
	front_ = other.front_;
	back_ = other.back_;

	other.size_ = 0;
	other.front_ = nullptr;
	other.back_ = nullptr;

	return *this;
}

template <class T>
bool Queue<T>::operator==(const Queue& other) const
{
	if (this == &other)
	{
		return true;
	}
	if (is_empty() && other.is_empty())
	{
		return true;
	}
	if (size() != other.size())
	{
		return false;
	}

	Node* cur_node = front_;
	Node* cur_other_node = other.front_;

	for (size_t i = 0; i < size_; i++)
	{
		if (cur_node->data_ != cur_other_node->data_)
		{
			return false;
		}
		cur_node = cur_node->next_;
		cur_other_node = cur_other_node->next_;
	}

	return true;
}

template <class T>
bool Queue<T>::operator!=(const Queue& other) const
{
	return !(*this == other);
}

template <class T>
bool Queue<T>::is_empty() const
{
	return size_ == 0;
}

template <class T>
size_t Queue<T>::size() const
{
	return size_;
}

template <class T>
const T& Queue<T>::back() const
{
	return back_->data_;
}

template <class T>
T& Queue<T>::back()
{
	return back_->data_;
}

template <class T>
const T& Queue<T>::front() const
{
	return front_->data_;
}

template <class T>
T& Queue<T>::front()
{
	return front_->data_;
}

template <class T>
void Queue<T>::push(const T& val)
{
	if (!is_empty())
	{
		back_->next_ = new Node{};
		back_ = back_->next_;
	}
	else
	{
		front_ = new Node{};
		back_ = front_;
	}
	back_->data_ = val;
	size_++;
}

template <class T>
void Queue<T>::pop()
{
	if (!is_empty())
	{
		if (size_ == 1)
		{
			delete front_;
			front_ = nullptr;
			back_ = nullptr;
		}
		else
		{
			Node* tmp = front_;
			front_ = front_->next_;
			delete tmp;
			tmp = nullptr;
		}
		size_--;
	}
	else
	{
		std::cerr << "POP error" << std::endl;
	}
}

template <class T>
void Queue<T>::delete_nodes()
{
	Node* cur_node = front_;
	Node* next_node = nullptr;

	for (size_t i = 0; i < size_; i++)
	{
		next_node = cur_node->next_;
		delete cur_node;
		cur_node = next_node;
	}
}

}  // namespace queue_list

#endif  // QUEUE_LIST_VERSION_INCLUDE_QUEUE_IMPL_HPP
