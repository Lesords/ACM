#include<iostream>//ac
using namespace std;
int a[105];
int main() {
	int t,n,d,ans,tmp;
	cin>>t;
	while(t--) {
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 2;i <= n;i++) {
			if(!a[i]) continue;//Ϊ0ʱ����
			tmp = min(d/(i-1),a[i]);//ȡСֵ
			a[1] += tmp;//��ӿ���ת�Ƶ�ֵ
			d -= tmp*(i-1);//�۳���Ӧ����
			if(!d) break;//����Ϊ0ʱ����
		}
		cout<<a[1]<<endl;
	}
	return 0;
}
