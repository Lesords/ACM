#include<iostream>//ac
#include<cstring>
//解法1：判断是否为循环小数，只需要判断余数是否重复即可
//解法2:1只有除以2和5才可以除尽，所以可以只判断除数是否有包含2和5的倍数
using namespace std;
int book[105];//标记余数，数组大小需为数据上限
int main() {
	int t,a;
	cin>>t;
	while(t--) {
		cin>>a;
		int flag = 1,num = 1;//默认为有限小数
		memset(book,0,sizeof(book));//初始化
		while(num) {
			if(num<a) num *= 10;
			else {
				if(book[num%a]) {
					flag = 0;
					break;
				}
				book[num%a] = 1;//标记余数
				num %= a;
			}
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
