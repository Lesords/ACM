#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int t,n,tmp;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		int sub = 0,flag = 0,book = 0;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			if(tmp!=a[i]) {
				if(book == 2) flag = 1;//�ڶ����ֲ����
				if(flag) continue;
				if(book) {//��һ���ֲ����
					if((tmp-a[i])!=sub) flag = 1;
				}
				else {//��û�޸Ĺ�
					sub = tmp - a[i],book = 1;
					if(sub < 0) flag = 1;//a��������b����
				}
			}
			else if(book==1) book++;//�Ѿ��޸Ĺ�
		}
		flag?cout<<"NO\n":cout<<"YES\n";
	}
	return 0;
}
