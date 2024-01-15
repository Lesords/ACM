// Problem: D. Another Problem About Dividing Numbers
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.ml/problemset/problem/1538/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-12 16:10:40

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题意：给定两个数字a和b，可以对每个数进行 /c 的操作，其中c为对应数的因子
//请是否可以进行k次操作使得 a 和 b 的最后结果相等
//题解：特判k为1的情况，此时要么a为b的倍数，要么b为a的倍数，并且a不等于b
//否则计算a和b的因子个数，如果k在此范围内，那么满足条件，否则不满足条件
//因为对于任意的a和b，可以有  a/a = 1, b/b = 1
//所以在因子数量为范围内，可以控制对应的次数，使其最后结果为1

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int cal(int val) {//计算val的因子个数
	int ans = 0;
	for(int i = 2;i*i <= val;i++) {
		while(val%i==0) {
			val /= i;
			ans++;
		}
	}
	//如果val不为1，因子数++（因为判断条件为i*i）
	if(val > 1) ans++;
	return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int a, b, k;
    	cin >> a >> b >> k;
    	//特判操作次数为1的情况
    	if(k==1) {
    		//注意a不能等于b！！！
    		if(a!=b && (a%b==0||b%a==0)) { 
    			cout << "YES\n";
    		}
    		else cout << "NO\n";
    	}
    	else {
    		//两个数的因子数量必须大于等于k
    		if(cal(a) + cal(b) >= k) {
    			cout << "YES\n";
    		}
    		else cout << "NO\n";
    	}
    }
    return 0;
}
