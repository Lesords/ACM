#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
	map<char,int> mapp;
	string s;
	int maxx = 0;
	char ans;
	while(getline(cin,s)) {
		for(int i = 1;i < s.size();i++) {
			mapp[s[i]]++;
			if(mapp[s[i]]>maxx) {
				maxx = mapp[s[i]];
				ans = s[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
