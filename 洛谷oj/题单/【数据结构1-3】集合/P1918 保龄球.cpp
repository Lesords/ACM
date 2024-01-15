#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val < b.val;//按值从小到大排序
    }
}a[MAXN];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].pos=i;//记录数据和下标
    sort(a+1,a+n+1);//排序
    cin>>m;
    while(m--) {
        int num;
        cin>>num;//需要击倒的数量
        int l = 1,r = n,ans = 0;
        while(l<=r) {//二分查找答案
            int mid = l+(r-l)/2;
            if(a[mid].val==num) {//值为num的对应pos即为答案
                ans = a[mid].pos;
                break;
            }
            else if(a[mid].val<num) l = mid+1;//太小了，l扩大
            else r = mid-1;//太大了，r收缩
        }
        cout<<ans<<endl;
    }
    return 0;
}
