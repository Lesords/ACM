#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：双指针，根据标记数组book来记录区间内出现不同画师的数量
//如果l-r区间内的数量满足m，更新答案
//然后左指针移动，并删除l位置对应画师的数量然后判断总数是否需要修改；
//否则右指针移动，增加对应r位置的画师的数量并判断是否需要修改总数

const int MAXN = 1e6+6;
int a[MAXN],book[2005];//book标记画师的数量
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    int l = 1,r = 1,cnt = 1,ll,rr,ans = MAXN;//ans初始化为较大值
    //l和r为在起点，并更新book数组
    book[a[1]]++;
    while(r<=n) {//右指针还在范围，则继续
        if(cnt==m) {//满足条件m
            if(r-l+1<ans) {//判断是否需要更新答案
                ans = r-l+1;
                ll = l,rr = r;
            }
            book[a[l]]--;//左指针对应位置修改
            if(book[a[l]]==0) cnt--;//判断总数是否需要操作
            l++;//移动左指针
        }
        else {
            book[a[++r]]++;//右指针的位置修改
            if(book[a[r]]==1) cnt++;//若为第一个，则修改总数
        }
    }
    cout<<ll<<" "<<rr<<"\n";
    return 0;
}
