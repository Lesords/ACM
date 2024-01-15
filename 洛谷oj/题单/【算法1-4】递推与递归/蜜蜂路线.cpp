#include<iostream>//ac
using namespace std;
const int MAXN = 305;
int a[MAXN],b[MAXN],ans[MAXN];
void bigadd() {
	//两个值赋给另一个不能直接进位，会把进位消除了！！！
	int rest = 0;//可以开临时变量保存进位量
	for(int i = 1;i < MAXN;i++) {
		ans[i] = a[i]+b[i]+rest;//等号会消除原先的进位量
		rest = ans[i]/10;		//加号的话需要清空数组
		ans[i] %= 10;
	}
}
int main() {
	int n,m,pos;
	a[1] = b[1] = 1;
	cin>>m>>n;
	if(n-m+1<=2) cout<<'1'<<endl;
	else {
		for(int i = 3;i <= n-m+1;i++) {
			bigadd();//累加操作
			for(int j = 1;j < MAXN;j++) {
				b[j] = a[j];//更新前两项
				a[j] = ans[j];//更新前一项
			}
		}
		for(int i = MAXN-1;i >= 1;i--) if(ans[i]) {
			pos = i;break;//找到非零点
		}
		for(int i = pos;i >= 1;i--) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
