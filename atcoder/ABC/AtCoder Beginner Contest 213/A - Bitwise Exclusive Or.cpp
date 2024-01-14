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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;

//题解：范围只有0-255，所以直接暴力每个数，判断是否有对应异或值符合条件的即可

int main() {
    int a,b;
    cin>>a>>b;
    for(int i = 0;i <= 255;i++) {
        if((a^i)==b) {
            cout<<i<<"\n";
            break;
        }
    }
	return 0;
}
