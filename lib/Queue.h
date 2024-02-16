#pragma once
#include <iostream>

class MyQueue {
public:
    MyQueue();
    ~MyQueue();

    void add(const std::pair<int, int>& element);
    void pop();
    std::pair<int, int> show() const;
    bool isEmpty() const;
    size_t size() const;

private:
    struct Node {
        std::pair<int, int> data;
        Node* next;
        Node(const std::pair<int, int>& val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t queueSize;
};