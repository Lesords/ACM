#include<iostream>//ac
using namespace std;
int mid[22] = {0,1},a[22] = {0,2};
int main() {
	int t,tmp;
	//n�����Ƶ����ĵĴ�С��
	//��n-1�����ƶ����������ˣ�Ϊ 2 * mid[n-1]
	//�ٽ���n��pan�ƶ����ڶ�����ȥ��Ϊ 1
	//���n-1�����ƶ����ڶ���ȥ��Ϊ mid[n-1]
	//=> mid[i] = 3 * mid[i-1] + 1; 
	for(int i = 2;i < 21;i++) 
		mid[i] = 3 * mid[i-1] + 1;
	//���һ������n����
	//��n-1�����ƶ����ڶ������У�Ϊ mid[n-1] 
	//Ȼ���n�������Ӵ�С,ֱ���Ƶ���������ȥ��Ϊ 2
	//���n-1�����ƶ�����������ȥ��Ϊ mid[n-1]
	//=> a[i] = 2 * mid[i-1] + 2; 
	for(int i = 2;i < 21;i++)
		a[i] = 2 * mid[i-1] + 2;
	cin>>t;
	while(t--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
}
