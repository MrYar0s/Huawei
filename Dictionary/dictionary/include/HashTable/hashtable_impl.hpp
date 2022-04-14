#ifndef DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_IMPL_HPP
#define DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_IMPL_HPP

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::HashTable(size_t size) : size_(size)
{
	data_ = new List<Node> [size_];
}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::HashTable(const HashTable& other) : size_(other.size_)
{
	data_ = new List<Node> [size_];

	for(size_t i = 0; i < size_; i++)
	{
		data_ = List<Node>(other.data_[i]);
	}
}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::HashTable(HashTable&& other) : size_(other.size_), data_(other.data_)
{
	other.data_ = nullptr;
}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::~HashTable()
{
	delete [] data_;
}

template <class Key, class Val, class Hash>
HashTable& HashTable<Key, Val, Hash>::operator=(const HashTable& other) : size_(other.size_)
{
	if(this == &other)
	{
		return *this;
	}

	delete [] data_;
	size_ = other.size_;
	data_ = new List<Node> [size_];
	for(size_t i = 0; i < size_; i++)
	{
		data_[i] = List<Node>(other.data_[i]);
	}
	return *this;
}

template <class Key, class Val, class Hash>
HashTable& HashTable<Key, Val, Hash>::operator=(HashTable&& other)
{
	if(this == &other)
	{
		return *this;
	}

	delete [] data_;
	size_ = other.size_;
	data_ = other.data_;
	other.data_ = nullptr;

	return *this;
}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::operator==(const HashTable& other) const
{
	if(this == &other)
	{
		return true;
	}
	if(size_ != other.size_)
	{
		return false;
	}
	for(size_t i = 0; i < size_; i++)
	{
		if(data_[i] != other.data_[i])
		{
			return false;
		}
	}
	return true;
}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::operator!=(const HashTable& other) const
{
	return !(*this == other);
}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::is_empty() const
{
	return size_ == 0;
}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::insert(const Key& key, const Val& val)
{
	size_t index = Hash()(key) % size_;

	list = data_[index];
	auto cur = list.front_();
	while(cur != nullptr)
	{
		if(cur.data_.key_ == key)
		{
			cur.data_.val_ = val;
			return false;
		}
		cur = cur.next_;
	}
	capacity_++;
	valid_queue_.push(nullptr);
	data_[index].push(Node(key, val));
	valid_queue_.back() = &data_[index].back();

	return true;
}

template <class Key, class Val, class Hash>
Val& HashTable<Key, Val, Hash>::operator[](const Key& key)
{
	size_t index = Hash()(key) % size_;

	list = data_[index];
	auto cur = list.front_();
	while(cur != nullptr)
	{
		if(cur->data_.key_ == key)
		{
			return cur->data_.val_;
		}
		cur = cur->next_;
	}
	valid_queue_.push(nullptr);
	data_[index].push(Node(key, Val()));
	valid_queue_.back() = &data_[index].back();

	return data_[index].back().val_;
}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::Node::Node(const Key& key, const Val& val) : key_(key), val_(val)
{}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::Node::Node(const Node& other) : key_(other.key_), val_(other.val_)
{}

template <class Key, class Val, class Hash>
HashTable<Key, Val, Hash>::Node::Node(Node&& other) : key_(other.key_), val_(other.val_)
{}

template <class Key, class Val, class Hash>
Node& HashTable<Key, Val, Hash>::Node::operator=(const Node& other) : key_(other.key_), val_(other.val_)
{}

template <class Key, class Val, class Hash>
Node& HashTable<Key, Val, Hash>::Node::operator=(Node&& other) : key_(other.key_), val_(other.val_)
{}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::Node::operator==(const Node& other) const
{
	return (key_ == other.key_) && (val_ == other.val_);
}

template <class Key, class Val, class Hash>
bool HashTable<Key, Val, Hash>::Node::operator!=(const Node& other) const
{
	return !(*this == other);
}
#endif // DICTIONARY_INCLUDE_HASHTABLE_HASHTABLE_IMPL_HPP