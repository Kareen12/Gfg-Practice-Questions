class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool mycomp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), mycomp);
        
        int ans = 1;
        int endTime = v[0].second;
        
        for(int i=1; i<n; i++){
            if(v[i].first>endTime){
                ans++;
                endTime = v[i].second;
            }
        }
        return ans;
    }
};