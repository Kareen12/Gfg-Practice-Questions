#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static bool mycomp(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}

int solve(int arr[], int dep[], int n){
  vector<pair<int, int> > data;
  for(int i=0; i<n; i++){
    data.push_back({arr[i], dep[i]});
  }

  sort(data.begin(), data.end(), mycomp);

  int count = 1;
  int lastDept = data[0].second;
  for(int i=1; i<n; i++){
    if(data[i].first >= lastDept){
      count++;
      lastDept = data[i-1].second;
    }
  }
  return count;
}

int main() {
  int n = 4;
  int arrival[] = {5, 6, 2, 4};
  int departure[] = {7, 11, 6, 5};

  cout<<solve(arrival, departure, n)<<endl;
  return 0;
}