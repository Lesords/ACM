#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 32010;
struct node{
	ll s,e;
	friend bool operator < (node a,node b) {
		//�յ��С�����������Ӵ�С����
		if(a.e!=b.e) return a.e < b.e;
		return a.s > b.s;
	}
}a[MAXN];
int main() {
	int n,ans = 1;
	ll l,r,last;//lastΪ��һ���е�λ��
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>l>>r;//r�ǳ���!!!
		a[i].s = l;
		a[i].e = l+r;
	}
	sort(a+1,a+1+n);
	last = a[1].e;//��һ���е�һ���ڵ�һ�������λ��
	for(int i = 2;i <= n;i++) {
		
		//���������û�ж��������Բ����еģ�����
		//�������Ϊ�� ����ǰ�� λ��
		//���ĳ��� ǰ��λ��Ϊ�� ������
		
		//��������㣡����
		if(last>a[i].s) continue;//�����е�������
		//�ٴ��е�ǰ�������һ��λ��
		last = a[i].e;ans++;
	}
	cout<<ans;
	return 0;
}
