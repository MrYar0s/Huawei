#ifndef TREE_INCLUDE_TREE_HPP
#define TREE_INCLUDE_TREE_HPP

#include <cstdlib>

namespace tree
{

#define BLACK true
#define RED false

template <class T>
struct NodeT
{
    T value_;
    NodeT<T>* parent_;
    NodeT<T>* left_, *right_;
    bool color_;

    NodeT();
    explicit NodeT(const T& value);
    NodeT(const NodeT& other);
    NodeT(NodeT&& other) noexcept;
};

template <class T>
class Tree
{
public:
    Tree();
    Tree(const Tree& other);
    Tree(Tree&& other) noexcept;
    ~Tree();

    Tree& operator=(const Tree& other);
    Tree& operator=(Tree&& other) noexcept;

    bool operator==(const Tree& other) const;
    bool operator!=(const Tree& other) const;

    bool check_tree(const NodeT<T>* root, const NodeT<T>* other_root) const;

    bool is_empty() const;
    size_t size() const;

    void insert(NodeT<T>* node);
    void insert(const T& value);
    void balance_insert(NodeT<T>* node);

    const T& get(const NodeT<T>* node) const;
    T& get(const NodeT<T>* node);

    const NodeT<T>* find(const T& value) const;

    void rotate_left(NodeT<T>* node);
    void rotate_right(NodeT<T>* node);
    void print(const NodeT<T>* node = nullptr, const size_t& layer = 0);

private:
    NodeT<T>* root_;
    size_t size_;

    void delete_tree(const NodeT<T>* node);
    NodeT<T>* copy_tree(const NodeT<T>* other, NodeT<T>* parent = nullptr);
    NodeT<T>* grandparent(const NodeT<T>* node);
    NodeT<T>* uncle(const NodeT<T>* node);
    NodeT<T>* sibling(const NodeT<T>* node);
};

} //namespace tree

#endif //TREE_INCLUDE_TREE_HPP