/* Min Stack
Solution
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/


class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int x) {
        pair<int,int> p;
        if(s.empty())
        {
            p = {x,x};
        }
        
        else
        {
            p = {x,min(x,s.top().second)};
        }
        
        s.push(p);
        
    }
    
    void pop() {
        s.pop();
        
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */