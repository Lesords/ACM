#include<iostream>//ac 
#include<cstring>
#include<algorithm>
using namespace std;
int f(int a) {//计算位数 
	int k = 0;
	while(a) {
		a /= 10;
		k++;
	}
	return k;
}
int a[20],book[11];
int main() {
	int l,r,flag;
	cin>>l>>r;
	for(int i=l;i<=r;i++) {
		memset(book,0,sizeof(book));
		int len = f(i);//位数
		int tmp = i;//临时数
		flag = 0;
		for(int j = 1;j<=len;j++) {
			a[j] = tmp % 10;
			book[a[j]] ++;
			tmp /= 10;
			if(book[a[j]]>1) {//数字有重复
				flag = 1;
				break;
			}
		}
		if(!flag) {//符合条件
			cout<<i<<endl;
			break;
		}
	}
	if(flag) cout<<"-1"<<endl;//不符合条件
	return 0;
}
