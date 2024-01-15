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
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a,b,c;
int check(int val) {
    int num = 0;
    while(val) {
        num++;;
        val /= 10;
    }
    return num;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int num = 0,numa,numb;
        cin>>a>>b>>c;
        while(c) {
            num = num*10+1;
            c--;
        }
        numa = numb = num;
        while(check(numa)<a) {
            numa *= 10;
        }
        while(check(numb)<b) {
            numb *= 7;
        }
        cout<<numa<<" "<<numb<<"\n";
    }
	return 0;
}
