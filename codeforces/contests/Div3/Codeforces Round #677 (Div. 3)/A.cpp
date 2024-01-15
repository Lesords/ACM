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
        int n;cin>>n;//n为重复的数字
        int ans = 0;
        for(int i = 1;i < n%10;i++) {//遍历所有可能的情况(没包括当前值)
            ans += 1+2+3+4;//总共有4种情况（4种位）
        }
        int cnt = 0;
        while(n) {//判断当前数有几位
            n /= 10;
            cnt++;
        }
        for(int i = 1;i <= cnt;i++) ans += i;//遍历所有位数，并计算和
        cout<<ans<<endl;
    }
	return 0;
}
