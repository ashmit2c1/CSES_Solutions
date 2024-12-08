#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";
#define output(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x,y) make_pair(x,y)
lint findSum(vector<lint>& arr, lint left, lint right) {
    if(left>1){
        return arr[right-1]-arr[left-2];
    }
    else{
        return arr[right-1];
    }
}
vector<lint>solveFunction(vector<lint>&arr,vector<pair<lint,lint>>&queries){
    vector<lint>ans;
    forloop(1,arr.size()){
        arr[i]=arr[i]+arr[i-1];
    }
    forloop(0,queries.size()){
        lint left=queries[i].first;
        lint right=queries[i].second;
        lint sum = findSum(arr,left,right);
        ans.push_back(sum);
    }
    return ans;
}

void solution(){
    lint n;lint k;
    cin >> n >> k;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    vector<pair<lint,lint>>queries;
    forloop(0,k){
        lint x;lint y;
        cin >> x >> y;
        queries.push_back({x,y});
    }
    vector<lint>ans=solveFunction(arr,queries);
    forloop(0,ans.size()){print(ans[i])}

}
int main(){

    solution();
}