#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105],b[105];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) cin>>b[i];
		sort(a+1,a+1+n);//a��bû����ͬ�ģ���������֮��
		sort(b+1,b+1+n);//a+b�϶�Ҳû����ͬ��
		for(int i = 1;i <= n;i++) {
			if(i!=1) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		for(int i = 1;i <= n;i++) {
			if(i!=1) cout<<' ';
			cout<<b[i];
		}
		cout<<endl;
	}
	return 0;
}
