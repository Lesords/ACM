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

//��⣺ֱ�Ӹ�������ģ��
//��ǰ���е㶼������֮���ٱ���ԭ���ĸ��ڵ��ʱ��
//���ڸ��ڵ������֮��ͻ�ѱ�ɾ�ˣ�����
//�����ٴα������ڵ��ʵ�ʵ�Ӱ�첻���´α���ֱ�Ӻ����������бߣ�

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
vector<int> ans;
priority_queue<int, vector<int>, greater<int> > g[MAXN];//���
int vis[MAXN],fa[MAXN];//vis��¼�Ƿ���ʹ���fa��¼��ǰ��ĸ��ڵ㣨����һ�η���ʱ�ĸ��ڵ�
void dfs(int pos) {
    ans.push_back(pos);//��¼��
    int flag = 0;//flag��¼�Ƿ��е�δ����
    //��vector��t����Ϊ��һֱ������
    //�������ȶ��в��ᣬ��Ϊ��ֱ�Ӱѱ�ɾ��
    while(!g[pos].empty()) {
        int now = g[pos].top();
        g[pos].pop();//�ѷ��ʹ��ı�ֱ��ɾ��������
        if(vis[now]) continue;//�����ѷ��ʵĵ�
        vis[now] = 1;//��ǵ�ǰ���ѷ���
        fa[now] = pos;//��¼��Ӧ��ĸ��ڵ�
        dfs(now);
        flag = 1;//���ڱ�δ����
    }
    if(pos==1&&flag==0) return;//��ǰΪ1��������ָ���δ���ʣ�ֱ�ӷ���
    if(flag==0) dfs(fa[pos]);//����ֱ�Ӱ�������ģ�⣬������һ��
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i < n;i++) {
        int u,v;
        scanf("%d%d", &u,&v);
        g[u].push(v);
        g[v].push(u);
    }
    vis[1] = 1;//������
    dfs(1);
    for(auto v:ans) {
        printf("%d ", v);
    }
	return 0;
}
