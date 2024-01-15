#include<iostream>//ac
using namespace std;

//题解：埃式筛法，筛到合数时，从当前数往后遍历，合数因子数++
//若为素数，则从当前数*2往后遍历，筛选合数
//最后再标记每个数的合数因子数

const int MAXN = 1e5 + 5;
int prim[MAXN],cnt[MAXN],ans[MAXN];
int main() {
	int n,m,tmp;
	cin>>n>>m;
	for(int i = 2;i <= n;i++) {
		if(prim[i]) {//1表示合数，0表示素数
			for(int j = i;j <= n;j+=i) cnt[j]++;//cnt保存j的合数因子数
		}//以i开始的合数（间隔为i），合数因子数++
		else for(int j = i+i;j <= n;j += i) prim[j] = 1;
		ans[cnt[i]]++;//标记i的合数因子数
	}//桶排序思想
	for(int i = 1;i <= m;i++) {
		cin>>tmp;
		cout<<ans[tmp]<<endl;
	}
	return 0;
}
