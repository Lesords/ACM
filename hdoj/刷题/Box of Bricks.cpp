#include<iostream>//ac
#include<cmath>
using namespace std;
int a[55];
int main() {
	int n,flag = 0;
	while(cin>>n&&n) {
		int sum = 0,cnt = 0;
		if(flag++) cout<<endl;//pe��
		for(int i = 1;i<=n;i++) {
			cin>>a[i];
			sum += a[i];
		}
		sum /= n;//ǽ�ĸ߶�
		for(int i = 1;i<=n;i++)
			cnt += abs(sum-a[i]);//ÿ��ǽ��ƽ���߶ȵĲ��
		cout<<cnt/2<<endl;//�ƶ���ʱ��һ�߶�һ����
	}
	return 0;
} 
