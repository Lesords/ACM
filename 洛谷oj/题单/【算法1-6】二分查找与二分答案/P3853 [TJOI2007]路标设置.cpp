#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e7+5;
bool mark[MAXN];//bool耗时短，用来记录已经放置路标的位置
int len,n,k,tmp;
bool check(int mid) {//mid是最小“空旷指数”值
    int last = 0,num = 0;//last是上一个路标的位置，num为放置的路标数量
    for(int i = 1;i < len;i++) {//第一个和最后一个已有路标，忽略
        if(mark[i]) last = i;//已放置过的
        else if(i-last==mid) last = i,num++;//距离大于mid，放置路标
    }
    return num <= k;//放置的路标是否小于题目要求
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>len>>n>>k;
    for(int i = 1;i <= n;i++) cin>>tmp,mark[tmp]++;
    int l = 0,r = len,ans;
    while(l<=r) {//二分
        int mid = (l+r)/2;
        if(check(mid)) ans = mid,r = mid-1;//尽量取小
        else l = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
