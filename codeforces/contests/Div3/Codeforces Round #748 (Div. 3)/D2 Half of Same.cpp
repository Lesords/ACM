// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-13 23:22:55

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

//题解：由于结果肯定是两数之差或者其的因子（注意，因子也行！！！）
//那么可以先遍历所有可能值
//由于对一个数进行若干次-k，其实相当于%k
//所以可以记录 所有值%对应可能值 的出现次数，若有出现次数大于一半的情况，说明当前值可行
//注意：模的结果会有负数，所以模两次，第一次中加上对应的模数（不需要计算倍数）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[50], b[50];
int gcd(int a, int b) {
	return a%b==0?b:gcd(b, a%b);
}
bool cmp(int a,int b) {
	return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin >> n;
    	map<int,int> num;
    	int siz = ceil(n/2.0);
    	int ans = 0;
    	for(int i = 1;i <= n;i++) {
    		cin >> a[i];
    		num[a[i]]++;
    		if(num[a[i]] >= siz) {
    			ans = -1;
    		}
    	}
    	if(ans==-1) {
    		cout << "-1\n";
    		continue;
    	}
    	vector<int> dif;
    	for(auto v:num) {
    		// cout << v.fi << " " << v.se << "\n";
    		for(auto t:num) {
    			if(v.fi==t.fi) continue;
    			int maxx = max(v.fi, t.fi);
    			int minn = min(v.fi, t.fi);
    			int val = maxx-minn;
    			dif.push_back(maxx-minn);
    			//需要记录val的所有因子！！！
    			for(int i = 2;i*i <= val;i++) {
    				if(val%i==0) dif.push_back(i), dif.push_back(val/i);
    			}
    		}
    	}
    	sort(dif.begin(), dif.end(), cmp);
    	int pos = unique(dif.begin(), dif.end()) - dif.begin();
    	for(int i = 0;i < pos;i++) {
    		map<int,int> cnt;
    		int num = 0;
    		// cout <<"dif:"<<dif[i] <<"\n";
    		for(int j = 1;j <= n;j++) {
    			ll tmp = a[j];
    			int vv = ((a[j]%dif[i])+dif[i])%dif[i];
    			// cout << vv << " ";
    			cnt[vv]++;
    			if(cnt[vv]>num) num = cnt[vv];
    			a[j] = tmp;
    		}
    		// cout <<"\n";
    		if(num >= siz) {
    			ans = dif[i];break;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
