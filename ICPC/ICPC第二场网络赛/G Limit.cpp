#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stido(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;

//题解：用泰勒公式把 ln(1+bx) 展开，t为多少就展开多少项
//然后再利用洛必达求解
//求极限方法：
//1. 若分母为0，分子为常数，那么结果为无穷大
//2. 若分子和分母都为0，那么极限为 最高阶项的系数的比值

const int MAXN = 1e5+5;
int d[10];
int main() {
	int n, t;
	cin>>n>>t;
	if(t==0) {//特判t为0的情况，否则会出现浮点错误（除数为0）
		cout<<"0";
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		int a, b;
		cin >> a >> b;
		d[1] += a*b;
		d[2] -= a*b*b;
		d[3] += a*b*b*b;
		d[4] -= a*b*b*b*b;
		d[5] += a*b*b*b*b*b;
	}
	for(int i = 1;i < t;i++) {
		if(d[i]!=0) {
			cout << "infinity\n";
			return 0;
		}
	}
	//分母系数为1，分子系数为 a*b^t/t，其中d[t] = a*b^t（符号看求解过程）
	if(d[t]%t==0) cout << d[t]/t;
	else cout << d[t] << ' ' << t;
	return 0;
}