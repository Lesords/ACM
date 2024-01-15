// Problem: G. Changing Brackets
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-17 19:29:40

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题解：由于结果不受()影响，所以只需要记录[]的数量
//为了满足[]内的()匹配，那么说明[]的间隔需要为偶数
//也就是说一个括号需要奇数位置，另外一个需要在偶数位置（这样中间的距离才会为偶数）

const int MAXN = 2e6+5;//注意范围！！！
const int MOD = 1e9+7;
const double pi = acos(double(-1));
char s[MAXN];
int sum[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	cin >> (s+1);
    	int len = strlen(s+1);
    	for(int i = 1;i <= len;i++) {
    		sum[i] = sum[i-1];
    		if(s[i]=='['||s[i]==']') {
    			if(i%2) sum[i]++;//奇数位置++
    			else sum[i]--;//偶数位置抵消--
    		}
    	}
    	int n, l, r;
    	cin >> n;
    	while(n--) {
    		cin >> l >> r;
    		//由于可能出现偶数位置较多的情况，即结果为负数，所以需要取绝对值
    		cout << abs(sum[r]-sum[l-1]) << "\n";
    	}
    }
    return 0;
}
