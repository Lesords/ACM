#include<iostream>//ac
#include<cstring>
#include<cstdio>
using namespace std;
char a[105]; 
int main() {
	while(gets(a)) {
		if(a[0]=='#') break;//��β
		int ans = 0;
		for(int i = 0;i < strlen(a);i++) {
			if(a[i]==' ') continue;//�ո�����
			ans += (a[i]-'A'+1) *(i+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
