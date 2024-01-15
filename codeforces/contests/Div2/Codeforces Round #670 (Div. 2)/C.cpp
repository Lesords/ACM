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

//��⣺dfs�������ģ�������ֻ��һ������ѡ����һ��ɾ������
//�����轫 ������ �е�Ҷ�ڵ����ӵ� ������ ��ȥ

const int MAXN = 1e5+5;
vector<int> g[MAXN];//��ͼ
int fa[MAXN],num[MAXN],n,minn,cent1,cent2,son;
//fa�����Ӧ��ĸ��ڵ㣬num��¼��ǰ�ڵ��֧����������+��������ڵ㣩
//minn��¼ɾ����ǰ��ɻ�õ����ڵ��֧��
//cent1Ϊ��һ�����ģ�cent2Ϊ�ڶ������ģ�sonΪ ������ ��Ҷ�ڵ�
void dfs(int dot,int f) {//�������ĺ͸��ڵ�
    int maxx = 0;//��¼ɾ��dot��ɻ�õ�����֦��
    num[dot] = 1;//����Ϊһ����
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==f) continue;//�������ڵ�
        fa[now] = dot;
        dfs(now,dot);
        maxx = max(maxx,num[now]);//���� ����֦��
        num[dot] += num[now];//���·�֧����
    }
    maxx = max(maxx,n-num[dot]);//���ڵ����ϵķ�������
    if(maxx<minn) cent1 = dot,minn = maxx,cent2 = 0;//ֻ��һ�����ģ�cent2��Ϊ0
    else if(maxx==minn) cent2 = dot;
}
void dfs2(int dot,int f) {//Ѱ�������ĵ�Ҷ�ڵ�
    if(g[dot].size()==1) {//�ҵ�Ҷ�ڵ�ֱ�ӷ���
        son = dot;return;//����son��ֵ
    }
    for(int i = 0;i < g[dot].size();i++) {
        if(g[dot][i]==f) continue;//�������ڵ�
        dfs2(g[dot][i],dot);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i < n;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cent1 = cent2 = 0,minn = INF;//��ʼ��
        dfs(1,0);//��ʼ�ڵ�ĸ��ڵ���Ϊ0
        if(!cent2) {//ֻ��һ������
            cout<<cent1<<" "<<g[cent1][0]<<"\n"<<cent1<<" "<<g[cent1][0]<<"\n";
        }
        else {
            if(fa[cent2]!=cent1) swap(cent1,cent2);
            dfs2(cent2,cent1);//��cent2Ϊ�����ģ����򽻻����ߵ�ֵ
            cout<<fa[son]<<" "<<son<<"\n"<<cent1<<" "<<son<<"\n";
        }
        for(int i = 1;i <= n;i++) g[i].clear(),fa[i] = 0;//���ԭͼ�����ڵ�ֵ
    }
	return 0;
}
