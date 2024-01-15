#include<iostream>//ac
using namespace std;

//题目分析：数据为 1e6* 位数 7 ，复杂度也只为 7e6
//可以从0开始计数，利用 前缀和相减 会抵消掉
 
const int MAXN = 1e6 + 5;
int book[15] = {1,0,0,0,1,0,1,0,2,1},a[MAXN];
int main() {
	for(int i = 1;i < MAXN;i++) {//遍历全部数据
		int tmp = i,cnt = 0;
		while(tmp) {//遍历每个数字的圈圈
			cnt += book[tmp%10];
			tmp /=10;
		}
		a[i] = a[i-1] + cnt;
	}
	int t;cin>>t;
	while(t--) {
		int left,right;
		cin>>left>>right;
		cout<<a[right] - a[left - 1]<<endl;//left左移一位
	}
	return 0;
}
