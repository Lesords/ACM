#include<iostream>//ac
using namespace std;
int b,p,k;
int poww(int a,int b) {
	//if(!b) return 1%k;//����ָ��Ϊ0ʱ������
	int ans = 1, bas = a%k;//��ʼֵ�� %k������
	while(b) {
		if(b&1) ans = (bas*ans)%k;
		bas = (bas*bas)%k;//�۳�
		b >>= 1;//����һλ
	}
	return ans%k;//�����%k����ֹ����bΪ0�����������
}
// update
ll poww(ll a, ll b, ll p) {//a��b�η�
	ll ans = 1;//ansΪ���
	while(b) {
		if(b&1) ans = (ans*a)%p;
		a = (a*a)%p;//������ÿ�γ˶�Ҫ���� 
		b >>= 1;
	}
	return ans%p;   
}
int main() {
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<' '<<"mod "<<k<<'='<<poww(b,p);
	return 0;
}
