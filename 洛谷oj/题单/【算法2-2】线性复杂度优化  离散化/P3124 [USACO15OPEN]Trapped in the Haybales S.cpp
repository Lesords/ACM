#include<iostream>//ac
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

//题解：由于只能选择一个干草捆来加固！！！
//所以可以按照干草捆的位置进行从小到大排序
//然后枚举在右边不加固的情况下，左边每个位置需要加固多少，取较小值
//接着枚举在左边不加固的情况下，右边每个位置需要加固多少，取较小值
//注意：可能会有负数，所以需要与0取max

const int MAXN = 1e5+5;
struct node {
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.pos < b.pos;//从小到大排序
    }
}a[MAXN];
int main() {
    int n,b;
    cin>>n>>b;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val>>a[i].pos;
    }
    sort(a+1,a+1+n);//排序
    int ans = INF,pos = 0;//寻找第一个大于b的位置
    for(int i = 1;i <= n;i++) {
        if(a[i].pos>b) {
            pos = i;break;//找到就结束
        }
    }
    int l = pos-1,r = pos;//左右位置以b为标准，l为b的左边，r为b的右边
    for(;l >= 1;l--) {//枚举左边需要加固的位置
        //注意是距离，两个位置差即可，不需要+1！！！
        while(r<=n&&a[r].pos-a[l].pos>a[r].val) r++;//寻找右边不需要加固的位置
        if(r>n) break;//越界，则结束
        //蓄力为a[r].pos-a[l].pos，与a[l].val的差值即为加固的大小
        ans = min(ans, max(0, (a[r].pos-a[l].pos)-a[l].val));//记得与0取max
    }
    l = pos-1, r = pos;
    for(;r <= n;r++) {//枚举右边需要加固的位置
        while(l>=1&&a[r].pos-a[l].pos>a[l].val) l--;//寻找左边不需要加固的位置
        if(l<1) break;//越界，则结束
        ans = min(ans, max(0, (a[r].pos-a[l].pos)-a[r].val));
    }
    if(ans==INF) cout<<"-1\n";//等于INF，表示无解
    else cout<<ans;
    return 0;
}
