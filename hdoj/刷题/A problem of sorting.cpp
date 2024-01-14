#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct people{
	char name[130];
	int birth;
	friend bool operator < (people a, people b) {
		return a.birth<b.birth;
	}
};
int main() {
	int t;
	cin>>t;//不开同步，开了会wa 
	while(t--) {
		int n;
		cin>>n;
		getchar();//scanf("%*c");
		priority_queue<people> q;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) {
			people tmp;
			gets(tmp.name);
			int l=strlen(tmp.name);
			tmp.birth=(tmp.name[l-4]-'0')*1000+(tmp.name[l-3]-'0')*100+(tmp.name[l-2]-'0')*10+tmp.name[l-1]-'0'; 
			tmp.name[l-5]='\0';
			q.push(tmp);
		}
		while(!q.empty()) {
			people tmp;
			tmp=q.top();
			q.pop();
			cout<<tmp.name<<endl;
		}
	}
	return 0;
}
