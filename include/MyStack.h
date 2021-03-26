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

    void push_back(const T& value) {
        if (this->capacity == this->size) {
            this->capacity = std::max((std::size_t)1, 2 * this->capacity);
            T* new_data = new T[this->capacity];
//            for (std::size_t i = 0; i < this->size; ++i) {
//                new_data[i] = this->data[i];
//            }

            delete[] this->data;
            this->data = new_data;
        }

        this->data[this->size] = value;
        ++this->size;
    }
    void pop_back() {
        assert(this->size > 0);
        delete this->data[this->size - 1];
        this->size -= 1;
    }
//    void resize(std::size_t size) {
//        if (size < my_size) {
//            for (std::size_t i = size; i < my_size; ++i) {
//                my_data[i] = T{};
//            }
//        } else if (size > my_size) {
//            if (size > my_capacity) {
//                my_capacity = size;
//                T* tmp = new T[my_capacity];
//
//                for (std::size_t i = 0; i < my_size; ++i) {
//                    tmp[i] = my_data[i];
//                }
//
//                delete[] my_data;
//                my_data = tmp;
//            }
//        }
//        my_size = size;
//    }
//
//
//    void reserve(std::size_t new_cap){
//        if(new_cap > my_capacity){
//            T* new_data = new T[new_cap];
//            for(std::size_t i = 0; i < new_cap; ++i){
//                new_data[i] = i < my_size ? my_data[i] : T{};
//            }
//            delete[] my_data;
//            my_data = new_data;
//            my_capacity = new_cap;
//        }
//    }
//
//    void reverse(){
//        for(std::size_t i = 0; i < my_size / 2; ++i){
//            std::size_t j = (my_size - 1) - i;
//            T temp = my_data[i];
//            my_data[i] = my_data[j];
//            my_data[j] = temp;
//        }
//    }
//
//    std::size_t size() const {
//        return my_size;
//    }

 private:
    std::size_t size;
    std::size_t capacity;
    T* data;
};
#endif  // INCLUDE_MYSTACK_H_
