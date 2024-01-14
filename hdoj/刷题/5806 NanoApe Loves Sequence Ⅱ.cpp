#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：可以将题目转换为：取一个区间，并且这个区间内至少有k个数组大于等于m
//那么可以记录所有大于等于m的值的位置，当大于等于m值的个数大于k个时
//取当前位置往前 k-1 个的位置pos（当前为第k个，前面只需取k-1个）
//使当前位置为右区间，则 1-pos 的位置都可以为左边界，数量为 pos 个

const int MAXN = 2e5+5;
int pos[MAXN];//pos记录 大于等于m数字 的位置
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,k,top = 0;//top表示当前 大于等于m数字 的数量
        ll ans = 0;
        scanf("%d%d%d", &n,&m,&k);
        for(int i = 1;i <= n;i++) {
            int tmp;
            scanf("%d", &tmp);
            if(tmp>=m) {//大于等于m，则用pos存储位置
                pos[++top] = i;
            }
            if(top>=k) {//满足k个时
                ans += pos[top-k+1];//取前 k-1 个的位置，累加
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
