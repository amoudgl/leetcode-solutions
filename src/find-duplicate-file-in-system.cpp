// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < paths.size(); i++)
        {
            int j = 0;
            string directory;
            while (j < paths[i].size() && paths[i][j] != ' ')
            {
                directory += paths[i][j];
                j++;
            }
            j++;
            int flag = 0;
            string filename, content;
            while (j < paths[i].size())
            {
                if (!flag && paths[i][j] != '(' & paths[i][j] != ' ')
                {
                    filename += paths[i][j];
                }
                else if (paths[i][j] == '(')
                {
                    flag = 1;
                }
                else if (paths[i][j] == ')')
                {
                    flag = 0;
                    filename = directory + "/" + filename;
                    if (m.find(content) == m.end())
                    {
                        m[content] = vector<string> ();
                    }
                    m[content].push_back(filename);
                    filename = "";
                    content = "";
                }
                else if (flag) content += paths[i][j];
                j++;
            }            
        }
        vector<vector<string> > ans;
        for (auto p : m)
        {
            if (p.second.size() > 1)
                ans.push_back(p.second);
        }
        return ans;
    }
};
