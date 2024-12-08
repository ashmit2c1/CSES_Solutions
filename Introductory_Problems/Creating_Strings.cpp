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

void generateStrings(set<string>&st,string s,lint index){
    if(index==s.size()){
        st.insert(s);
        return;
    }
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        generateStrings(st,s,index+1);
        swap(s[index],s[i]);
    }
}

void solution(){
    string s;cin >> s;
    lint ans=0;
    set<string>st;
    generateStrings(st,s,0);
    vector<string>result;
    for(auto it=st.begin();it!=st.end();it++){
        result.push_back(*it);
    }
    print(result.size());
    forloop(0,result.size()){
        print(result[i])
    }
}
int main(){

    solution();
}