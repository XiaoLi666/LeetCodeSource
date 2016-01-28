/*
 * Author: Zili Wang
 * Date: 25th Jan 2016
 */

class Queue {
public:
    std::deque<int> data;
    
    // Push element x to the back of queue.
    void push(int x) {
        data.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        data.pop_front();
    }

    // Get the front element.
    int peek(void) {
        return data.front();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return data.empty();
    }
};
