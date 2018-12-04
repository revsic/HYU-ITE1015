#ifndef MY_CONTAINER_H
#define MY_CONTAINER_H

#include <iostream>

template <typename T>
class MyContainer {
public:
    MyContainer() : obj_arr(nullptr), n_element(0), is_allocated(false) {
        // Do Nothing
    }

    MyContainer(size_t n) : obj_arr(new T[n]), n_element(n), is_allocated(true) {
        // Do Nothing
    }

    MyContainer(T* arr, size_t n) : obj_arr(arr), n_element(n), is_allocated(false) {
        // Do Nothing
    }

    virtual ~MyContainer() {
        if (is_allocated) {
            delete[] obj_arr;
        }
    }

    void clear() {
        for (size_t i = 0; i < n_element; ++i) {
            obj_arr[i] = T();
        }
    }

    size_t size() const {
        return n_element;
    }

protected:
    T* obj_arr;
    size_t n_element;
    bool is_allocated;
};

#endif