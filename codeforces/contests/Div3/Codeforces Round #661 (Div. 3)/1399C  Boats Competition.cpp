#include<iostream>//ac
#include<cstdio>
#include<cstring>
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
const int MAXN = 55;
int a[MAXN],b[MAXN],book[MAXN*2],t,n;
bool cmp(int a,int b) {
    return a>b;
}
int check(int num) {//计算num队的数量
    int l = 1,r = num-1,ans = 0;
    while(l<=r) {
        if(l+r==num) {
            if(l==r) {//相同取一半
                ans += book[l]/2;
                return ans;
            }
            ans += min(book[l],book[r]);
            l++,r--;
        }
        else if(l+r<num) l++;//小了右移
        else if(l+r>num) r--;//大了左移
    }
    return ans;
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        int minn = INF,maxx = 0,ans = 0;
        memset(book,0,sizeof(book));
        for(int i = 1;i <= n;i++) {
            cin>>a[i],book[a[i]]++;
            minn = min(minn,a[i]);
            maxx = max(maxx,a[i]);
        }
        maxx *= 2;
        for(int i = minn;i <= maxx;i++) {//暴力，从小遍历到大
            ans = max(ans,check(i));
        }
        cout<<ans<<endl;
    }
	return 0;
}

