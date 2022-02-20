#ifndef TREE_INCLUDE_TREE_IMPL_HPP
#define TREE_INCLUDE_TREE_IMPL_HPP

#include <algorithm>
#include <utility>
#include "tree.hpp"

namespace tree
{

template <class T>
NodeT<T>::NodeT()
{
	value_ = 0;
	parent_ = nullptr;
	left_ = right_ = nullptr;
	color_ = RED;
}

template <class T>
NodeT<T>::NodeT(const T& value)
{
	value_ = value;
	parent_ = nullptr;
	left_ = right_ = nullptr;
	color_ = RED;
}

template <class T>
NodeT<T>::NodeT(const NodeT& other)
{
	value_ = other.value_;
	parent_ = other.parent_;
	left_ = other.left_;
	right_ = other.right_;
	color_ = other.color_;
}

template <class T>
NodeT<T>::NodeT(NodeT&& other) noexcept
{
	std::swap(value_, other.value_);
	std::swap(parent_, other.parent_);
	std::swap(left_, other.left_);
	std::swap(right_, other.right_);
	std::swap(color_, other.color_);
}

template <class T>
Tree<T>::Tree()
{
	root_ = new NodeT<T>;
	size_ = 0;
}

template <class T>
Tree<T>::Tree(const Tree& other)
{
	root_ = copy_tree(other.root_);
	size_ = other.size_;
}

template <class T>
Tree<T>::Tree(Tree&& other) noexcept
{
	std::swap(root_, other.root_);
	std::swap(size_, other.size_);
}

template <class T>
Tree<T>::~Tree()
{
	delete_tree(root_);
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree& other)
{
	if(this == &other)
	{
		return *this;
	}

	delete_tree(root_);
	size_ = 0;

	root_ = copy_tree(other.root_);
	size_ = other.size_;

	return *this;
}

template <class T>
Tree<T>& Tree<T>::operator=(Tree&& other) noexcept
{
	if(this == &other)
	{
		return *this;
	}

	delete_tree(root_);
	size_ = 0;

	root_ = other.root_;
	size_ = other.size_;

	other.root_ = nullptr;
	other.size_ = 0;

	return *this;
}

template <class T>
bool Tree<T>::operator==(const Tree& other) const
{
	if(this == &other)
	{
		return true;
	}

	if(size_ != other.size_)
	{
		return false;
	}

	return check_tree(root_, other.root_);
}

template <class T>
bool Tree<T>::operator!=(const Tree& other) const
{
	return !(*this == other);
}

template <class T>
NodeT<T>* Tree<T>::copy_tree(const NodeT<T>* other, NodeT<T>* parent)
{
	if(other == nullptr)
	{
		return nullptr;
	}

	auto node = new NodeT<T>;
	node->parent_ = parent;
	node->color_ = other->color_;
	node->value_ = other->value_;

	node->left_ = copy_tree(other->left_, node);
	node->right_ = copy_tree(other->right_, node);
	return node;
}

template <class T>
bool Tree<T>::check_tree(const NodeT<T>* root, const NodeT<T>* other_root) const
{
	if(root == nullptr || other_root == nullptr)
	{
		return (root == nullptr && other_root == nullptr);
	}
	if(root->value_ != other_root->value_)
	{
		return false;
	}
	if(root->color_ != other_root->color_)
	{
		return false;
	}
	check_tree(root->left_, other_root->left_);
	check_tree(root->right_, other_root->right_);
	return true;
}

template <class T>
bool Tree<T>::is_empty() const
{
	return size_ == 0;
}

template <class T>
size_t Tree<T>::size() const
{
	return size_;
}

template <class T>
NodeT<T>* Tree<T>::grandparent(const NodeT<T>* node)
{
	if(node != nullptr && node->parent_ != nullptr)
	{
		return node->parent_->parent_;
	}
	return nullptr;
}

template <class T>
NodeT<T>* Tree<T>::uncle(const NodeT<T>* node)
{
	NodeT<T>* grand = grandparent(node);
	if(grand == nullptr)
	{
		return nullptr;
	}
	if(node->parent_ == grand->left_)
	{
		return grand->right_;
	}
	return grand->left_;
}

template <class T>
NodeT<T>* Tree<T>::sibling(const NodeT<T>* node)
{
	if(node->parent_ == nullptr)
	{
		return nullptr;
	}
	if(node == node->parent_->left_)
	{
		return node->parent_->right_;
	}
	return node->parent_->left_;
}

template <class T>
void Tree<T>::delete_tree(const NodeT<T>* node)
{
	if(node == nullptr)
	{
		return;
	}
	delete_tree(node->left_);
	delete_tree(node->right_);
	delete node;
}

template <class T>
void Tree<T>::insert(const T& value)
{
	auto node = new NodeT<T>{value};
	insert(node);
}

template <class T>
void Tree<T>::insert(NodeT<T>* node)
{
	node->color_ = RED;
	if(is_empty())
	{
		root_ = node;
		node->parent_ = nullptr;
	}
	else
	{
		NodeT<T>* start = root_;
		NodeT<T>* parent;
		while(start != nullptr)
		{
			parent = start;
			if(start->value_ < node->value_)
			{
				start = start->right_;
			}
			else
			{
				start = start->left_;
			}
		}
		node->parent_ = parent;
		if(parent->value_ < node->value_)
		{
			parent->right_ = node;
		}
		else
		{
			parent->left_ = node;
		}
	}
	size_++;
	balance_insert(node);
}

template <class T>
void Tree<T>::balance_insert(NodeT<T>* node)
{
	if(node == root_)
	{
		node->color_ = BLACK;
		return;
	}
	while(node->parent_->color_ == RED)
	{
		NodeT<T>* grand = grandparent(node);
		if(node->parent_ == grand->left_)
		{
			NodeT<T>* unc = uncle(node);
			if(unc != nullptr && unc->color_ == RED)
			{
				node->parent_->color_ = BLACK;
				unc->color_ = BLACK;
				grand->color_ = RED;
				node = grand;
			}
			else
			{
				if(node == node->parent_->right_)
				{
					node = node->parent_;
					rotate_left(node);
				}
				node->parent_->color_ = BLACK;
				grand = grandparent(node);
				grand->color_ = RED;
				rotate_right(grand);
			}
		}
		else
		{
			NodeT<T>* unc = uncle(node);
			if(unc != nullptr && unc->color_ == RED)
			{
				node->parent_->color_ = BLACK;
				unc->color_ = BLACK;
				grand->color_ = RED;
				node = grand;
			}
			else
			{
				if(node == node->parent_->left_)
				{
					node = node->parent_;
					rotate_right(node);
				}
				node->parent_->color_ = BLACK;
				grand = grandparent(node);
				grand->color_ = RED;
				rotate_left(grand);
			}
		}
	}
	root_->color_ = BLACK;
}

template <class T>
void Tree<T>::rotate_right(NodeT<T>* const node)
{
	NodeT<T>* pivot = node->left_;

	pivot->parent_ = node->parent_;
	if(node->parent_ != nullptr)
	{
		if(node->parent_->left_ == node)
		{
			node->parent_->left_ = pivot;
		}
		else
		{
			node->parent_->right_ = pivot;
		}
	}

	node->left_ = pivot->right_;
	if(pivot->right_ != nullptr)
	{
		pivot->right_->parent_ = node;
	}

	node->parent_ = pivot;
	pivot->right_ = node;
}

template <class T>
void Tree<T>::rotate_left(NodeT<T>* const node)
{
	NodeT<T>* pivot = node->right_;

	pivot->parent_ = node->parent_;
	if(node->parent_ != nullptr)
	{
		if(node->parent_->left_ == node)
		{
			node->parent_->left_ = pivot;
		}
		else
		{
			node->parent_->right_ = pivot;
		}
	}

	node->right_ = pivot->left_;
	if(pivot->left_ != nullptr)
	{
		pivot->left_->parent_ = node;
	}

	node->parent_ = pivot;
	pivot->left_ = node;
}

template <class T>
const T& Tree<T>::get(const NodeT<T>* node) const
{
	return node->value_;
}

template <class T>
T& Tree<T>::get(const NodeT<T>* node)
{
	return node->value_;
}

template <class T>
const NodeT<T>* Tree<T>::find(const T& value) const
{
	NodeT<T>* node = root_;
	while(node != nullptr)
	{
		if(node->value_ < value)
		{
			node = node->right_;
		}
		if(node->value_ < value)
		{
			node = node->left_;
		}
		if(node->value_ == value)
		{
			return node;
		}
	}
	return node;
}

template <class T>
void Tree<T>::print(const NodeT<T>* node, const size_t& layer)
{
	if(node == nullptr && layer == 0)
	{
		node = root_;
	}

	if(node == nullptr)
	{
		return;
	}

	std::cout << "Root value = " << node->value_ << "\n";
	std::cout << "Root color = ";
	if(node->color_ == BLACK)
	{
		std::cout << "BLACK\n";
	}
	else
	{
		std::cout << "RED\n";
	}
	std::cout << "Left child = " << node->left_ << "\n";
	std::cout << "Right child = " << node->right_ << "\n";
	print(node->left_, layer + 1);
	print(node->right_, layer + 1);
}

} //namespace tree

#endif //TREE_INCLUDE_TREE_IMPL_HPP