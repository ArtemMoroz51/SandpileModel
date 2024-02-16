#include "Queue.h"

MyQueue::MyQueue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

MyQueue::~MyQueue() {
    while (frontNode) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}

void MyQueue::add(const std::pair<int, int>& element) {
    Node* newNode = new Node(element);
    if (rearNode) {
        rearNode->next = newNode;
    }
    else {
        frontNode = newNode;
    }
    rearNode = newNode;
    ++queueSize;
}

void MyQueue::pop() {
    if (frontNode) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (!frontNode) {
            rearNode = nullptr;
        }
        --queueSize;
    }
}

std::pair<int, int> MyQueue::show() const {
    if (frontNode) {
        return frontNode->data;
    }
    // Вернуть что-то, что указывает на отсутствие элемента, например:
    return std::make_pair(-2, -2);
}

bool MyQueue::isEmpty() const {
    return queueSize == 0;
}

size_t MyQueue::size() const {
    return queueSize;
}