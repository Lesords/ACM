#include<iostream>//ac
using namespace std;
int main() {
	int n,ans = 0;
	cin>>n;
	while(n) {
		if(n&1) ans++;
		//�����������ƶ�����2��
		//��ֻ��Ҫ�жϳ��ֶ��ٸ���Ч��1
		n >>= 1;
	}
	cout<<ans<<endl;
	return 0;
} 
