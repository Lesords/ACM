#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：将题目转化为，alice选偶数加分，bob选奇数扣分
//那么总分为0即为平局，大于0则alice赢，小于0则bob赢
//那么最优的方法即从大到小排序，每次选择最大值（自己不加分都不让对方加分）

const int MAXN = 2e5+5;
int a[MAXN];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n,cmp);//从大到小排序
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            if(i%2) {//奇数即为alice的回合
                if(a[i]%2==0) ans += a[i];//偶数加分
            }
            else {//否则为bob的回合
                if(a[i]%2) ans -= a[i];//奇数扣分
            }
        }
        if(ans==0) cout<<"Tie\n";
        else if(ans>0) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
}
