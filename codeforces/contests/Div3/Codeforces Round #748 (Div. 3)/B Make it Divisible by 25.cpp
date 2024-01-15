// Problem: B. Make it Divisible by 25
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-13 22:39:46

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int one[10], two[10];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	string s;
    	cin >> s;
    	//00 25 50 75
    	int len = s.size()-1, ans = INF;
    	int pos = 0, tmp = 0,flag = 0;
    	int zero = 0;
    	for(int i = 0;i <= len;i++) {
    		if(s[i]=='0') {
    			zero = 1;break;
    		}
    	}
    	for(int i = len;i >= 0;i--) {
    		if(pos==0&&s[i]=='0') pos++;
    		else if(pos==1&&s[i]=='0') {
    			flag = 1;break;
    		}
    		else tmp++;
    	}
    	if(flag) ans = min(ans, tmp);
		flag = pos = tmp = 0;
    	for(int i = len;i >= 0;i--) {
    		if(pos==0&&s[i]=='5') pos++;
    		else if(pos==1&&s[i]=='2') {
    			flag = 1;break;
    		}
    		else tmp++;
    	}
    	if(flag) ans = min(ans, tmp);
    	flag = pos = tmp = 0;
    	for(int i = len;i >= 0;i--) {
    		if(pos==0&&s[i]=='0') pos++;
    		else if(pos==1&&s[i]=='5') {
    			flag = 1;break;
    		}
    		else tmp++;
    	}
    	if(flag) ans = min(ans, tmp);
    	flag = pos = tmp = 0;
    	for(int i = len;i >= 0;i--) {
    		if(pos==0&&s[i]=='5') pos++;
    		else if(pos==1&&s[i]=='7') {
    			flag = 1;break;
    		}
    		else tmp++;
    	}
    	if(flag) ans = min(ans, tmp);
    	if(ans==INF) {
    		ans = len+1 - zero;
    	}
    	cout << ans <<"\n";
    }
    return 0;
}
