#include<iostream>//ac
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int sum[MAXN];
int main() {
    int n,ans = 0,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int a,b,c;
        scanf("%d-%d %d", &a,&b,&c);
        sum[a] += c;
        if(sum[a]>num) {
            num = sum[a];
            ans = a;
        }
    }
    cout<<ans<<" "<<num;
    return 0;
}
