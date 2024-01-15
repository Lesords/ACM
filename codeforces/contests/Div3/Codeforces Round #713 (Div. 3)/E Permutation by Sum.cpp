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

//题解：由于结果是个排列，所以所有的数字都是不同的
//那么可以提前计算对应区间长度内 最小值 和最大值
//然后利用s和最小值的差，均匀的分配给区间的内的数字，使区间内的数字互不相同
//可以先利用平均数来分配，然后根据余数来从高到低分配，保证不会重复
//即从1 - k，到 1+avg - k+avg
//然后标记以及出现过的数字，再填充剩余位置的数字

const int MAXN = 1e5+5;
//等差求和公式
int High(int n,int k) {//求最大值，范围 n-k+1 -> n
    return ((2*n-k+1)*k)/2;
}
int Lower(int k) {//求最小值，范围 1 - k
    return (1+k)*k/2;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int Max = High(n,r-l+1);//取最大值
        int Min = Lower(r-l+1);//取最小值
        if(s<Min||s>Max) {//不在范围内则无解
            cout<<"-1\n";
            continue;
        }
        vector<bool> vis(505,0);//用来标记数字是否使用
        vector<int> ans(505,0);//用来保存结果序列
        int dif = s - Min,num = r-l+1;//dif为差，num为区间的数量
        int avg = dif/num,val = 1,rest = dif%num;//val为起始数字
        //avg为平均分配的数量，rest为剩余需要分配的数量
        for(int i = l;i <= r;i++) {//区间内的数字分配，从1开始
            ans[i] = val+avg;//需添加上分配的平均值
            val++;
        }
        int pos = r;//从高到低补剩余的值
        while(rest--) {
            ans[pos--]++;//一个个增加即可
        }
        for(int i = l;i <= r;i++) vis[ans[i]] = 1;//标记已经出现的值
        for(int i = 1;i <= n;i++) {//从头到尾补充剩余的位置
            if(i==l) {//若为l，则直接移到r，并跳过
                i = r;
                continue;
            }
            for(int j = 1;j <= n;j++) {//从头开始寻找
                if(vis[j]) continue;//跳过已出现过的
                ans[i] = j;//填充i位置的答案
                vis[j] = 1;//标记数字
                break;//找到就结束，不然会重复寻找！！！
            }
        }
        for(int i = 1;i <= n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
