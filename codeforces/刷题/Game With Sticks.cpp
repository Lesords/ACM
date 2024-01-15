#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	//每次操作总会拿走一个垂直条和一个水平条
	//判断垂直和水平的最小数量
	//若是奇数，则Akshat赢；否则，Malvika赢
	if(min(n,m)%2) cout<<"Akshat"<<endl;
	else cout<<"Malvika"<<endl;
	return 0;
}
