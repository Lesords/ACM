#include<iostream>//ac
using namespace std;
const int maxn = 3e4+5;
int a[maxn];
int main() {
	int n,t,pos = 1;
	cin>>n>>t;
	for(int i=1;i<=n-1;i++) cin>>a[i];
	while(pos < t) {//��Ŀ��λ��ǰ��
		pos += a[pos];//�ƶ�λ��
	}
	if(pos==t) cout<<"YES"<<endl;//���Ե���ָ��λ��
	else cout<<"NO"<<endl;//������ָ��λ��
	return 0;
}
