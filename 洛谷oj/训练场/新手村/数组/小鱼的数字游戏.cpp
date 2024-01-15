#include<iostream>//ac
using namespace std;
int a[105];
int main() {
	int tmp,cnt = 1;
	while(1) {
		cin>>tmp;
		if(tmp==0) break;//0ÍË³ö
		a[cnt++] = tmp;
	} 
	for(int i = cnt-1;i >= 1;i--) {
		cout<<a[i];
		i==1?cout<<endl:cout<<' ';
	}
	return 0;
}
