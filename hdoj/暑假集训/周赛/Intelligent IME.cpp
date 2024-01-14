#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int t,a[5005];
	cin>>t;
	while(t--) {
		int n,m;
		string str1,str2;
		map<string,int> ans;
		map<string,int>::iterator it;
		map<char,char> map;
		memset(a,0,sizeof(a));
		map.clear();
		ans.clear();
		map['a']=map['b']=map['c']='2';
		map['d']=map['e']=map['f']='3';
		map['g']=map['h']=map['i']='4';
		map['j']=map['k']=map['l']='5';
		map['m']=map['n']=map['o']='6';
		map['p']=map['q']=map['r']=map['s']='7';
		map['t']=map['u']=map['v']='8';
		map['w']=map['x']=map['y']=map['z']='9';
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			cin>>str1;
			ans[str1]=0;
		}
		for(int i=1;i<=m;i++) {
			cin>>str2;
			for(int j=0;j<str2.size();j++) {
				str2[j]=map[str2[j]];
			}
			ans[str2]++;
		}
		int cnt=0;
		for(it=ans.begin();it!=ans.end();it++) {
			a[cnt]=it->second;
			cnt++;
		}
		sort(a,a+cnt,cmp);
		for(int i=0;i<cnt;i++) {
			cout<<a[i]<<endl;
		}
	}
	return 0;
}
