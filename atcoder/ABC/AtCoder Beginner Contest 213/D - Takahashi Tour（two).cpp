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

//��⣺������������ʵ����dfs�Ĺ���
//����ǰ�����пɷ��ʵ㶼������֮�󣬻ص���һ����
//���������ʵ���ǻ���
//��¼����Ļ���ֻ��Ҫ�ٶ�Ӧ��dfs���� push_back ����
//����Ҫ�����ٵ���

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
vector<int> g[MAXN];//vector������Թ�������
vector<int> ans;//��¼�������
void dfs(int pos,int f) {//posΪ��ǰ�ڵ㣬fΪ���ڵ�
    ans.push_back(pos);
    for(int i = 0;i < g[pos].size();i++) {//��������ָ���
        int now = g[pos][i];
        if(f==now) continue;//�������ڵ�����
        dfs(now, pos);
        ans.push_back(pos);
        //ֱ�ӻ��ݵ�ʱ��������һ�ν�����ɣ�����
        //����Ҫ�ٱ���һ�����ж��Ƿ�Ϊ��
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i < n;i++) {
        int u,v;
        scanf("%d%d", &u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //vector������Թ�������
    for(int i = 1;i <= n;i++) sort(g[i].begin(), g[i].end());
    dfs(1,-1);
    for(int i = 0;i < ans.size();i++) {
        if(i!=0) printf(" ");
        printf("%d", ans[i]);
    }
	return 0;
}
