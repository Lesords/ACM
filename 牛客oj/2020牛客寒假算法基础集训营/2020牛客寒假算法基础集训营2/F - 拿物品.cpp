#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����ͬһ����Ʒ����������
//����ÿ�ζ��ǿ�������Լ���Է��÷ֵĲ�
//�����ţţ��˵�õ�һ����Ʒ�÷� + ai���Է�����bi��
//��ÿ��ѡȡ����ƷӦ���� ai + bi �ϴ����Ʒ

const int MAXN = 2e5 + 5;
int ans_1[MAXN],ans_2[MAXN],A[MAXN];
struct node{
	int val,num;
	friend bool operator < (node a,node b) {
		return a.val > b.val;//�Ӵ�С����
	}
}a[MAXN];
int main() {
	int n,one = 0,two = 0,tmp;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>A[i];
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		a[i].num = i;
		a[i].val = tmp+A[i];//!!!
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		if(i%2) ans_1[++one] = a[i].num;
		else ans_2[++two] = a[i].num;
	}
	for(int i = 1;i <= one;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_1[i];
	}
	cout<<endl;
	for(int i = 1;i <= two;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_2[i];
	}
	cout<<endl;
	return 0;
}
