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

//题解：为了使结果变大，则偶数位置的值尽量取小，奇数位置的值取大

const int MAXN = 1e5+5;
int a[MAXN],ans[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int pos = 1,num = 0;//pos记录结果序列的当前位置，num为结果
    for(int i = 2;i <= n;i+=2) ans[i] = a[pos++];
    for(int i = 1;i <= n;i+=2) ans[i] = a[pos++];
    for(int i = 2;i < n;i++) {
        if(ans[i]<ans[i-1]&&ans[i]<ans[i+1]) num++;
    }
    cout<<num<<endl;
    for(int i = 1;i <= n;i++) cout<<ans[i]<<' ';
	return 0;
}
