#include<iostream>//ac
#include<string>
using namespace std;
int a[30] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main() {
	string s;
	getline(cin,s);//����һ��
	int ans = 0;
	for(int i = 0;i < s.length();i++) {
		if(s[i]>='a'&&s[i]<='z') ans += a[s[i]-'a'];
		if(s[i]==' ') ans++;//�����жϣ�����ֵ��ַ�
	}//�� '\n' �� '\r'
	cout<<ans<<endl;
	return 0;
}
