#include<iostream>//ac
#include<cstring>
using namespace std;
int book[300];
int main() {
	int n;
	while(cin>>n) {
		int tmp,max = 0,ans = 0;
		memset(book,0,sizeof(book));//初始化
		for(int i=1;i<=n;i++) {
			cin>>tmp;
			book[tmp+105]++;
			if(book[tmp+105]>max) {
				max = book[tmp+105];
				ans = tmp;
			}
			if(book[tmp+105]==max)//多个众数，取值小的
				ans = ans<tmp?ans:tmp;
		}
		cout<<ans<<' '<<max<<endl;
	}
	return 0;
}
