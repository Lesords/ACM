#include<iostream>//ac
#include<string>
using namespace std;
string solve(string a) {
	int sign = 0;
	if(a[0]=='-') sign = 1,a.erase(0,1);//�ж��Ƿ��и���
	string ans = "";
	for(int i = a.size()-1;i >= 0;i--) ans += a[i];//�������
	while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);//���ǰ��0
	if(sign) ans = '-' + ans;//�и����򲹳�
	return ans;
}
int main() {
	string a;
	cin>>a;
	cout<<solve(a)<<endl;
	return 0;
}
