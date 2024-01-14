// Problem: Lunch
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=6892
// Memory Limit: 524 MB
// Time Limit: 6000 ms
// 
// Author：Lese
// Time：2021-10-27 00:20:55

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

//题解：对于每个数val的可操作次数为 [val==偶数] + 质因子个数（不包括因子2的数量）
//由于直接筛质因子会导致超时，所以可以先预处理所有的质因子，注意因子数量可以尽量多点！！！
//证明：
//首先，对于质数来说，很显然，只能操作一次（只要一个因子，并且操作完直接为1）
//那么对于非质数而言，都可以分解成对应的质因子相乘（唯一分解定理）
//所以可以操作的次数即为质因子数量

//需要注意的是因子为2的情况，如果存在因子2，那么对答案的贡献其实只有一次
//因为分成偶数堆其实都是一样，在一个堆的操作其实可以在重新在另外一个同步操作
//那么也就是说，在第一个堆先手赢，那么再第二个对后手可以实现先手同样的操作，使得后手赢

const int MOD = 1e9+7;
const double pi = acos(double(-1));

const int MAXV = 1e5+5;
const int MAXN = 1e4+5;
int prim[MAXN], v[MAXV+10], cnt;//v记录最小质因子
//prim数组存储对应的质数，cnt表示质数的数量
void get_prim() {//线性筛质数
    for(int i = 2;i <= MAXV;i++) {
        if(v[i]==0) {
            prim[++cnt] = i;
            v[i] = i;
        }
        for(int j = 1;j <= cnt;j++) {
            if(i*1ll*prim[j]>MAXV||v[i]<prim[j]) break;
            v[i*prim[j]] = prim[j];
        }
    }
}


int main() {
	get_prim();
    int t;
    scanf("%d", &t);
    while(t--) {
    	int n;
    	scanf("%d", &n);
    	int ans = 0;
    	for(int i = 1;i <= n;i++) {
    		int a;
    		scanf("%d", &a);
    		int tmp = a%2==0;//判断是否为偶数（即2的倍数）
    		while(a%2==0) a/=2;//扣除所有2的因子
    		// 只剩下一个因子时，跳过，直接特判！！！
    		// 无需一个个遍历，加快速度
    		//第一个为质数2，所以可以直接从位置2开始遍历
    		for(int j = 2;prim[j]*prim[j] <= a;j++) {
    			if(a%prim[j]) continue;//如果不为因子，直接跳过
    			while(a%prim[j]==0) tmp++, a /= prim[j];
    		}
    		// 由于判断的是x*x的情况，所以会忽略掉只有x的情况，所以需要特判
    		if(a > 1) tmp++;//不为1，那么说明质因子++
    		if(i==1) ans = tmp;
    		else ans ^= tmp;
    	}
    	printf("%c\n", ans?'W':'L');
    }
    return 0;
}
