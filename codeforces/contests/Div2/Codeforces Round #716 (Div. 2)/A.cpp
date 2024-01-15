#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题意：子序列的乘积是否为不为完全平方数，若是输出YES，否则输出NO
//题解：只要有一个数字不为完全平方数，则结果为YES
//例 4 * 16 = 2*2 * 4*4 = 8*8

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            int tmp = sqrt(a[i]);
            if(tmp*tmp!=a[i]) {//判断是否不为完全平方数
                flag = 1;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
