#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
char a[105],b[105];
int book_a[30],book_b[30];
int main() {
	while(cin>>a>>b) {
		int len = strlen(a);
		memset(book_a,0,sizeof(book_a));
		memset(book_b,0,sizeof(book_b));
		for(int i = 0;i < len;i++) {
			book_a[a[i]-'A']++;//记录a数组中每个字符出现的次数
			book_b[b[i]-'A']++;//记录b数组中每个字符出现的次数
		}
		sort(book_a,book_a+26);
		sort(book_b,book_b+26);
		int flag = 0;
		//若ab两个数组里的某个字符出现的次数都一致
		//则可以通过映射，使得两个字符串相等
		for(int i = 0;i < 26;i++) {
			if(book_a[i]!=book_b[i]) {
				flag = 1;
				break;
			}
		}
		flag?cout<<"NO"<<endl:cout<<"YES"<<endl;
	}
	return 0;
}
