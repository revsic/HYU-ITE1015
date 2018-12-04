#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "MyContainer.h"

#include <stdexcept>

template <typename T>
class MyVector : public MyContainer<T> {
public:
    using MyContainer<T>::obj_arr;
    using MyContainer<T>::n_element;
    using MyContainer<T>::is_allocated;

    MyVector() : MyContainer<T>(), capacity(0) {
        // Do Nothing
    }

    MyVector(size_t n) : MyContainer<T>(n), capacity(n) {
        // Do Nothing
    }

    MyVector(T* arr, size_t n) : MyContainer<T>(arr, n), capacity(n) {
        // DO Nothing
    }

    MyVector(MyVector const& vec) : MyVector(vec.n_element) {
        for (size_t i = 0; i < vec.n_element; ++i) {
            obj_arr[i] = vec.obj_arr[i];
        }
    }

    void clear() {
        MyContainer<T>::clear();
    }

    bool empty() const {
        return n_element == 0;
    }

    size_t size() const {
        return n_element;
    }

    size_t max_size() const {
        return capacity;
    }

    void reserve(size_t n) {
        if (n > capacity) {
            T* ptr = new T[n];
            for (size_t i = 0; i < n_element; ++i) {
                ptr[i] = obj_arr[i];
            }

            if (is_allocated) {
                delete[] obj_arr;
            }
            obj_arr = ptr;
            capacity = n;
            is_allocated = true;
        }
    }

    void push_back(T obj) {
        if (n_element >= capacity) {
            auto max = [](int a, int b) { return a > b ? a : b; };
            reserve(max(1, capacity * 2));
            obj_arr[n_element++] = obj;
        }
    }

    void pop_back() {
        if (n_element > 0) {
            obj_arr[n_element--] = T();
        }
    }

    T& front() {
        return obj_arr[0];
    }

    T& back() {
        return obj_arr[n_element - 1];
    }

    T& at(size_t idx) {
        if (idx < n_element) {
            return obj_arr[idx];
        }
//        throw std::out_of_range("MyVector::at index out of range");
    }

    T& operator[](size_t idx) {
        return obj_arr[idx];
    }

    MyVector operator+(MyVector const& rhs) const {
        size_t total = n_element + rhs.n_element;
        
        MyVector new_vec(total);
        for (size_t i = 0; i < n_element; ++i) {
            new_vec[i] = obj_arr[i];
        }

        for (size_t i = 0; i < rhs.n_element; ++i) {
            new_vec[i + n_element] = rhs.obj_arr[i];
        }
        
        return new_vec;
    }

private:
    size_t capacity;
};

#endif
