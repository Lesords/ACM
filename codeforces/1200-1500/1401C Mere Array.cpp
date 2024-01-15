#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：由于gcd为最小值的值可以交换，那么也就是说为 最小值的倍数 的值位置可任意交换
//所以将原数组排序，判断是否有 不为倍数 的值不在指定位置即可

const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,minn = INF,flag = 0;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
            minn = min(minn, a[i]);//记录最小值
        }
        sort(b+1,b+1+n);//排序
        for(int i = 1;i <= n;i++) {
            //位置错误并且不为minn的倍数即为无解
            if(a[i]!=b[i]&&a[i]%minn) {
                flag = 1;break;
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}
