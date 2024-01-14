#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],b[MAXN],val[MAXN];
int one[105],two[105];
int n,m;
int solve(int num) {
    int left = one[b[1]];
    int right = two[b[1]];
    for(int i = left;i <= right;i++) {
        int book = 0;
        if(a[i]!=b[1]) continue;
        for(int j = 1;j <= num;j++) {
//            if(val[i+j-1]!=0) {
//                book = 1;break;
//            }
            if(i+j-1>n) {
                book = 1;break;
            }
            if(a[i+j-1]!=b[j]) {
                book = 1;break;
            }
        }
        if(!book) {
            return i;
        }
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(one[a[i]]==0) one[a[i]] = i;
        two[a[i]] = i;
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int num;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>b[j];
        }
        int pos = solve(num);
        val[pos] = i;
    }
    for(int i = 1;i <= n;i++) {
        if(!val[i]) continue;
        if(i!=1) cout<<" ";
        cout<<val[i];
    }
    return 0;
}
