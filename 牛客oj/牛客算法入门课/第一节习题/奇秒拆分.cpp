#include<iostream>//ac
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		int ans = 0;//ͳ������
		cin>>n;
		for(int i = 1;i <= n;i++) {
			if(n%i==0) {//���Ա�����
				//���ܳ����ظ��ģ�����ִֻ��һ��
				ans++;
				n /= i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
