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


lint solvefunction(vector<lint>&arr){
    sort(arr.begin(),arr.end());
    lint sum=0;
    lint median;
    if(arr.size()&1==true){
        median = (arr[arr.size()/2] + arr[(arr.size()-1)/2])/2;
    }
    else{
        median=arr[arr.size()/2];
    }
    forloop(0,arr.size()){
        sum+=abs(median-arr[i]);
    }
    return sum;
}

void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){
        lint x;cin >> x;arr.push_back(x);
    }
    lint ans=solvefunction(arr);
    print(ans)

}
int main(){

    solution();
}