#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
int e[15];//�������Ȩֵ
struct node {
	int num,w;
	friend bool operator < (node a, node b) {
		if(a.w!=b.w) return a.w>b.w;//����Ȩֵ
		return a.num < b.num;//���ű��
	}
}p[MAXN];
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= 10;i++) cin>>e[i];//����Ȩֵ
	for(int i = 1;i <= n;i++) {
		cin>>p[i].w;
		p[i].num = i;
	}
	sort(p+1,p+n+1);//δ�Ӷ���ֵ ���������
	for(int i = 1;i <= n;i++) {//��ǰi��Ϊd[i]���
		p[i].w += e[(i-1)%10+1];
	}
	sort(p+1,p+n+1);//�ٴ�����
	for(int i = 1;i <= k;i++) {//���k����
		if(i!=1) cout<<' ';
		cout<<p[i].num;
	}
	return 0;
}
