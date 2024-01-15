#include<iostream>//ac
#include<algorithm>
#define LL long long
using namespace std;

//题解：归并排序求逆序对
//在合并的时候判断左边有多少个数大于当前右边的数，然后累加即可

const int MAXN = 5e5+5;
int a[MAXN],b[MAXN],n;//a为原数组，b为中间数组
LL ans;//结果偏大
void Merge(int l,int r,int ll,int rr) {//[l,r]与[ll,rr]区间对比
    int cnt = l-1;//中间数组的位置
    int tl = l,tll = ll;//记录起始点
    while(l<=r&&ll<=rr) {//若两个都不为空，则继续对比
        if(a[l]<=a[ll]) b[++cnt] = a[l++];//左小右大，添加左边的值
        else b[++cnt] = a[ll++], ans += (r-l+1);
        //否则添加右边的值，并计算左边的大值数量
    }
    while(l<=r) b[++cnt] = a[l++];//补充左边剩余值
    while(ll<=rr) b[++cnt] = a[ll++];//补充右边剩余值
    for(int i = tl;i <= rr;i++) a[i] = b[i];//b数组转移到a数组
}
void mergesort(int l,int r) {//归并排序
    if(l==r) return;//只剩一个元素，无需操作
    int mid = (l+r)/2;
    mergesort(l,mid);//先划分，后合并
    mergesort(mid+1,r);
    Merge(l,mid,mid+1,r);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    mergesort(1,n);//原数组输出记得删掉！！！
    cout<<ans;//输出逆序对即可
    return 0;
}
