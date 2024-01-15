#include<iostream>//wa
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		string s;
		int ans = 0;
		while(n--) {
			cin>>s;
			for(int i = 0;i < s.size();i++) {
				if(s[i]=='1') ans++;
			}
		}
		if(ans%2) cout<<"sdzNB\n";
		else cout<<"kgNB\n";
	}
	return 0;
}
