#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	int n,m,ans = 0;
	string a,b,t;
	cin>>n>>m>>a>>b;
	if(a.size()<b.size()) t = a,a = b,b = t;
	ans = a.size()-b.size();
	for(int i = 0;i < b.size();i++) if(a[i]!=b[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
