#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue : public Queue<T> {
protected:
    struct Node {
        T value;
        Node* next;
        Node(T v, Node* n = nullptr) : value(v), next(n) {}
    };
    Node* head;
    Node* tail;

public:
    LinkedQueue();
    virtual ~LinkedQueue();
    virtual void enqueue(const T&) override;
    virtual void dequeue() override;
    virtual T front() const override;
    virtual T back() const override;
    virtual bool isEmpty() const override;
    virtual int getLength() const override { return this->length; }

private:
    void copy(const LinkedQueue<T>&);
};

#include "LinkedQueue.tpp"
#endif
