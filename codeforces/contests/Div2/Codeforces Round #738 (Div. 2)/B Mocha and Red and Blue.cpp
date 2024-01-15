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

//题解：bfs
//将所有不为 ? 的位置放入队列中
//每次遍历所有指向点，若指向点为 ?，则将其修改为与当前相反的字符
//注意：当所有位置都为 ? 时，将第一个点任意设置一个字符，然后放入队列中！！！

//官方做法：遍历所有位置，判断当前为 ?，且上一个不为 ?，的情况
//将当前的字符 取与上一个字符 不同的字符
//正向和方向各计算一次即可
//若都为 ? 字符，则任意设置第一个位置的字符

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int vis[105];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        memset(vis, 0, sizeof(vis));
        if(n==1) {//只有一个，特判
            if(s[0]!='?') cout<<s<<"\n";
            else cout<<"B\n";
            continue;
        }
        queue<int> q;
        for(int i = 0;i < s.size();i++) {
            if(s[i]!='?') {
                q.push(i);//将所有不为 ?的字符位置放入队列中
            }
        }
        if(q.empty()) {//注意全空情况！！！
            s[0] = 'B';//取任意字符都行
            q.push(0);//全为?，则设置起点为0
        }
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            if(vis[now]) continue;//跳过已计算的
            vis[now] = 1;//标记
            for(int i = -1;i <= 1;i += 2) {//只有两个方向
                int nxt = now + i;
                if(nxt<0||nxt>=s.size()) continue;//越界，跳过
                if(s[nxt]!='?') continue;//跳过不为?的
                s[nxt] = s[now]=='B'?'R':'B';//相反字符
                q.push(nxt);//将当前位置放入队列中
            }
        }
        cout<<s<<'\n';
    }
	return 0;
}
