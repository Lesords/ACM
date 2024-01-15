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
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int main() {
    ll t,n,k,l[3],r[3];
    cin>>t;
    while(t--) {
        cin>>n>>k>>l[1]>>r[1]>>l[2]>>r[2];
        if(max(l[1],l[2])<=min(r[1],r[2])) {//有相交
            ll tmp = min(r[1],r[2])-max(l[1],l[2]);//相交大小
            tmp *= n;//相交总大小
            ll need = k-tmp;//剩余需要的大小
            if(need<=0) {//小于0表示当前以满足条件
                cout<<"0\n";continue;
            }
            ll dis = max(r[1],r[2])-min(l[1],l[2]);//单个区间长度
            dis *= n;//总长度
            if(need<=dis-tmp) cout<<need<<'\n';//区间可满足
            else cout<<(dis-tmp)+(need-(dis-tmp))*2<<'\n';//需额外区间
        }
        else {//无相交
            ll space = max(l[1],l[2])-min(r[1],r[2]),ans = INF;
            ll dis = max(r[1],r[2])-min(l[1],l[2]);
            //space为中间间隔，dis为区间长
            for(int i = 1;i <= n;i++) {//判断需要操作几个片段！！！
                ll tmp = space * i;
                if(dis*i>=k) ans = min(ans,tmp+k);//原区间可满足
                else ans = min(ans,tmp+dis*i+(k-dis*i)*2);//需要额外区间
            }
            cout<<ans<<'\n';
        }
    }
	return 0;
}
