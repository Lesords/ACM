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
int num[MAXN];
int main() {
    string s;
    cin>>s;
    int ans = 0,cnt = 0,len = s.size();
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='w') {
            cnt++;
            if(i==len-1) num[cnt]++;
        }
        else {
            num[cnt]++;
            cnt = 0;
        }
    }
    for(int i = 1;i <= len;i++) {
        ans += num[i]*(i+i-1);
    }
    cout<<ans<<endl;
	return 0;
}
