#include<iostream>//ac
#define ll long long
using namespace std;

//��⣺����������ֵΪ 3^0 3^1 3^2 ������ 3^(n-1)
//��ôҲ����˵��ɵ�����������ֵ�����൱��Ϊ3���Ƶ�ֵ
//��ô��kС��ֵ��Ϊ k ��Ӧ�Ķ���������ɵ� ������ֵ

int main() {
	int t,k;
	cin>>t;
	for(int i = 1;i <= t;i++){
		cin>>k;
		ll ans = 0,tmp = 1;//��ʼ��
		while(k) {
			if(k&1) ans += tmp;//��ǰ������λΪ1
			tmp *= 3;//���¶�Ӧ����λ��ֵ
			k >>= 1;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
