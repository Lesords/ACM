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
        int a,b;
        cin>>a>>b;
        cout<<int(ceil(abs(a-b)/10.0))<<endl;
    }
	return 0;
}
