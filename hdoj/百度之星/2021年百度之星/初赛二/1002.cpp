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

//题解：贪心
//从小到大排序，以 前面一个，左边界 为起点，开始遍历找目的值

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int a[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        set<int> st;
        int minn = INF, maxx = -INF;
        scanf("%d %d",&n,&k);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
        }
        sort(a+1,a+n+1);
        int last = a[1]-k;
        st.insert(last);
        for(int i = 2;i <= n;i++) {
            //不能小于 a[i]-k
            for(int j = max(last+1,a[i]-k);j<=a[i]+k;j++) {
                if(st.find(j)==st.end()) {
                    last = j;
                    st.insert(j);
                    break;
                }
            }
        }
        cout<<st.size()<<"\n";
    }
	return 0;
}
