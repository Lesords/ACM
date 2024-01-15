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
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 1e3+5;
const int MOD = 1e9+7;
struct node{
    ll val;
    int pos;
}a[MAXN],b[MAXN];
int main() {
    int n,cnt = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].pos=i;
    while(cnt<n) {//cnt为离开队列的人数
        ll index = 0,time = INF;//time为当前需要多少回合有人失去耐心
        for(int j = 1;j <= n-cnt;j++) {
            ll tmp = a[j].val/j;
            if(a[j].val%j) tmp++;//有余数需要多一回合！！！
            if(tmp<time) {
                time = tmp;
                index = j;
            }
        }
        int num = n-cnt,tmp = 0;
        for(int i = 1,rk = 1;i <= num;i++) {
            //（time-1）次i，第time次只需要减rk！！！
            //因为只有第time才有人排名变了
            a[i].val -= i*(time-1)+rk;
            if(a[i].val<=0) {//当前的人失去耐心，rk不需要增加
                cnt++;
                cout<<a[i].pos<<" ";
            }
            else {
                rk++;//当前的人没有失去耐心，rk才需要增加
            }
        }
        for(int i = 1;i <= num;i++) {//利用b数组记录剩余的人
            if(a[i].val<=0) continue;
            b[++tmp] = a[i];
        }
        for(int i = 1;i <= tmp;i++) a[i] = b[i];//然后再移到a数组
    }
	return 0;
}
