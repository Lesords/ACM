#include<iostream>//ac
using namespace std;
int solve(int n) {//ȡ�෴��
	int ans = 0;
	while(n) {//���Զ�ɾ��ǰ����
		ans = ans*10+n%10;
		n /= 10;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<n+solve(n)<<endl;
	return 0;
}
