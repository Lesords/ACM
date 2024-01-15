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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        string a,b;
        cin>>a>>b;
        int lena = a.size();
        int lenb = b.size();
        int ans = 0;
        for(int i = 0;i < lena;i++) {
            for(int j = i;j < lena;j++) {//枚举a字符的两端位置
                for(int k = 0;k < lenb;k++) {//b字符只需要起点，大小已经限制了
                    int len = j-i+1,flag = 0;
                    if(len+k-1>=lenb) continue;
                    for(int ss = 0;ss < len;ss++) {
                        if(a[i+ss]!=b[k+ss]) {
                            flag = 1;break;
                        }
                    }
                    if(!flag) {
                        ans = max(ans,len);
                    }
                }
            }
        }
        cout<<lena+lenb-ans*2<<"\n";
    }
	return 0;
}
