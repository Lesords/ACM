#include<iostream>//ac
using namespace std;
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		if(n>=m) cout<<m<<endl;//�������,ֱ�����װ����
		else {
			if(m%n==0) cout<<n*(m/n)*(m/n)<<endl;//��ƽ��
			else {
				//ƽ��֮�󣬶������װ����һ����������伴��
				int mod = m%n;//�������װ��������������
				int res = n - mod;//ʣ���ƽ�ֵķ�����
				m -= mod;//ȥ�����װ����
				cout<<mod*(m/n+1)*(m/n+1)+res*(m/n)*(m/n)<<endl;
			}
		}
	}
	return 0;
}
