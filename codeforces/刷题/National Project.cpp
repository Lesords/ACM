#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	ll t,n,g,b;
	cin>>t;
	while(t--) {
		cin>>n>>g>>b;
		//g>bʱ�����Ϊn
		//g<bʱ��ֻ��Ҫ����õ��������ɣ�����һ������Ҫ��
		ll tmp = ceil(n/2.0);//��������·���賤��
		ll ans = floor(tmp/g)*(g+b);//ans�����ã���������
		if(tmp%g==0) ans -= b;//���պ����꣬�򻵵Ŀ��Բ���
		else ans += tmp%g;//�����޺õ�
		//������Ҫn�죬�Է����ֺõ��������ڻ�������������
		cout<<max(n,ans)<<endl;
	}
	return 0;
}
