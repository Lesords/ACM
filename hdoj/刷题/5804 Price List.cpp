#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//题意：每天可以买多个商店的产品，可以少算不能多算
//题解：累加所有店铺的总和，判断当前值是否超过总和即可
//超过了输出1，否则输出0
//注意：记账的数量范围为1e18，所以用ll！！！

const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        ll tmp,sum = 0;//sum累加和
        for(int i = 1;i <= n;i++) scanf("%lld", &tmp),sum+=tmp;
        for(int i = 1;i <= m;i++) scanf("%lld", &a[i]);//注意ll
        for(int i = 1;i <= m;i++) {
            printf("%d", a[i]>sum);//判断是否大于总和即可
        }
        puts("");
    }
    return 0;
}
