#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

template <typename T>
class QueueFactory {
private:
    bool useLinked;
    int maxSize;

public:
    
    QueueFactory(bool useLinkedQueue = true, int max = 0)
        : useLinked(useLinkedQueue), maxSize(max) {}

    Queue<T>* create() const {
        if (useLinked || maxSize == 0)
            return new LinkedQueue<T>();
        else
            return new ArrayQueue<T>(maxSize);
    }
};

#endif


