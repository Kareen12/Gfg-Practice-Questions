// User function Template for C++

// FOR SAME CODE MEMORY LIMIT EXCEEDED ON LEEETCODE
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here
        vector<vector<string>> ans;
        queue<pair<vector<string>, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({{beginWord}, 0});

        int prevLevel = -1;
        vector<string> toBeRemoved;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            vector<string> currSeq = front.first;
            string currString = currSeq[currSeq.size() - 1];
            int currLevel = front.second;

            if (prevLevel != currLevel)
            {
                for (auto s : toBeRemoved)
                {
                    st.erase(s);
                }
                toBeRemoved.clear();
                prevLevel = currLevel;
            }

            if (currString == endWord)
            {
                ans.push_back(currSeq);
            }

            for (int i = 0; i < currString.length(); i++)
            {
                string oldString = currString;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[i] = ch;

                    if (st.find(currString) != st.end())
                    {
                        auto temp = currSeq;
                        temp.push_back(currString);
                        q.push({temp, currLevel + 1});
                        toBeRemoved.push_back(currString);
                    }
                }
                currString = oldString;
            }
        }
        return ans;
    }
};