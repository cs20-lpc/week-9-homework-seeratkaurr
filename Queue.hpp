#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
protected:
    int length;

public:
    Queue() : length(0) { }
    virtual ~Queue() { }

    virtual T back() const = 0;
    virtual void clear() = 0;
    virtual void dequeue() = 0;
    virtual void enqueue(const T&) = 0;
    virtual T front() const = 0;
    virtual int getLength() const = 0;
    virtual bool isEmpty() const = 0;
};

#endif
