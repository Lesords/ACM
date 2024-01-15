#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    int t;
    fast;
    cin>>t;
    while(t--) {
        int n,k,ans = 0;
        string s;
        vector<int> v;
        cin>>n>>k>>s;
        for(int i = 0;i < n;i++) {//记录所有*的位置，然后用双指针求解
            if(s[i]=='*') v.push_back(i);
        }
        if(v.size()<=2) {
            cout<<v.size()<<"\n";
            continue;
        }
        ans = 2;
        int l = 0,r = v.size()-1;
        while(v[r]-v[l]>k) {
            int posl = l;
            while(v[posl+1]-v[l]<=k) posl++;//可以等于！！！
            l = posl;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
2
3 2
***
4 3
*.**
*/
