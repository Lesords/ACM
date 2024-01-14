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
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int val[10] = {0, 7, 27, 41, 49, 63, 78, 108};
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n,sum = 0;
    	cin>>n;
    	for(int i = 1;i <= n;i++) {
    		int tmp;
    		cin>>tmp;
    		sum += val[tmp];
    	}
    	if(sum>=120) {
    		sum -= 50;
    	}
    	else if(sum >= 89) {
    		sum -= 30;
    	}
    	else if(sum >= 69) {
    		sum -= 15;
    	}
    	cout<<sum<<"\n";
    }
    return 0;
}