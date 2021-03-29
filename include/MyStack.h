// Copyright [2021] <Nikita Semaev>
#include <algorithm>
#include <cassert>

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 public:
    MyStack() : size(0), capacity(0), data(nullptr) {}
    ~MyStack() {
        clear();
    }
    void clear() {
        delete[] data;
        data = nullptr;
        this->capacity = 0;
        this->size = 0;
    }

    bool isEmpty() const {
        if (this->size > 0) {
            return false;
        } else {
            return true;
        }
    }

    T getHead() const {
        return this->data[this->size - 1];
    }

    void push(const T& new_value) {
        if (this->size == this->capacity) {
            this->capacity *= 2;
            if (this->capacity == 0) {
                this->capacity = 1;
            }
            T* new_data = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; ++i) {
                new_data[i] = this->data[i];
            }
            delete[] this->data;
            this->data = new_data;
        }
        this->data[this->size] = new_value;
        this->size += 1;
    }

    T pop() {
        assert(this->size > 0);
        T value = this->data[this->size - 1];
        this->size -= 1;
        return value;
    }

    void print() const {
        std::cout << "Size " << this->size << ": ";
        for (std::size_t i = 0; i < this->size; ++i) {
            std:: cout << this->data[i] << ' ';
        }
        std::cout << std::endl;
    }

 private:
    std::size_t size;
    std::size_t capacity;
    T* data;
};
#endif  // INCLUDE_MYSTACK_H_
