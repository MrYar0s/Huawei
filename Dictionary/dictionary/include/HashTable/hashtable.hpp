#ifndef DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_HPP
#define DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_HPP

#include "../List/list.hpp"
#include <vector>

template <class Key, class Val, class Hash = std::hash<Key>>
class HashTable
{
public:
	explicit HashTable(size_t size = START_SIZE);
	HashTable(const HashTable& other);
	HashTable(HashTable&& other) noexcept;
	virtual ~HashTable();

	HashTable& operator=(const HashTable& other);
	HashTable& operator=(HashTable&& other) noexcept;
	bool operator==(const HashTable& other) const;
	bool operator!=(const HashTable& other) const;

	bool is_empty() const;
	size_t size() const;

	bool insert(const Key& key, const Val& val);
	Val& operator[](const Key& key);

	const size_t START_SIZE = 1 << 13;

	struct Node;
protected:
	std::vector<Node*> valid_queue_;

private:
	size_t size_;
	size_t capacity_;
	Queue<Node>* data_;
};

template <class Key, class Val, class Hash>
struct HashTable<Key, Val, Hash>::Node final
{
	Node() = default;
	Node(const Key& key, const Val& val);
	Node(const Node& other);
	Node(Node&& other) noexcept;
	~Node() = default;

	Node& operator=(const Node& other);
	Node& operator=(Node&& other) noexcept;
	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;

	Key key_;
	Val val_;
};

#endif // DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_HPP