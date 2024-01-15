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
const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<ll> st;
        for(int i = 1;i <= n+2;i++) cin>>a[i];
        sort(a+1,a+n+3);//从小到大排序
        ll sum = 0;
        for(int i = 1;i <= n;i++) {//计算前n个的和，并放入set容器中
            sum += a[i];
            st.insert(a[i]);//只要前n个！！！
        }
        if(sum==a[n+1]||sum==a[n+2]) {//若为后两个任意一个的和
            for(int i = 1;i <= n;i++) {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        else {
            //选后两个中的一个，再判断是否可以删除前n个数中的某个一个得到另外一个
            ll tsum = sum+a[n+1];
            ll dis = tsum-a[n+2],flag = 0;
            if(dis>0&&st.count(dis)) {
                for(int i = 1;i <= n+1;i++) {
                    if(a[i]==dis&&!flag) {
                        flag = 1;continue;
                    }
                    cout<<a[i]<<" ";
                }
                cout<<"\n";
                continue;
            }
            tsum = sum+a[n+2];
            dis = tsum - a[n+1],flag = 0;
            if(dis>0&&st.count(dis)) {
                for(int i = 1;i <= n+2;i++) {
                    if(i==i+1) continue;
                    if(a[i]==dis&&!flag) {
                        flag = 1;continue;
                    }
                    cout<<a[i]<<" ";
                }
                cout<<"\n";
                continue;
            }
            cout<<"-1\n";
        }
    }
	return 0;
}
