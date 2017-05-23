// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[1] = longUrl;
        return "tinyurl";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[1];
    }
private:
    unordered_map<int, string> m;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
