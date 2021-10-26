#ifndef STACK_INCLUDE_STACK_HPP
#define STACK_INCLUDE_STACK_HPP
#include <cstddef>

namespace stack {

template <class T> class Stack {
public:
  const size_t START_SIZE = 32;

  Stack();
  explicit Stack(size_t size);
  Stack(const Stack &other);
  Stack(Stack &&other);
  ~Stack();

  Stack &operator=(const Stack &other);
  Stack &operator=(Stack &&other);

  void push(T n);
  void pop();

  void info() const;
  size_t max_size() const;
  size_t size() const;
  T &top();
  const T &top() const;

  bool operator==(const Stack &other) const;
  bool operator!=(const Stack &other) const;

  void expand();

  void change_memory_mult(double mult);

private:
  double MEMORY_MULT = 2;
  T *data_;
  size_t size_;
  size_t cur_;
};

template <> class Stack<bool> {
public:
  const size_t START_SIZE = 8;

  Stack();
  explicit Stack(size_t size);
  Stack(const Stack &other);
  Stack(Stack &&other);
  ~Stack();

  Stack &operator=(const Stack &other);
  Stack &operator=(Stack &&other);

  void push(bool n);
  void pop();

  void info() const;
  size_t max_size() const;
  size_t size() const;
  bool top() const;

  bool operator==(const Stack &other) const;
  bool operator!=(const Stack &other) const;

  void expand();

private:
  double MEMORY_MULT = 2;
  unsigned char *data_;
  size_t size_;
  size_t cur_;
};
} // namespace stack
#endif // STACK_SORCE_STACK_HPP
