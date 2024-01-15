#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 5e4+10;
int pre[MAXN],last[10];

//注：若两个数相减%7==0,那么这两个数%7的余数一定相同
//即 两个数%7余数相同，相减之后%7==0 ！！！
//所以只需要找对应余数的前后跨度最大的值即可

int main() {
	int n,tmp,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		pre[i] = (pre[i-1]+tmp)%7;
		//保存%7的前缀和
	}
	for(int i = 1;i <= n;i++) {//从前到后找最后的位置
		last[pre[i]] = i;//寻找pre[i]余数的最后位置
	}
	for(int i = 1;i <= n;i++) {//可以直接求ans
		//判断 当前余数的最后出现位置 - i 与ans的大小
		ans = max(ans,last[pre[i]]-i);//pre[i]是余数
	}
	cout<<ans;
	return 0;
}
