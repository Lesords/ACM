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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        int odd = 0,even = 0;
        for(int i = 0;i < s.size();i++) {
            int tmp = s[i]-'0';
            if((i+1)%2&&tmp%2) odd=1;
            if((i+1)%2==0&&tmp%2==0) even=1;
        }
        if(s.size()%2) {
            if(odd) cout<<"1\n";
            else cout<<"2\n";
        }
        else {
            if(even) cout<<"2\n";
            else cout<<"1\n";
        }
    }
	return 0;
}
