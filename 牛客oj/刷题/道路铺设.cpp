#include<iostream>//ac
using namespace std;

//��⣺�Ƚ����ڵ���ȣ��ұߵı�������ʱ����Ҫ������ұ�����

int main() {
	int t,a,tmp = 0,ans = 0;//��ʼ��Ϊƽ��0
	cin>>t;
	while(t--) {
		cin>>a;
		if(a>tmp) ans += a - tmp;//��Ȳ�
		tmp = a;
	}
	cout<<ans<<endl;
	return 0;
}
