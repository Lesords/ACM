#include<iostream>//ac
using namespace std;
const int MAXN = 5e3 + 5;
int a[MAXN];
int find(int n) {//需要更新a[n]的值！！！
	return a[n]=n==a[n]?n:find(a[n]);
}
int main() {
	int n,m,p,tmp1,tmp2;
	cin>>n>>m>>p;
	for(int i = 1;i <= n;i++) a[i] = i;//初始化
	for(int i = 1;i <= m;i++) {
		cin>>tmp1>>tmp2;
		int one = find(tmp1);
		int two = find(tmp2);
		if(one!=two) {//根源赋值！！！
			a[two] = one;
		}
	}
	while(p--) {
		cin>>tmp1>>tmp2;
		if(find(tmp1)==find(tmp2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
