// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto n1 = parse(a);
        auto n2 = parse(b);
        return to_string(n1.first*n2.first-n1.second*n2.second) + "+" + 
               to_string(n1.first*n2.second+n2.first*n1.second) + "i";
    }
private:
    pair<int, int> parse(string a)
    {
        int i = 0;
        while (a[i] != '+' && i < a.size()) i++;
        int real = stoi(a.substr(0, i));
        int img = stoi(a.substr(i+1, a.size()-i-2));
        return make_pair(real, img);
    }
};
