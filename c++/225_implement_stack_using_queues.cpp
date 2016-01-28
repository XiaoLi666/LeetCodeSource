/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
 */

class Stack {
public:
    deque<int> stack;
    // Push element x onto stack.
    void push(int x) {
        stack.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        stack.pop_back();
    }

    // Get the top element.
    int top() {
        return stack.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return stack.empty();
    }
};
