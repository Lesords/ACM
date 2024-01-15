// Problem: A. Regular Bracket Sequences
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1574/problem/0
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-20 22:35:23

#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题解：构造
//首先输出一种情况，每个括号都是独立的，即n个()
//那么对于剩下的n-1个情况，可以是将一个() 插入 剩余的 n-1 个() 当中即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	//n个独立的()
    	for(int i = 1;i <= n;i++) cout<<"()";
    	cout<<"\n";
    	for(int i = 1;i < n;i++) {//剩余的只有n-1个()
    		for(int j = 1;j < n;j++) {//i位置多嵌套一个()
    			cout<<"(";
    			if(j==i) cout<<"()";
    			cout<<")";
    		}
    		cout<<"\n";
    	}
    }
    return 0;
}
