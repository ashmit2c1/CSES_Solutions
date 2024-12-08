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

// BRUTE FORCE APPROACH 
lint solveFunction(vector<lint>&arr,lint target){
    lint cnt=0;
    forloop(0,arr.size()){
        lint sum=0;
        secondfor(i,arr.size()){
            sum+=arr[j];
            if(sum==target){cnt++;}
        }
    }
    return cnt;
}
// OPTIMISED APPROACH 
lint solveFunction2(vector<lint>&arr,lint target){
    unordered_map<lint,lint>mp;
    lint currentSum=0;
    lint cnt=0;
    mp[0]=1;
    forloop(0,arr.size()){
        currentSum+=arr[i];
        if(mp.find(currentSum-target)!=mp.end()){
            cnt+=mp[currentSum-target];
        }
        mp[currentSum]++;
    }
    return cnt;
}
// SLIDING WINDOW APPROACH
lint solveFunction3(vector<lint>&arr,lint target){
    lint left=0;lint right=0;
    lint currentSum=0;lint cnt=0;
    while(right<arr.size()){
        currentSum+=arr[right];
        while(currentSum>target && left<=right){
            currentSum-=arr[left];
            left++;
        }
        if(currentSum==target){
            cnt++;
        }
        right++;
    }
    return cnt;
}


void solution(){
    lint n;lint sum;
    cin >> n >> sum;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solveFunction2(arr,sum);
    print(ans)

}
int main(){

    solution();
}