#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],b[MAXN];
ll ans;//���ƫ��
void merge(int s1,int e1,int s2,int e2) {//�ϲ�
	//�����������յ㣬�����������յ�
	int pos = s1,st = s1;//��ʼ����㣡����
	while(s1<=e1&&s2<=e2) {
		if(a[s1]<=a[s2]) b[pos++] = a[s1++];//����������
		else ans += e1-s1+1,b[pos++] = a[s2++];//����������
	}
	while(s1<=e1) b[pos++] = a[s1++];//ʣ������
	while(s2<=e2) b[pos++] = a[s2++];
	//��ֵ��ԭ��������a
	for(int i = st;i <= e2;i++) a[i] = b[i];
}
void sortt(int l,int r) {
	if(l==r) return;//��������
	int mid = l + (r-l)/2;//ȡ�м�ֵ
	sortt(l,mid);//����
	sortt(mid+1,r);//����
	merge(l,mid,mid+1,r);//�ٺϲ�
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sortt(1,n);//�鲢����
	cout<<ans<<"\n";
	return 0;
}
