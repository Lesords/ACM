#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	string a,b,c;
	cin>>t;
	while(t--) {
		cin>>a>>b>>c;
		int flag = 0;
		for(int i = 0;i < a.size();i++) {
			if(c[i]!=a[i]&&c[i]!=b[i]) {
				flag = 1;break;
			}//a��b��a��c��һ���ַ�ʱ��ͬ�ļ���
		}
		cout<<(flag?"NO":"YES")<<endl;
	}
	return 0;
}
