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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：先将原来的数分成三份，然后one值占用一份，two值占用两份，对应数量一致
//然后再判断是否有剩余没分清除的，给对应的值再多加一份

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int one=0,two = 0;
        one = two = n/3;// 1/2分，对应数量一致
        int rest = n%3;
        if(rest==1) one++;//如果还剩余一个，one++
        else if(rest==2) two++;//还剩两个，two++
        cout<<one<<" "<<two<<'\n';
    }
    return 0;
}
