#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x,y;
        cin>>n>>x>>y;
        if(n==2) {
            cout<<x<<' '<<y<<endl;
            continue;
        }
        int dis = y-x,cha=y-x,beginn,add,endd = INF;
        for(int i = 1;i <= dis;i++) {
            if(dis%i) continue;
            int num = dis/i+1;
            if(num>n) continue;
            int tx = x,ty = y;
            while(num<n) {
                if(tx-i>0) tx -= i,num++;
                else ty += i,num++;
            }
            if(ty<endd) {
                beginn = tx,add = i,endd = ty;
            }
        }
        if(endd==INF) continue;
        for(int i = beginn;i <= endd;i += add) {
            if(i!=beginn) cout<<' ';
            cout<<i;
        }
        cout<<endl;
    }
	return 0;
}
