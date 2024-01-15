#include<iostream>//ac
using namespace std;
int op[6] = {100,20,10,5,1};
int main() {
	int n,ans = 0,tmp;
	cin>>n;
	//币值越大数量就越少
	for(int i = 0;i < 5;i++) {//直接判断五种币值的数量
		tmp = n/op[i];	//当前币值的数量
		ans += tmp;		//添加数量
		n %= op[i];		//去除对应的金额
		if(n==0) break;	//结束（全分完）
	}
	cout<<ans<<endl;
	return 0;
}
