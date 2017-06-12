// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty())
            s.push(make_pair(nestedList, 0));
    }

    int next() {
        int val = s.top().first[s.top().second].getInteger();
        auto p = s.top();
        s.pop();
        s.push(make_pair(p.first, p.second+1));
        return val;
    }

    bool hasNext() {
        while (!s.empty() && (s.top().first.size() == 0 || s.top().second == s.top().first.size() || 
                              s.top().first[s.top().second].isInteger() == false))
        {
            if (s.top().first.size() == 0 || s.top().second == s.top().first.size())
            {
                s.pop();
                if (!s.empty())
                {
                    auto p = s.top();
                    s.pop();
                    s.push(make_pair(p.first, p.second+1));
                }
            }
            else if (s.top().first[s.top().second].isInteger() == false)
            {
                vector<NestedInteger> v = s.top().first[s.top().second].getList();
                s.push(make_pair(v, 0));
            }
        }
        if (!s.empty()) return true;
        return false;
    }
private: 
    stack<pair<vector<NestedInteger>, int>> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
