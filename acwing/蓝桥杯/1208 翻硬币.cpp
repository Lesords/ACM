#include<iostream>//ac
#include<string>
using namespace std;
char change(char ch) {//��תӲ��
	return ch=='o'?'*':'o';
}
int main() {
	string a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 0;i < a.size();i++) {//ֱ�ӱ���
		if(a[i]!=b[i]) {//������һ���ķ�ת����Ӳ��
			ans++;
			a[i] = change(a[i]);
			a[i+1] = change(a[i+1]);
		}
	}
	cout<<ans;
	return 0;
}
