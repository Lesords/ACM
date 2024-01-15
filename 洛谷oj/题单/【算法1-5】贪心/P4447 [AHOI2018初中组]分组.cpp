#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：贪心+二分
//首先将所有队员按照实力值从小到大排序
//然后在所有组中选择最合适的组，如果没找到，则新建一个组
//利用二分来查找组，如果有多个组都符合条件，则越后面的越优（后面的晚建，大小可能更小

const int MAXN = 1e5+5;
int a[MAXN],q[MAXN],siz[MAXN];//q记录 满足 当前组的实力值，siz记录当前组的大小
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//从小到大排序
    int top = 0;
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(q+1,q+top+1,a[i])-q;//寻找第一个满足条件的位置
        while(pos+1<=top&&q[pos+1]==a[i]) pos++;//如果后面有组也满足，则选择后面组
        if(q[pos]==a[i]) siz[pos]++,q[pos]++;//当前组满足条件，则更新组的信息（q需加1，要连续
        else q[++top] = a[i]+1,siz[top] = 1;//新建一个组
        //下一个需要的值都为当前值+1！！！
    }
    int ans = INF;
    for(int i = 1;i <= top;i++) {//取最小长度即为结果
        ans = min(ans, siz[i]);
    }
    cout<<ans;
    return 0;
}
