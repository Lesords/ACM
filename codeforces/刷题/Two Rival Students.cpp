#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int t,n,x,a,b;
	cin>>t;
	while(t--) {
		cin>>n>>x>>a>>b;
		//������Ϊn-1,��ʼ����Ϊabs(a-b)�����ӵľ���Ϊx
		cout<<min(n-1,abs(a-b)+x)<<endl;
	}
	return 0;
}
