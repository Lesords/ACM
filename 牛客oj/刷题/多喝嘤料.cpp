#include<iostream>//ac
using namespace std;
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans = n,tmp;
		m = n;//nƿ m��
		while(n>=3||m>=4) {
			tmp = n/3 + m/4;//�û���õ�����
			n %= 3, m %= 4;//ʣ���
			ans += tmp, n += tmp, m += tmp;//���¸��Ӻ�ƿ������
		}
		cout<<ans<<endl;
	}
	return 0;
}
