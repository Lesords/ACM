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

//��⣺���������֪��������Ҫʹ ��Ȩֵ��ı� �Ĺ��׾����ࣨWA
//�������룬Ҳ����˵����Ӧ�� ��ȨֵС�ı� �Ĺ��׾���С
//��ô���Խ��߸��ݱ�Ȩֵ��С��������
//ÿ���жϱ�Ȩ�������߸��ж��ٵ㣬���״�����Ϊ���߳˻�
//����ÿ�μ��� ��ȨֵС ��֮�󣬻Ὣ��ȨֵС�ĺ��Ե�
//��ô���ǿ������Ϊ ��������ɾ��������Ӧ �㼯 �ϲ�����
//��ô����������ǿ����� ���鼯 �����
//���鼯������ÿ�� �㼯 ��������ÿ���ж���һ���ߣ��򽫶�Ӧ�㼯�ϲ�����

//WA˼·������dfs�������б� ��������ĵ� ������
//Ȼ�����б߸��� ��Ȩֵ �Ӵ�С����
//Ȼ��ÿ��ѡȡ һ���ߣ����״���Ϊ��������Ӧ�㼯�ĳ˻�
//Ȼ�󽫶�Ӧ��ָ�������� �ĵ㼯ɾ��������ıߣ�
//WAԭ������Ϊ����ֻ��ɾ�� ��Ӧ���� �ڵ��������������������ڵ�û�и��£�����

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//���ݱ�Ȩֵ��С��������
    }
}edge[MAXN];
int dis[MAXN], siz[MAXN];//dis��¼��Ӧ�����ȣ�siz��¼��Ӧ���Ӽ�����
int getf(int pos) {//Ѱ��pos������
    return pos==dis[pos]?pos:dis[pos] = getf(dis[pos]);
}
void Merge(int a,int b) {//����ϲ�
    a = getf(a);
    b = getf(b);
    if(a!=b) {
        dis[b] = a;//aΪ���ȣ�����
        siz[a] += siz[b];
    }
}
int main() {
    fast;
    int n;
    cin>>n;
    //��ʼ������Ϊ��������Ϊ1
    for(int i = 1;i <= n;i++) dis[i] = i, siz[i] = 1;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i] = {u,v,w};
    }
    sort(edge+1, edge+n);//��С��������
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        node tmp = edge[i];
        tmp.u = getf(tmp.u);//��ȡ��Ӧ������
        tmp.v = getf(tmp.v);
        //���ҵ㼯�˻� ��Ϊ��ǰ�߹��״���
        ans += siz[tmp.u] *1ll* siz[tmp.v] * tmp.w;
        Merge(tmp.u ,tmp.v);//������֮��ϲ�
    }
    cout<<ans<<"\n";
	return 0;
}
