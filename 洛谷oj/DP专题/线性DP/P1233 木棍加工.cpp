#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：线性dp
//将所有棍子按照先长度从大到小，在宽度从大到小排序
//那么对于所有棍子来说，按照排序后的顺序选择的话长度都可以满足
//所以可以忽略长度，只关注宽度即可
//即对于所有宽度求 最长上升子序列 （宽度比前面大的重新准备，其他的可和前面一起加工）
//有nlogn和n^n两种做法求 最长上升子序列

const int MAXN = 5e3+5;
struct node{
    int l, w;
    friend bool operator < (node a,node b) {
        if(a.l==b.l) return a.w > b.w;  //长度一致，则根据宽度从大到小
        return a.l > b.l;               //根据长度从大到小
    }
}a[MAXN];
int b[MAXN],dp[MAXN];//b存储排序后的宽度，dp[i]为以i为结尾的最长上升子序列的大小
vector<int> ans;//存储最长上升子序列中对应位置的最大值
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].l>>a[i].w;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        b[i] = a[i].w;
    }
//    nlogn做法
//    for(int i = 1;i <= n;i++) {
//        //为空，或者可以直接放在最后位置
//        if(ans.empty()||b[i]>ans.back()) ans.push_back(b[i]);
//        else {
//        //否则找出可以满足条件的最小位置，然后替换对应值
//            *lower_bound(ans.begin(),ans.end(), b[i]) = b[i];
//        }
//    }
//    cout<<ans.size();

    int ans = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;                  //记得初始化
        for(int j = 1;j < i;j++) {  //遍历所有前面的情况
            if(b[i]>b[j]) {         //比前面小即满足条件
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
