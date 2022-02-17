#ifndef QUEUE_LIST_VERSION_INCLUDE_QUEUE_HPP
#define QUEUE_LIST_VERSION_INCLUDE_QUEUE_HPP

#include <cstdlib>

namespace queue_list
{
template <class T>
class Queue
{
	public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other) noexcept;
	~Queue();

	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other) noexcept;

	bool operator==(const Queue& other) const;
	bool operator!=(const Queue& other) const;

	void push(const T& val);
	void pop();

	const T& back() const;
	T& back();

	const T& front() const;
	T& front();

	bool is_empty() const;
	size_t size() const;

	private:
	struct Node
	{
		T data_;
		Node* next_;
	};
	size_t size_{0};
	Node* front_;
	Node* back_;

	void delete_nodes();
};
}  // namespace queue_list

#endif  // QUEUE_LIST_VERSION_INCLUDE_QUEUE_HPP
