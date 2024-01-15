#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：对于给定数组q来说，只会出现两个情况，q[i] == q[i-1] 或者 q[i] > q[i-1]
//因为q数组为前缀最大值，所以不存在 q[i] < q[i-1]
//那么对应情况 q[i] > q[i-1] 来说，我们可以知道当前位置 a[i] 必定为 q[i]
//因为前面的肯定都为 <= q[i-1]，那么要想 q[i] > q[i-1]，只能在i位置放置 大值 ！！！
//那么对于 q[i] == q[i-1] 的情况：
//最小字典序为 选择最小的还未选择的 数字
//最大字典序为 选择略小于前一个固定值 的数字
// 因为对于相等的区间来说，后面的数字都不会大于 前一个确定的q[i] （第一个q[i]）

const int MAXN = 2e5+5;
int a[MAXN];//记录原数组
void solve(vector<int> &q,bool minn) {
    //q用引用，直接修改数据，无需返回,minn判断当前是否为最小字典序排列
    set<int> hav;//hav记录还未选择的数字
    for(int i = 1;i <= (int)q.size();i++) {//将所有的数字先放入hav容器中
        hav.insert(i);
    }
    for(int v: q) {//已经确定的即为已经选择的，从hav容器中删除
        if(v!=-1) hav.erase(v);
    }
    int lastVal = -1;//记录上一个提前确定的值
    for(int &i : q) {//利用引用，可以直接修改容器中的值
        if(i==-1) {
            set<int>::const_iterator it;//只查看不能修改（可移动指针）
            if(minn) {//求最小值，则取hav容器首即可
                it = hav.begin();
            }
            else {//否则利用lower_bound寻找 略小于 lastVal 的数字
                it = --hav.lower_bound(lastVal);
            }
            i = *it;//修改当前的数值
            hav.erase(i);//删除i数字（已确定
        }
        else lastVal = i;//更新提前确定的值
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        vector<int> res1(n,-1),res2(n,-1);//初始化
        for(int i = 1;i <= n;i++) {//遍历原数组
            if(a[i]>a[i-1]) {//若当前位置大于前一个位置，可确定当前位置的值
                res1[i-1] = res2[i-1] = a[i];//下标需-1，res1和res2从0开始计数
            }
        }
        solve(res1, true);//求最小字典序的排列
        solve(res2, false);//求最大字典序的排列
        for(int v: res1) {//输出对应的结果
            cout<<v<<" ";
        }
        cout<<"\n";
        for(int v: res2) {
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
