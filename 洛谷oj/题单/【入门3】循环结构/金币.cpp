#include<iostream>//ac
using namespace std;
int main() {
	int n,ans = 0,money = 1,tmp = 0;
	cin>>n;//��ʼ�������ܺͶ�Ϊ0��ǮΪ1
	while(n--) {
		++tmp;//����++
		ans += money;//������Ǯһ��ʱ��Ǯ++����������
		if(tmp==money) money++,tmp = 0;
	}
	cout<<ans<<endl;
	return 0;
}
