#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int t,a,b;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		int tmp = abs(a-b);//ȡ����ֵ��Ȼ�󰴴Ӵ�С�ݼ�
		int cnt = tmp/5;
		tmp %= 5;
		cnt += tmp/2;
		tmp %= 2;
		cnt += tmp;
		//Ҳ�ɰ����һ�µ���Ϊ2�������Ϊ��cnt/5 + (cnt%5+1)/2��
		cout<<cnt<<endl;
	}
	return 0;
}
