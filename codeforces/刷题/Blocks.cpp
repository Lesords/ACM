#include<iostream>//ac
using namespace std;

//题解：如果有偶数块，说明可以操作为全色
//如果只有一种颜色，则无需操作
//如果都为奇数，则无法操作为全色
//可操作的情况：设一个偶数色为基色，则每次碰到基色修改相邻两块并保存答案

const int MAXN = 205;
int a[MAXN],ans[MAXN * 3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,white = 0,black = 0,cnt = 0;
	cin>>n;
	char tmp;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;//1代表黑色块，0代表白色块
		tmp == 'B'?(black++,a[i] = 1):(white++,a[i] = 0);//必须加括号！！！
	}
	if(black%2&&white%2) cout<<"-1"<<endl;//若两种颜色块都为奇数，则无法成功
	else {
		if(!black||!white) cout<<"0"<<endl;//若只有一种颜色，则无需操作
		else {
			int flag = (black%2==0)?1:0;//flag为偶数的颜色块
			for(int i = 1;i < n;i++) {
				if(a[i] == flag) {
					ans[++cnt] = i;//保存记录（左边块的下标）
					a[i] ^= 1;//与1异或可以把0变为1,1变为0
					a[i+1] ^= 1;
				}
			}
			cout<<cnt<<endl;
			for(int i = 1;i <= cnt;i++) {
				if(i!=1) cout<<' ';
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
