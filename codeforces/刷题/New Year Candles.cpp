#include<iostream>//ac
using namespace std;
int main() {
	int a,b,ans = 0,cnt = 0;
	cin>>a>>b;
	while(a) {
		ans++;//���
		cnt++;//��Ǿɵ���������
		if(cnt==b) a++,cnt = 0;//����һ���µģ��������
		a--;//�������
	}
	cout<<ans<<endl;
	return 0;
} 
