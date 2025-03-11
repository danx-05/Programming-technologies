#include <iostream>
#include <random>
#include <chrono>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node<T>* next;

    Node(T _val) : val(_val), next(nullptr) {}
};

template <typename T>
struct list {
    Node<T>* first;
    Node<T>* last;
    int len;

    list() : first(nullptr), last(nullptr), len(0) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(T _val) {
        Node<T>* p = new Node<T>(_val);
        if (is_empty()) {
            first = p;
            last = p;
        }
        else {
            last->next = p;
            last = p;
        }
        len++;
    }

    void print() {
        if (is_empty()) return;
        Node<T>* p = first;
        while (p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    void remove_first() {
        if (is_empty()) return;
        Node<T>* p = first;
        first = p->next;
        delete p;
        len--;
        if (is_empty()) {
            last = nullptr;
        }
    }

    void remove_last() {
        if (is_empty())
            return;
        if (first == last) {
            remove_first();
            return;
        }
        Node<T>* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
        len--;
        if (is_empty()) {
            first = nullptr;
            last = nullptr;
        }
    }

    void delete_node(int num) {
        if (is_empty()) return;

        if (num < 0 || num >= len) {
            cout << "Index out of bounds" << endl;
            return;
        }

        if (num == 0) {
            remove_first();
            return;
        }

        if (num == len - 1) {
            remove_last();
            return;
        }

        Node<T>* current = first;
        for (int i = 0; i < num - 1; ++i) {
            current = current->next;
        }

        Node<T>* node_to_delete = current->next;
        current->next = node_to_delete->next;
        delete node_to_delete;
        len--;
    }

    
    void insert(int index, T _val) {
        if (index < 0 || index > len) {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node<T>* new_node = new Node<T>(_val);

        if (index == 0) {
            if (is_empty()) {
                last = new_node;
            }
            new_node->next = first;
            first = new_node;
            
        }
        else {
            Node<T>* current = first;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;

            if (index == len) {
                last = new_node;
            }
        }
        len++;
    }
    Node<T>* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node<T>* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
    ~list() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        first = nullptr;
        last = nullptr;
        len = 0;
    }
};

list<int>* generetor_sp(int n) {
    list<int>* List = new list<int>();
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 1000);
    for (int j = 0; j < n; j++) {
        int a = distribution(generator);
        List->push_back(a);
    }
    return List;
}

