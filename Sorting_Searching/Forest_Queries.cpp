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


lint calculateFunction(vector<vector<int>>&matrix,lint x1,lint y1,lint x2,lint y2){
    lint ans=matrix[x2][y2];
    if(x1>0){ans-=matrix[x1-1][y2];}
    if(y1>0){ans-=matrix[x2][y1-1];}
    if(x1>0 && y1>0){ans+=matrix[x1-1][y1-1];}
    return ans;
}
vector<lint>solveFunction(vector<vector<int>>&prefixMatrix,vector<pair<pair<lint,lint>,pair<lint,lint>>>&queries){
    vector<lint>ans;
    forloop(0,queries.size()){
        lint x1=queries[i].first.first-1;
        lint y1=queries[i].first.second-1;
        lint x2=queries[i].second.first-1;
        lint y2=queries[i].second.second-1;
        lint answer=calculateFunction(prefixMatrix,x1,y1,x2,y2);
        ans.push_back(answer);
    }
    return ans;
}

void solution(){
    lint n;lint q;
    cin >> n >> q;
    vector<vector<int>>matrix(n,vector<int>(n));
    forloop(0,n){
        secondfor(0,n){
            char a;cin >> a;
            if(a=='*'){matrix[i][j]=1;}
            else{matrix[i][j]=0;}
        }
    }
    vector<pair<pair<lint,lint>,pair<lint,lint>>>queries;
    forloop(0,q){
        lint x1;lint y1;lint x2;lint y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({{x1,y1},{x2,y2}});
    }
    vector<vector<int>>prefixMatrix(n,vector<int>(n));
    forloop(0,n){
        secondfor(0,n){
            prefixMatrix[i][j]=matrix[i][j];
            if(i>0){
                prefixMatrix[i][j]+=prefixMatrix[i-1][j];
            }
            if(j>0){
                prefixMatrix[i][j]+=prefixMatrix[i][j-1];
            }
            if(i>0 && j>0){
                prefixMatrix[i][j]-=prefixMatrix[i-1][j-1];
            }
        }
    }
    vector<lint> ans=solveFunction(prefixMatrix,queries);
    forloop(0,ans.size()){cout << ans[i] << "\n";}

}
int main(){

    solution();
}