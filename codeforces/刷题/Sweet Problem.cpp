#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int t,a[4];
	cin>>t;
	while(t--) {
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		//���ֵ��������С��֮��ʱ���ɽ�����С����Ϊ��ͬһ���ǹ�
		//����Ļ����������ǹ����Ի�ֳ�������ϵģ�Ҳ�����ܺ�/2
		if(a[3]>=a[1]+a[2]) cout<<a[1]+a[2]<<endl;
		else cout<<(a[1]+a[2]+a[3])/2<<endl;
		//����a[3]-a[2]��ֵ��a[1]���ʹ��
		//Ȼ���ʱa[2]=a[3]��a[1] = a[1] - (a[3]-a[2])
		//��ʱΪ������ͬһ����ͬ����һ�����Է���
	}
	return 0;
}
