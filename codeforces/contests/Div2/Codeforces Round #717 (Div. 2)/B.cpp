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

//题解：异或满足交换律，所以可以求异或前缀和
//然后对于最终的异或结果可以分成两种：两个部分和三个部分
//对于两个部分可以直接求所有数的异或和，若为0，则可行（a^a = 0）
//对于三个部分直接枚举两个边界，然后利用异或前缀和来计算三个区间是否相同

const int MAXN = 2e3+5;
const int MOD = 1e9+7;
int pre[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,sum = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(i==1) sum = tmp;
            else sum ^= tmp;
            pre[i] = pre[i-1]^tmp;
        }
        int ans = sum==0;//sum==0来判断是否可以分成两个部分
        for(int i = 1;i <= n;i++) {//枚举两个边界
            for(int j = i+1;j <= n;j++) {
                //只要有一种情况成立即可，利用|来计算
                ans |= (pre[i]==(pre[j]^pre[i])) && (pre[i]==(pre[n]^pre[j]));
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
/*
1
6
2 3 1 3 2 0

2
4
2 3 1 10
3
1 1 10

2
5
1 1 1 1 2
5
1 2 2 1 1
*/
