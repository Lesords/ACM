#include<iostream>
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
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
struct node{
    int index,siz;
    friend bool operator < (node a,node b) {
        return a.siz < b.siz;
    }
}num[MAXN];
vector<int> a[MAXN];
int book[MAXN],ans[MAXN],hav[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        for(int i = 1;i <= m;i++) {
            a[i].clear();
            book[i] = 0;
            hav[i] = 0;
        }
        for(int i = 1;i <= m;i++) {
            int tmp;
            cin>>tmp;
            for(int j = 1;j <= tmp;j++) {
                int tt;
                cin>>tt;
                a[i].push_back(tt);
                book[tt]++;
            }
            num[i].index = i;
            num[i].siz = tmp;
        }
        sort(num+1, num+1+m);
        int flag = 0;
        for(int i = 1;i <= m;i++) {
            int ind = num[i].index;
            int val = 0,cnt = INF;
            for(int j = 0;j < a[ind].size();j++) {
                int now = a[ind][j];
                if(hav[now]>=ceil(m/2.0)) continue;
                if(book[now]&&book[now]<cnt) {
                    cnt = book[now];
                    val = now;
                }
            }
            if(cnt==INF) {
                flag = 1;
                break;
            }
            ans[ind] = val;
            hav[val]++;
            book[val]--;
        }
        if(flag) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i = 1;i <= m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
