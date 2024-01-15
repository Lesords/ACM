#include<iostream>//ac
using namespace std;
int ans = 0,n,a[11];
void dfs(int pos, int sum,int flag) {
	if(sum>n) return;
	if(pos==10) {
		if(sum==n) {
			if(!flag) ans++;//只计算结果
			else{//输出配料结果
				for(int i = 1;i <= 10;i++) cout<<a[i]<<' ';
				cout<<endl;
			}
		}
		return;
	}
	for(int i = 1;i <= 3;i++) {//只有3种情况
		a[pos+1] = i;//保存结果（下一位）
		dfs(pos+1,sum+i,flag);
	}
}
int main() {
	cin>>n;
	dfs(0,0,0);//第一次调用只计算ans，从位置0开始计算
	cout<<ans<<endl;
	dfs(0,0,1);//第二次调用输出结果序列
	return 0;
}
