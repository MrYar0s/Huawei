#ifndef STACK_INCLUDE_STACK_IMPL_HPP
#define STACK_INCLUDE_STACK_IMPL_HPP
#include "../include/stack.hpp"
#include <climits>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>

namespace stack {

template <class T> Stack<T>::Stack() {
  size_ = START_SIZE;
  data_ = new T[size_];
  cur_ = 0;
}

template <class T> Stack<T>::Stack(size_t size) {
  data_ = new T[size];
  size_ = size;
  cur_ = 0;
}

template <class T> Stack<T>::Stack(const Stack &other) {
  size_ = other.size_;
  data_ = new T[size_];
  cur_ = other.cur_;
  for (size_t i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

template <class T> Stack<T>::Stack(Stack &&other) {
  data_ = other.data_;
  size_ = other.size_;
  cur_ = other.cur_;

  other.data_ = nullptr;
}

template <class T> Stack<T>::~Stack() { delete[] data_; }

template <class T> Stack<T> &Stack<T>::operator=(const Stack &other) {
  if (*this == other) {
    return *this;
  }
  size_ = other.size_;
  cur_ = other.cur_;

  delete[] data_;
  data_ = new T[size_];

  for (size_t i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }

  return *this;
}

template <class T> Stack<T> &Stack<T>::operator=(Stack &&other) {
  if (*this == other) {
    return *this;
  }
  size_ = other.size_;
  cur_ = other.cur_;

  delete[] data_;
  data_ = other.data_;
  other.data_ = nullptr;

  return *this;
}

template <class T> void Stack<T>::push(T n) {
  cur_++;
  if (cur_ > size_) {
    expand();
  }
  data_[cur_ - 1] = n;
}

template <class T> void Stack<T>::pop() { cur_--; }

template <class T> void Stack<T>::info() const {
  std::cout << "maximum size = " << size_ << std::endl;
  std::cout << "current size = " << cur_ << std::endl;
  for (size_t i = 0; i < cur_; i++) {
    std::cout << "data[" << i << "] = " << data_[i] << std::endl;
  }
}

template <class T> size_t Stack<T>::max_size() const { return size_; }

template <class T> size_t Stack<T>::size() const { return cur_; }

template <class T> T &Stack<T>::top() { return data_[cur_ - 1]; }

template <class T> const T &Stack<T>::top() const { return data_[cur_ - 1]; }

template <class T> bool Stack<T>::operator==(const Stack &other) const {
  if (cur_ != other.cur_) {
    return false;
  }
  for (size_t i = 0; i < cur_; ++i) {
    if (data_[i] != other.data_[i]) {
      return false;
    }
  }
  return true;
}

template <class T> bool Stack<T>::operator!=(const Stack &other) const {
  return !(*this == other);
}

template <class T> void Stack<T>::change_memory_mult(double mult) {
  MEMORY_MULT = mult;
}

template <class T> void Stack<T>::expand() {
  size_ = static_cast<size_t>(MEMORY_MULT * static_cast<long double>(size_));
  T *other_data_ = new T[size_];
  for (size_t i = 0; i < cur_; ++i) {
    other_data_[i] = data_[i];
  }
  delete[] data_;
  data_ = other_data_;
}

template <class T> void Stack<T>::swap(Stack &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(cur_, other.cur_);
  std::swap(MEMORY_MULT, other.MEMORY_MULT);
}

Stack<bool>::Stack() {
  size_ = START_SIZE;
  data_ = new unsigned char[size_t(START_SIZE / CHAR_BIT)];
  cur_ = 0;
}

Stack<bool>::Stack(size_t size) {
  size_ = size;
  data_ = new unsigned char[size_t(size_ / CHAR_BIT)];
  cur_ = 0;
}

Stack<bool>::Stack(const Stack &other) {
  size_ = other.size_;
  data_ = new unsigned char[size_ / CHAR_BIT];
  cur_ = other.cur_;
  for (size_t i = 0; i < size_ / CHAR_BIT; i++) {
    data_[i] = other.data_[i];
  }
}

Stack<bool>::Stack(Stack &&other) {
  data_ = other.data_;
  size_ = other.size_;
  cur_ = other.cur_;

  other.data_ = nullptr;
}

Stack<bool>::~Stack() { delete[] data_; }

Stack<bool> &Stack<bool>::operator=(const Stack &other) {
  if (*this == other) {
    return *this;
  }
  size_ = other.size_;
  cur_ = other.cur_;

  delete[] data_;
  data_ = new unsigned char[size_ / CHAR_BIT];

  for (size_t i = 0; i < size_ / CHAR_BIT; i++) {
    data_[i] = other.data_[i];
  }

  return *this;
}

Stack<bool> &Stack<bool>::operator=(Stack &&other) {
  if (*this == other) {
    return *this;
  }
  size_ = other.size_;
  cur_ = other.cur_;

  delete[] data_;
  data_ = other.data_;
  other.data_ = nullptr;

  return *this;
}

void Stack<bool>::push(bool n) {
  cur_++;
  if (cur_ > size_) {
    expand();
  }
  if (n) {
    data_[(cur_) / CHAR_BIT] |= (1 << (cur_ % CHAR_BIT));
  } else {
    data_[(cur_) / CHAR_BIT] &= ~(1 << (cur_ % CHAR_BIT));
  }
}

void Stack<bool>::pop() { cur_--; }

void Stack<bool>::info() const {
  std::cout << "maximum size = " << size_ << std::endl;
  std::cout << "current size = " << cur_ << std::endl;
  for (size_t i = 1; i <= cur_; i++) {
    std::cout << "data[" << i << "] = "
              << static_cast<bool>((1 << (i % CHAR_BIT)) & data_[i / CHAR_BIT])
              << std::endl;
  }
}

size_t Stack<bool>::max_size() const { return size_; }

size_t Stack<bool>::size() const { return cur_; }

bool Stack<bool>::top() const {
  return static_cast<bool>((1 << (cur_ % CHAR_BIT)) & data_[cur_ / CHAR_BIT]);
}

void Stack<bool>::swap(Stack &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(cur_, other.cur_);
  std::swap(MEMORY_MULT, other.MEMORY_MULT);
}

bool Stack<bool>::operator==(const Stack &other) const {
  if (cur_ != other.cur_) {
    return false;
  }
  for (size_t i = 1; i <= cur_; ++i) {
    if (((1 << (i % CHAR_BIT)) & data_[i / CHAR_BIT]) !=
        ((1 << (i % CHAR_BIT)) & other.data_[i / CHAR_BIT])) {
      return false;
    }
  }
  return true;
}

bool Stack<bool>::operator!=(const Stack &other) const {
  return !(*this == other);
}

void Stack<bool>::expand() {
  size_ = static_cast<size_t>(MEMORY_MULT * static_cast<long double>(size_));
  auto other_data_ = new unsigned char[size_ / CHAR_BIT];
  for (size_t i = 0; i < cur_; i++) {
    if (data_[i / CHAR_BIT] & (1 << (i % CHAR_BIT))) {
      other_data_[i / CHAR_BIT] |= (1 << (i % CHAR_BIT));
    } else {
      other_data_[i / CHAR_BIT] &= ~(1 << (i % CHAR_BIT));
    }
  }
  delete[] data_;
  data_ = other_data_;
}

} // namespace stack

#endif // STACK_INCLUDE_STACK_IMPL_HPP
