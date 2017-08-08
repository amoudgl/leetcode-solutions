class Solution {
public:
    vector<string> letterCombinations(string digits) {
        m['2']="abc"; m['3']="def"; m['4']="ghi"; m['5']="jkl"; m['6']="mno"; m['7']="pqrs"; m['8']="tuv"; m['9']="wxyz";
        string s;
        f(digits, 0, s);
        return ans;
    }
    void f(string digits, int k, string s)
    {
        if (k == digits.length())
        {
            if (!s.empty()) ans.push_back(s);
            return;
        }
        for (int i = 0; i < m[digits[k]].size(); i++)
        {
            f(digits, k+1, s+m[digits[k]][i]);
        }
    }
private:
    vector<string> ans;
    unordered_map<char, string> m;
};
