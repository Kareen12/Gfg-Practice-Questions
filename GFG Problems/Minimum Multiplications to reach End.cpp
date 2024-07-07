// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        queue<int> q;
        vector<int> ans(100000, -1);
        int mod = 100000;
        ans[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            if (front == end)
            {
                int res = ans[front] % mod;
                return res;
            }

            for (auto i : arr)
            {
                int sum = (i * front) % mod;
                if (ans[sum] == -1)
                {
                    ans[sum] = ans[front] + 1;
                    q.push(sum);
                }
            }
        }
        return -1;
    }
};