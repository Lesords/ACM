#include<iostream>//ac
#include<string>
using namespace std;
int a[30];
int main() {
	string s;
	int minn = 999,maxx = 0,flag = 0;
	cin>>s;
	for(int i = 0;i < s.size();i++) a[s[i]-'a']++;//��¼���ִ���
	for(int i = 0;i < 26;i++) {
		if(!a[i]) continue;//0Ϊû���֣�����
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	maxx = maxx-minn;
	for(int i = 2;i*i <= maxx;i++) {
		if(maxx%i==0) {//�������������ӣ�����Ϊ����
			flag = 1;break;
		}
	}//0��1Ҳ��Ϊ����������
	if(flag||maxx<=1) cout<<"No Answer\n0\n";
	else cout<<"Lucky Word\n"<<maxx<<"\n";
	return 0;
}
