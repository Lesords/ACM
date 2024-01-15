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
int a[105],book[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,maxx=0;
        cin>>n;
        memset(book,0,sizeof(book));
        for(int i = 1;i <= n;i++) cin>>a[i],book[a[i]]++,maxx=max(maxx,a[i]);
        maxx++;
        int num_m = 0;
        for(int i = 0;i <= maxx;i++) {
            if(book[i]==0) {
                num_m = i;break;
            }
        }
        if(num_m==0&&book[0]==0) {
            cout<<"0"<<endl;
            continue;
        }
        int num_n = 0;
        for(int i = 0;i <= maxx;i++) {
            if(book[i]<=1) {
                num_n = i;break;
            }
        }
        cout<<num_m+num_n<<endl;
    }
	return 0;
}
