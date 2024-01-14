#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN = 1e4+5;
int main() {
    int n;
    double m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        double val;
        cin>>val;
        if(val<m) {
            cout<<"On Sale! ";
            printf("%.1f\n", val);
        }
    }
    return 0;
}
