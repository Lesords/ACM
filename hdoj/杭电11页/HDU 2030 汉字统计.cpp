#include<iostream>//ac 
#include<cstring>
#include<cstdio>
using namespace std;
char a[505];
int main() {
	int T;
	cin>>T;
	getchar();//Ä©Î²×Ö·û
	while(T--) {
		gets(a);
		int cnt = 0;
		for(int i=0;i<strlen(a);i++) {
			if(a[i]<0) {//ºº×ÖÎª¸ºÊý
				cnt++;
			}
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
