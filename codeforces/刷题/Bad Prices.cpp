#include<iostream>
using namespace std;
int main() {
	int T,a[150005]; cin>>T;
	while(T--) {
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>=2;i--) {//�Ӻ�ʼ�ж� 
			if(a[i]<a[i-1]) {//����һ������ǰ��С��bad��
				ans++;
				a[i-1]=a[i];//С������ǰ��
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
