#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a;
	while(getline(cin,a)) {//����һ��
		if(a=="#") break;
		int ans = 0;
		for(int i = 0;i < a.size();i++) {
			if(a[i] == ' ') continue;//�ո��޷�
			ans += (i+1)*(a[i]-'A'+1);//λ�� * �ַ�ֵ
		}
		cout<<ans<<endl;
	}
	return 0;
}
