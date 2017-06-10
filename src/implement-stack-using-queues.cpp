// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        flag = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (!flag)
        {
            if (!q1.empty())
            {
                int x;
                x = q1.front();
                q1.pop();
                q2.push(x);
            }
            q1.push(x);
        }
        else
        {
            if (!q2.empty())
            {
                int x;
                x = q2.front();
                q2.pop();
                q1.push(x);
            }
            q2.push(x); 
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val;
        if (!flag)
        {
            val = q1.front();
            q1.pop();
            while(q2.size() > 1)
            {
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
            flag = 1;
        }
        else
        {
            val = q2.front();
            q2.pop();
            while(q1.size() > 1)
            {
                int x = q1.front();
                q1.pop();
                q2.push(x);
            }
            flag = 0;            
        }
        return val;
    }
    
    /** Get the top element. */
    int top() {
        if (!flag)
            return q1.front();
        else
            return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }
private:
    queue<int> q1;
    queue<int> q2;
    int flag;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
