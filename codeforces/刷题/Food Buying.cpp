#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		ll ans = 0,cnt = 0;//��ʼ��Ϊ0
		while(n>=10) {//����10
			cnt += n/10;//���ֵ�Ǯ
			n %= 10;//ʣ���޷����ֵ�Ǯ
			ans += cnt*10;//���ѵ�Ǯ
			n += cnt;//���Ϸ��ص�Ǯ
			cnt = 0;//����
		}
		cout<<ans+n<<endl;//ans+ʣ���Ǯ
	}
	return 0;
}
