#include<iostream>//ac
using namespace std;
int head;

//题解：每个位数最多有9个漂亮数（都由一个数组成） 
//所以 n 的漂亮数 =（位数 - 1） * 9 + 高位的漂亮数
//需要判断高位是否有 首位数字 组成的漂亮数 

int f(int n) {
	int pos = 0;
	while(n) {
		if(n<10) head = n;//求首位数字
		n /= 10;
		pos++;
	}
	return pos;
}
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int pos = f(n);//求位数
		int cnt = head;
		for(int i = 1;i < pos;i++) {
			cnt = cnt*10 + head;
		}//所得的 cnt 为首位数字组成的漂亮数
		if(n>=cnt) cout<<(pos - 1) * 9 + head<<endl;
		else cout<<(pos - 1) * 9 + head - 1<<endl;
	}
	return 0;
} 
