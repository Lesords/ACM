#include<iostream>//ac
#include<algorithm>
using namespace std;
//������֮����໥���룬��Ϊ��max-min��*2
//������Ҫ�������ֵ����Сֵ֮��ľ���
int a[5];
int main() {
	int t;
	cin>>t;
	while(t--) {
		for(int i = 1;i <= 3;i++) cin>>a[i];
		sort(a+1,a+4);
		if(a[1]!=a[2]) a[1] += 1;//��߱��м�С
		else if(a[1]==a[2]&&a[2]<a[3]) a[1] += 1,a[2] += 1;
		if(a[2]!=a[3]) a[3] -= 1;//�ұ߱��м��
		else if(a[2]==a[3]&&a[2]>a[1]) a[3] -= 1,a[2] -= 1;
		cout<<(a[3]-a[1])*2<<endl;
	}
	return 0;
}
