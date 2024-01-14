#include<iostream>//ac
using namespace std;
struct Matrix{//二阶矩阵
	int f[2][2];
};
Matrix mul(Matrix a,Matrix b) {//矩阵乘法
	Matrix ans;
	for(int i = 0;i < 2;i++) {//先行后列
		for(int j = 0;j < 2;j++) {//遍历四个位置
			ans.f[i][j] = 0;//初始化为0
			for(int k = 0;k < 2;k++) {//计算对应位置的结果
				ans.f[i][j] += (a.f[i][k]*b.f[k][j])%7;
			}//行i * 列j
			ans.f[i][j] %= 7;//取余
		}
	}
	return ans;//返回结果
}
int main() {
	int A,B,n;
	while(cin>>A>>B>>n&&A+B+n) {
		if(n<=2) {//小于2
			cout<<'1'<<endl;
			continue;
		}
		Matrix a,ans;
		a.f[0][0] = A, a.f[0][1] = B;
		a.f[1][0] = 1, a.f[1][1] = 0;//规律矩阵
		ans.f[0][0] = ans.f[0][1] = 1;//0行对应的是结果
		ans.f[0][1] = ans.f[1][1] = 0;
		n -= 2;//从第三位开始才需要乘
		while(n) {//矩阵快速幂
			if(n&1) ans = mul(ans,a);//将乘法改为矩阵乘法
			n>>=1;
			a = mul(a,a);//同理
		}
		cout<<(ans.f[0][0]+ans.f[0][1])%7<<endl;
		//f[0][0]+f[0][1] 对应的是结果 f(n)
	}
	return 0;
}
