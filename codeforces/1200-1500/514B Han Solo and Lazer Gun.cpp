#include<iostream>//ac
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

//题解：由于数据范围只有100，所以暴力判断每个冲锋队队员是否被击杀
//若没有被击杀，则在剩余的冲锋队队员中判断斜率相同的一同击杀

const int MAXN = 1e3+5;
struct node{
    int x,y;
};
vector<node> v;
int vis[MAXN];//记录是否被击杀
int main() {
    int n,x,y,ans = 0;
    cin>>n>>x>>y;
    for(int i = 1;i <= n;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});//记录所有冲锋队队员的位置
    }
    for(int i = 0;i < n;i++) {
        if(vis[i]) continue;//跳过已击杀的
        ans += vis[i] = 1;//更新状态和结果
        int disx = v[i].x-x;
        int disy = v[i].y-y;//计算差值
        for(int j = i+1;j < n;j++) {
            int tmpx = v[j].x-x;
            int tmpy = v[j].y-y;//计算差值
            if(disx*tmpy==disy*tmpx) vis[j] = 1;//斜率相同则一同击杀
            //判断斜率可将除先转换为乘，然后再判断
        }
    }
    cout<<ans;
    return 0;
}
