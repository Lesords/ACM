#include<iostream>//ac (ǰ׺��˼��)
#define ll long long
using namespace std;
ll f(ll n) {
	ll ans = 0;
	ans += (n/60)*50;//ʱ������� * ��Чʱ�䣨50��
	n %= 60;//ʣ��ʱ��
	if(n>50) ans += 50;//���ֻ��50
	else ans += n;
	return ans;
}
int main() {
	ll s,e;
	while(cin>>s>>e) {//���ҲΪ��Ч�ۿ�ʱ��
		cout<<f(e)-f(s-1)<<endl;//���ǰһλ
	}
	return 0;
}
