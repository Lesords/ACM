#include<iostream>//ac
#include<cmath>
using namespace std;

//题解：倒着模拟建表，分为如下几个部分
//1 2
//3 4
//1为初始化，4为全零（不动），只需要赋值2和3区即可

//还可找规律，发现 当前值为 上方与右上方 异或后的值
//类似于杨辉三角

int a[1050][1050] = {{},{0,1,1},{0,1,0}};//初始化
void solve() {
	for(int i = 2;i <= 10;i++) {
		int r = pow(2,i);//总长
		int l = r/2 + 1;//2区二维坐标起始点
		for(int j = 1;j < l;j++) {//以2区为主
			for(int k = l;k <= r;k++) {
				a[j][k] = a[j+l-1][k-l+1] = a[j][k-l+1];
			}//3区相对于2区
		}
	}
}
int main() {
	int n,maxx;
	solve();
	cin>>n;
	maxx = pow(2,n);
	for(int i = maxx;i >= 1;i--) {//倒着输出
		for(int j = maxx;j >= 1;j--) {//倒着输出
			if(j!=maxx) cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
