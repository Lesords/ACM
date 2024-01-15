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

//题解：统计0的数量，如果0的数量为偶数或者为1则必定是BOB赢，否则是ALICE赢
//对于偶数情况的时候，由于原字符串为回文串
//所以ALICE选完一个0之后，BOB选择0对应的位置（镜像位置）
//当只剩最后两个0的时候，当ALICE选完一个0之后，BOB可以直接翻转字符串
//使得ALICE需再选一个0，那么BOB就赢了
//当为奇数情况的时候，ALICE修改了中间的0
//那么对于剩余的偶数0来说，BOB为先手，所以是ALICE赢
//注意：需要特判0的数量为1的情况

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int zero = 0,n;
        cin>>n>>s;
        for(int i = 0;i < s.size();i++) {
            if(s[i]=='0') zero++;
        }
        if(zero%2==0||zero==1) {
            cout<<"BOB\n";
        }
        else cout<<"ALICE\n";
    }
	return 0;
}
