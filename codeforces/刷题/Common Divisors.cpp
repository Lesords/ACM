#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//���⣺��һ�������ж��ٸ���ͬ����
//��⣺��������Լ����Ȼ���ж�������ж��ٸ�����
//���ӵĸ�����Ϊ��

ll gcd(ll a,ll b) {//�����Լ������int,��ll���ͣ�
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	ll n,num,tmp,ans = 0;
	cin>>n>>num;
	for(int i = 2;i <= n;i++) {
		cin>>tmp;
		num = gcd(num,tmp);//����������������Լ��
	}
	for(ll i = 1;i*1LL*i <= num;i++) {//��int��ת��ll�ͼ���
		if(num%i==0) {//������������
			ans += (i==num/i)?1:2;
		}//����������ͬ��1�������2
	}
	cout<<ans<<endl;
	return 0;
}
