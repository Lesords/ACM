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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n,tmp;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<(n-1)/2<<endl;
    int big = n,small = 1,flag = 1;
    for(int i = 1;i <= n;i++) {
        if(flag) cout<<a[big--]<<' ';
        else cout<<a[small++]<<' ';
        flag ^= 1;
    }
	return 0;
}
