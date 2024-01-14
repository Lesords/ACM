#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int a[1002];
int main() {
	int n;
	while(cin>>n) {
		if(n==0) break;
		string str,ans;
		int cnt=1,max=0;
		map<string,int> map;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) {
			cin>>str;
			if(!map[str]) map[str]=cnt++;
			a[map[str]]++;
			if(a[map[str]]>max) max=a[map[str]],ans=str;
		}
		cout<<ans<<endl;
	}
	return 0;
}
