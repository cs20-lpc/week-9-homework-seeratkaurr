#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueFactory.hpp"
using namespace std;

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void simulateFixedQueue() {
    cout << "=== Ticket Counter Simulation (Fixed Queue) ===\n";
    QueueFactory<int> fixedFactory(false, 10); // false = use ArrayQueue
    Queue<int>* q = fixedFactory.create();
    int turnedAway = 0;

    for (int i = 0; i < 100; i++) {
        int r = randomInt(-1, 1);
        if (r < 0) {
            try { q->dequeue(); }
            catch (string& e) { cout << "No customer to serve.\n"; }
        } else {
            try { q->enqueue(1); }
            catch (string& e) { turnedAway++; }
        }
    }

    cout << "Turned away: " << turnedAway
         << ", Remaining: " << q->getLength() << endl;
    delete q;
}

void simulateDynamicQueue() {
    cout << "\n=== Bank Line Simulation (Dynamic Queue) ===\n";
    QueueFactory<int> dynamicFactory(true); // true = use LinkedQueue
    Queue<int>* q = dynamicFactory.create();
    int served = 0;

    for (int i = 0; i < 100; i++) {
        int r = randomInt(-1, 2);
        if (r < 0) {
            try { q->dequeue(); served++; }
            catch (string& e) { cout << "No customer to serve.\n"; }
        } else {
            q->enqueue(1);
        }
    }

    cout << "Served: " << served
         << ", Remaining: " << q->getLength() << endl;
    delete q;
}

int main() {
    srand(time(0));
    simulateFixedQueue();
    simulateDynamicQueue();
    return 0;
}
