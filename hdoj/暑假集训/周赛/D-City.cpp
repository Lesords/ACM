#include<iostream>//ac
using namespace std;
int dis[10005],ans[100005],a[100005],b[100005];
int find(int x) {
	return dis[x]==x?x:dis[x]=find(dis[x]);
}
int main() {
	int n,m,x,y,num;
	ios::sync_with_stdio(false);
	while(cin>>n>>m) {
		num=n;
		for(int i=0;i<=n;i++) dis[i]=i;//���㿪ʼ��ʼ�������� 
		for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
		for(int i=m;i>=2;i--) {//m��ʼ�����鼯������ 
			x=find(a[i]),y=find(b[i]);
			if(x!=y) num--,dis[x]=y;//�����������ֺϲ�,num-- 
			ans[i]=num;
		}
		//ans�������ÿ�� ���ϲ� ǰ״̬�ĳ�����
		//����ֻ��Ҫ������2���� 
		ans[m+1]=n;//���һ������Ϊn
		for(int i=2;i<=m+1;i++) cout<<ans[i]<<endl;
	}
	return 0;
} 
