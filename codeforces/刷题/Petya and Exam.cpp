#include<iostream>//wrong answer
#include<cstring>
#include<map>
#define MAXN 100005
using namespace std;
char good[MAXN],model[MAXN],tmp[MAXN];
int main() {
	map<char,int> map;
	cin>>good>>model;
	int len=strlen(good),T,lm=strlen(model);
	for(int i=0;i<len;i++) {
		map[good[i]]=1;
	}
	cin>>T;
	while(T--) {
		cin>>tmp;
		int ll=strlen(tmp),flag=0,maxn;
		maxn=ll>lm?ll:lm;
		for(int i=0;i<maxn;i++) {
			if(tmp[i]==model[i]) continue;
			if(model[i]=='*') continue;
			if(model[i]=='?'&&map[tmp[i]]) continue;
			flag=1;
			break;
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
