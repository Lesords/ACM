#include<iostream>//ac
#include<algorithm>
#include<cmath>//ceil向上取整（ceil需为浮点数）
using namespace std;
const int MAXN = 2e5 + 5;
int num[MAXN];//需要跳过的次数
int main() {
	int n,a,b,k,tmp,ans = 0;
	cin>>n>>a>>b>>k;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		tmp %= a+b;//去掉正常击杀的血量
		//刚好被b击杀时，需要还原到b击杀的血量（此时无先手）
		if(tmp==0) num[i] = ceil(b*1.0/a*1.0);//只剩下b的血量
		else num[i] = ceil(tmp*1.0/a*1.0)-1;//去除先手一次
	}
	sort(num+1,num+1+n);
	for(int i = 1;i <= n;i++) {
		if(k>=num[i]) {
			ans++;//结果++
			k -= num[i];//更新可跳过的次数
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
