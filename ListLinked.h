#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        out << "[";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) out << ", ";
            current = current->next;
        }
        out << "]";
        return out;
    }

    // --- MÉTODOS HEREDADOS ---

    void insert(int pos, T e) override {}

    void append(T e) override {}

    void prepend(T e) override {}

    T remove(int pos) override {
        return T();
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) override {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

#endif
