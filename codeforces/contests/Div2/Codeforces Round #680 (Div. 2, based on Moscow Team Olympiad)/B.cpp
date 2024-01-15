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
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==d&&b==c) cout<<a+b<<"\n";
        else cout<<max(a+b,c+d)<<"\n";//最小的可能值
        //可认为有100 a+b，和100个 c+d，然后去较大值即可
    }
	return 0;
}
