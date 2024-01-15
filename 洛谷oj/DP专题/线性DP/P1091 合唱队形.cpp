#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：求出对应的最长上升子序列和最长下降子序列
//然后最遍历一次判断可组成的最多人数
//注：可以全为上升或全为下降

const int MAXN = 105;
int a[MAXN],up[MAXN],down[MAXN];
//up[i]: 从1到i的最长上升子序列
//down[i]: 从i到n的最长下降子序列
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],up[i]=down[i]=1;//初始化都为1
    //最长上升子序列
    for(int i = 2;i <= n;i++) {//从前到后判断
        for(int j = 1;j < i;j++) if(a[i]>a[j]) {//j前i后
            up[i] = max(up[i],up[j]+1);//更新
        }
    }
    //最长下降子序列
    for(int i = n-1;i >= 1;i--) {//从后到前判断
        for(int j = n;j > i;j--) if(a[i]>a[j]) {//i前j后
            down[i] = max(down[i],down[j]+1);//更新
        }
    }
    int ans = 1;//不需要对称！！！
    for(int i = 1;i <= n;i++) ans = max(ans,up[i]+down[i]-1);//取最多人数
    cout<<n-ans<<endl;//相减即为出队人数
    return 0;
}
