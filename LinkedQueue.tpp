template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    head = last = nullptr;
    this->length = 0;
    Node* curr = copyObj.head;
    while (curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);
    if (isEmpty()) {
        head = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty())
        throw string("dequeue on empty queue");

    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;

    if (isEmpty())
        last = nullptr;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty())
        throw string("front on empty queue");
    return head->value;
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty())
        throw string("back on empty queue");
    return last->value;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}
