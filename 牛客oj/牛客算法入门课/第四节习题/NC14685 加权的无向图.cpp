#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
int fa[MAXN];
int find(int u) {//Ѱ������
	return fa[u]==u?u:fa[u]=find(fa[u]);
}//·��ѹ��
int main() {
	int n,m,u,v,ans = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) fa[i] = i;//��ʼ��
	for(int i = 1;i <= m;i++) {
		cin>>u>>v;
		fa[find(u)] = fa[find(v)];//�ϲ�����
	}
	for(int i = 1;i <= n;i++) if(fa[i]==i) ans++;
	cout<<ans-1;//ȥ��һ����������
	return 0;
}
