#include<iostream>//ac
using namespace std;
int ans,vis[10],a[10],n;
int get_val(int left,int right) {//对应范围的值
	int ans = 0;
	for(int i = left;i <= right;i++) ans = ans*10+a[i];
	return ans;
}
void dfs(int pos) {//生成全排列
	if(pos==10) {//已满足9个数
		for(int i = 1;i <= 7;i++)  {//第一个数（需留两个）
			for(int j = i+1;j <= 8;j++) {//第二个数（需留一个）
				int A = get_val(1,i);
				int B = get_val(i+1,j);
				int C = get_val(j+1,9);//计算三个数的值
				if(n*C==A*C+B) {// n = A + B/C 的变式（防止整除取整）
					ans++;return;
				}
			}
		}
		return ;
	}
	for(int i = 1;i <= 9;i++) {//遍历所有情况
		if(vis[i]) continue;//跳过已使用的数字
		vis[i] = 1;//标记
		a[pos] = i;//记录pos位置的值
		dfs(pos+1);
		vis[i] = 0;//取消标记
	}
}
int main() {
	cin>>n;
	dfs(1);//初始位置从1开始
	cout<<ans<<endl;
	return 0;
}
