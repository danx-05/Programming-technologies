#include <iostream>

template <typename T>
struct Node {
    T val;
    Node<T>* next;

    Node(T _val) : val(_val), next(nullptr) {}
};

template <typename T>
struct stack {
    int len;
    Node<T>* top;

    stack() : len(0), top(nullptr) {}
    bool is_empty() { return top == nullptr; }
    void push(T _val) {
        Node<T>* p = new Node<T>(_val);
        p->next = top;
        top = p;
        len++;
    }
    T pop() {
        if (is_empty()) {
            std::cout << "Stack is empty" << std::endl;
            return T{};
        }
        Node<T>* temp = top;
        T value = top->val;
        top = top->next;
        delete temp;
        len--;
        return value;
    }
    T peek() {
        if (is_empty()) {
            std::cout << "Stack is empty" << std::endl;
            return T{};
        }
        return top->val;
    }
    void print() {
        if (is_empty()) return;
        Node<T>* p = top;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};


template <typename T>
struct queue {
    stack<T> st1;
    stack<T> st2;

    queue() {
        
    }
    bool q_is_empty() { 
        return st1.is_empty() && st2.is_empty();
    }
    void q_push(T val) {

        st1.push(val);
    }
    T q_pop() {
        // empty
        if (st2.is_empty()) {
            while (!st1.is_empty()) {
                T a = st1.pop();
                st2.push(a);
            }
        }
        T b = st2.pop();
        return b;
    }
    void q_print() {
        if (q_is_empty()) return;
        st2.print();
        st1.print();
    }

};



int main() {
    queue<int> q;
    for (int i = 0; i < 100; i++) {
        q.q_push(i);
    }
    q.q_pop();
    q.q_print();
    int a;
    std::cin >> a;
    return 0;
}
