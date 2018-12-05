#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

template <typename T>
class My_shared_ptr {
public:
    My_shared_ptr() : m_obj(nullptr), count(nullptr) {
        // Do Nothing
    }

    My_shared_ptr(T* obj) : m_obj(obj), count(new int(1)) {
        // Do Nothing
    }

    My_shared_ptr(My_shared_ptr const& rhs) : m_obj(rhs.m_obj), count(rhs.m_count) {
        *count += 1;
    }

    ~My_shared_ptr() {
        *count -= 1;
        if (*count <= 0) {
            delete m_obj;
            delete count;

            std::cout << "Everything destroyed" << std::endl;
        }
    }

    My_shared_ptr& operator=(My_shared_ptr const& rhs) {
        if (m_obj == nullptr || count == nullptr) {
            if (m_obj != nullptr) {
                delete m_obj;
            }
            if (count != nullptr) {
                delete count;
            }
        } else {
            *count -= 1;
            if (*count <= 0) {
                delete m_obj;
                delete count;
            }
        }

        m_obj = rhs.m_obj;
        count = rhs.count;
        *count += 1;

        return *this;
    }

    T const* get_m_obj() const {
        return m_obj;
    }

    int getCount() const {
        if (count) {
            return *count;
        } else {
            return 0;
        }
    }

    void increase() {
        if (count) {
            *count += 1;
        }
    }

    void decrease() {
        if (count) {
            *count -= 1;
        }
    }

private:
    T* m_obj;
    int* count;
};

#endif