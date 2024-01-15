// Problem: P3808 【模板】AC自动机（简单版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3808
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-16 17:00:14

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
const int MOD = 1e9+7;
const double pi = acos(double(-1));

const int MAXN = 1e6+5;
char s[MAXN];
namespace AC {
    int tr[MAXN][26], tot;
    int e[MAXN], fail[MAXN];//e记录节点对应的字符串出现次数
    queue<int> q;
    void init() {
        for(int i = 0;i <= tot;i++) {//把用过的节点清空
            memset(tr[i], 0, sizeof tr[i]);
            fail[i] = e[i] = 0;
        }
        tot = 0;
    }
    void insert(char *s) {//插入一个字符串（建字典树）
        int u = 0;
        int len = strlen(s + 1);
        for(int i = 1;i <= len;i++) {//字符串从1开始记录
            if(!tr[u][s[i] - 'a']) {
                tr[u][s[i] - 'a'] = ++tot;
            }
            u = tr[u][s[i] - 'a'];
        }
        e[u] ++;
    }
    void build() {//建fail树
        for(int i = 0;i < 26;i++) if(tr[0][i]) q.push(tr[0][i]);
        while(q.size()) {
            int u = q.front();q.pop();
            for(int i = 0;i < 26;i++) {
                if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i],q.push(tr[u][i]);
                else tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    int query(char *t) {//t为需要查询的字符串
        int u = 0, res = 0;
        for(int i = 1;t[i];i++) {//字符串从位置1开始匹配
            u = tr[u][t[i] - 'a'];
            for(int j = u;j && e[j] != -1;j = fail[j])
                res += e[j], e[j] = -1;
        }
        return res;
    }
}

int main() {
	AC::init();
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>(s+1);
		AC::insert(s);
	}
	AC::build();//记得建fail树！！！
	cin>>(s+1);
	cout<<AC::query(s);
    return 0;
}
