#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node() : data(), next(nullptr) {
        // Do Nothing
    }

    Node(T const& data) : data(data), next(nullptr) {
        // Do Nothing
    }

    Node(T const& data, Node* next) : data(data), next(next) {
        // Do Nothing
    }
};

template <typename T>
class List {
public:
    List() : head(nullptr) {
        // Do Nothing
    }

    List(T const* arr, size_t n_nodes) : head(nullptr) {
        if (n_nodes > 0) {
            Node<T>* ptr = nullptr;
            while (n_nodes--) {
                if (ptr) {
                    ptr->next = new Node<T>(*arr++);
                    ptr = ptr->next;
                }
                else {
                    head = ptr = new Node<T>(*arr++);
                }
            }
        }
    }

    List(List const& rhs) : head(nullptr) {
        Node<T>* ptr = nullptr;
        Node<T>* rhs_ptr = rhs.head;
        while (rhs_ptr) {
            if (ptr) {
                ptr->next = new Node<T>(rhs_ptr->data);
                ptr = ptr->next;
            } else {
                head = ptr = new Node<T>(rhs_ptr->data);
            }
            rhs_ptr = rhs_ptr->next;
        }
    }

    List& operator=(List const& rhs) {
        Clear();
        Node<T>* ptr = nullptr;
        Node<T>* rhs_ptr = rhs.head;
        while (rhs_ptr) {
            if (ptr) {
                ptr->next = new Node<T>(rhs_ptr->data);
                ptr = ptr->next;
            } else {
                head = ptr = new Node<T>(rhs_ptr->data);
            }
            rhs_ptr = rhs_ptr->next;
        }

        return *this;
    }

    ~List() {
        Clear();
    }

    void insert_at(size_t idx, T const& data) {
        if (idx > 0) {
            Node<T>* prev = nullptr;
            Node<T>* now = head;

            idx += 1;
            while (--idx && now) {
                prev = now;
                now = now->next;
            }
            if (idx > 0) return;

            prev->next = new Node<T>(data);
            prev->next->next = now;
        } else {
            push_front(data);
        }
    }

    void remove_at(size_t idx) {
        if (idx > 0) {
            Node<T>* now = head;
            while (--idx && now) {
                now = now->next;
            }

            if (idx > 0) return;

            Node<T>* next = now->next->next;
            delete now->next;
            now->next = next;
        } else {
            pop_front();
        }
    }

    void pop_back() {
        if (head) {
            Node<T>* prev = nullptr;
            Node<T>* ptr = head;
            while (ptr->next) {
                prev = ptr;
                ptr = ptr->next;
            }
            delete ptr;

            if (prev) {
                prev->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
    }

    void push_back(T const& data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* prev = head;
            while (prev->next) {
                prev = prev->next;
            }
            prev->next = new Node<T>(data);
        }
    }

    void pop_front() {
        Node<T>* new_head = nullptr;
        if (head->next) {
            new_head = head->next;
        }

        delete head;
        head = new_head;
    }

    void push_front(T const& data) {
        Node<T>* ptr = new Node<T>(data);
        ptr->next = head;
        head = ptr;
    }

    friend std::ostream& operator<<(std::ostream& os, List const& rhs) {
        bool flag = false;
        Node<T>* ptr = rhs.head;
        while (ptr) {
            if (flag) {
                os << ", ";
            }
            os << ptr->data;

            flag = true;
            ptr = ptr->next;
        }
        return os;
    }

private:
    Node<T>* head;

    void Clear() {
        while (head) {
            Node<T>* ptr = head->next;
            delete head;
            head = ptr;
        }
    }
};

#endif