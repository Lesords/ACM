#include<iostream>//ac
//移动的次数下限是每次都走2层，上限是每次都走1层(n步)
//需要注意的就是层数为奇数的话，必须有一次得走一层
using namespace std;
int n,m;
int solve() {
	if(n%2==0) {//层数为偶数
		int num = n/2;
		for(int i = num;i <= n;i++) {
			if(i%m==0) return i;
		}
	}
	else {//层数为奇数
		int num = (n-1)/2 + 1;//n-1层为2步的，还有一次得走一层
		for(int i = num;i <= n;i++) {
			if(i%m==0) return i;
		}
	}
	return -1;
}
int main() {
	cin>>n>>m;
	if(n<m) {//层数小于移动最低数
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<solve()<<endl;
	return 0;
}
