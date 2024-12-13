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

lint solveFunction(vector<lint>&arr){
    lint cnt = 0;
    lint n = arr.size();
    lint prefixSum = 0;
    unordered_map<lint, lint> freq;
    freq[0] = 1;
    for (lint i = 0; i < n; i++) {
        prefixSum += arr[i];
        lint mod = (prefixSum % n + n) % n;
        if (freq.find(mod) != freq.end()) {
            cnt += freq[mod];
        }
        freq[mod]++;
    }

    return cnt;
}

/*lint solveFunction(vector<lint>&arr){
    vector<lint>copy=arr;
    forloop(1,copy.size()){
        copy[i]+=copy[i-1];
    }
    lint cnt=0;
    forloop(0,arr.size()){
        lint sum=0;
        secondfor(i,arr.size()){
            if(i==0){sum=copy[j];}
            else{sum=copy[j]-copy[i-1];}
            if(sum%arr.size()==0){cnt++;}
        }
    }
    return cnt;
}

lint solveFunction(vector<lint>&arr){
    lint cnt=0;
    forloop(0,arr.size()){
        lint sum=0;
        secondfor(i,arr.size()){
            sum+=arr[j];
            if(sum%arr.size()==0){cnt++;}
        }
    }
    return cnt;
}*/

void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solveFunction(arr);
    print(ans)

}
int main(){

    solution();
}