// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        flag = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!flag) 
        {
            if (s1.empty())
                s1.push(x);
            else
                s2.push(x);
        }
        else 
        {
            if (s2.empty())
                s2.push(x);
            else 
                s1.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val;
        if (!flag)
        {
            val = s1.top();
            s1.pop();
            while (s2.size() > 1)
            {
                s1.push(s2.top());
                s2.pop();
            }
            flag = 1;
        }
        else
        {
            val = s2.top();
            s2.pop();
            while (s1.size() > 1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            flag = 0;            
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (!flag)
            return s1.top();
        else
            return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
private: 
    stack<int> s1;
    stack<int> s2;
    int flag;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
