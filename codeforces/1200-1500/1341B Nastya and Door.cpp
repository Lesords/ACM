#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先预处理峰顶的前缀和，然后计算所有k段的最大值，并记录起点
//初始化起点为1！！！

const int MAXN = 2e5+5;
int a[MAXN],sum[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,maxx = 0,l = 1;//l初始化为1（如果有0的时候，为起点）
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        for(int i = 1;i <= n;i++) {//前缀和峰顶数量
            sum[i] = sum[i-1];
            if(i==1||i==n) continue;//跳过首尾
            sum[i] += (a[i]>a[i-1])&&(a[i]>a[i+1]);//简便判断峰顶
        }
        for(int i = 1;i <= n-k+1;i++) {//从起点开始计算
            int tmp = sum[i+k-2]-sum[i];//长k，忽略首尾
            if(tmp>maxx) {//更新较大值
                l = i;maxx = tmp;
            }
        }
        //maxx为峰顶数量，输出分割后的数量需 +1
        cout<<maxx+1<<" "<<l<<"\n";
    }
    return 0;
}
