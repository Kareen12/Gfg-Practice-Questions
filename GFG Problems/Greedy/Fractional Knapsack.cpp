//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool mycomp(pair<int, int> a, pair<int, int> b){
        double ratio1 = ((1.0)*a.first)/ a.second;
        double ratio2 = ((1.0)*b.first)/ b.second;
        return ratio1>ratio2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int, int> > data;
        for(int i=0; i<n; i++){
            data.push_back({arr[i].value, arr[i].weight});
        }
        
        sort(data.begin(), data.end(), mycomp);
        
        double ans = 0;
        for(int i=0; i<n; i++){
            if(data[i].second <= W){
                ans += data[i].first;
                W -= data[i].second;
            }
            else{
                double ratio = ((1.0)*data[i].first)/ data[i].second;
                ans += (ratio*W);
                W = 0;
            }
        }
        return ans;
    }
        
};