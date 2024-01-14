#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const int MAXN = 205;
int g[MAXN][MAXN],a[MAXN];
int main() {
    memset(g,-1,sizeof(g));
    int n,m,k;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = c;
    }
    cin>>k;
    int cnt = 0,cost = INF,index = 0;
    for(int i = 1;i <= k;i++) {
        int num,sum = 0,flag = 0;
        set<int> st;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>a[j];
            if(st.count(a[j])) {
                flag = 1;
            }
            else st.insert(a[j]);
            if(flag) continue;
            if(j==1) {
                if(g[0][a[j]]==-1) {
                    flag = 1;continue;
                }
                sum += g[0][a[j]];
            }
            else {
                int val = g[a[j]][a[j-1]];
                if(val==-1) {
                    flag = 1;continue;
                }
                sum += val;
            }
        }
        if(st.size()<n) continue;
        if(flag) continue;
        if(g[0][a[num]]==-1) continue;
        sum += g[0][a[num]];
        cnt++;
        if(sum<cost) {
            cost = sum;
            index = i;
        }
    }
    cout<<cnt<<"\n"<<index<<" "<<cost<<"\n";
    return 0;
}
