#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于题目需要最小的距离，所以两列的火柴最后的位置
//一定是根据高度排名一一对应的
//那么利用结构体存储高度和下标，然后根据高度排序
//最后得到的两个序列即为一一对应的序列
//那么将第二个序列的下标pos指向第一个序列中同一位置的下标pos即可
//最后生成的序列结果即为：第二个序列中的数最后需要移动到哪个位置
//那么最后的移动次数即为这个序列的逆序对，用归并排序求解即可

const int MAXN = 1e5+5;
const int MOD = 1e8-3;//模数
struct node{
    int hei,pos;
    friend bool operator < (node a,node b) {
        //根据高度排序
        if(a.hei!=b.hei) return a.hei < b.hei;
        return a.pos < b.pos;
    }
}one[MAXN],two[MAXN];
int a[MAXN],b[MAXN];//a记录最后的结果序列，b为归并过程的中间数组
int n,ans;//ans为交换次数
void Merge(int l,int r) {
    if(l==r) return;                        //只有一个元素，直接返回
    int mid = (l+r)/2;                      //取中间位置
                                            //先划分后合并
    Merge(l,mid);                           //左区间
    Merge(mid+1,r);                         //右区间
    int s1 = l,s2 = mid+1,e1 = mid,e2 = r;  //区间[s1,e1]与区间[s2,e2]对比
    int cnt = l;                            //记录数值的起点
    while(s1<=e1&&s2<=e2) {                 //两个区间都有数据时
        if(a[s1]<=a[s2]) b[cnt++] = a[s1++];//左小右大选左边
        else b[cnt++] = a[s2++], ans = (ans+(e1-s1+1))%MOD;
                                            //否则选右边，并计算左边大的数量
    }
    while(s1<=e1) b[cnt++] = a[s1++];       //左区间有剩余则补其
    while(s2<=e2) b[cnt++] = a[s2++];       //右区间有剩余则补其
    for(int i = l;i < cnt;i++) a[i] = b[i]; //将数组b的值移到a数组
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>one[i].hei,one[i].pos = i;
    for(int i = 1;i <= n;i++) cin>>two[i].hei,two[i].pos = i;
    sort(one+1,one+1+n);
    sort(two+1,two+1+n);
    for(int i = 1;i <= n;i++) {             //记录第二个序列需要移动到的位置
        a[two[i].pos] = one[i].pos;
    }
    Merge(1,n);                             //归并排序求逆序对
    cout<<ans;
    return 0;
}
