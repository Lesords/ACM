#include<iostream>//ac
#include<cstring>
using namespace std;
char a[85];
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>a;
		int cnt = 0, ans = 0;
		for(int i = 0;i<strlen(a);i++) {
			if(a[i]!='O') {//ÇåÁã
				cnt = 0;
				continue;
			}
			cnt++;//µþ¼Ó
			ans += cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
