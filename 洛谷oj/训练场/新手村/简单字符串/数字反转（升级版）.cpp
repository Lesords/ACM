#include<iostream>//ac
#include<string>
using namespace std;
string a;
string solve(int start, int end,int flag) {//flag�ж� ���ַ� ���� ĩ�ַ�
	string ans = "";
	for(int i = end - 1;i >= start;i--) {//�������
		ans += a[i];
	}
	if(flag) while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);
	else //С���������Ƴ�ĩβ 0 �ַ�
		while(ans[ans.size()-1]=='0'&&ans.size()>1)
			ans.erase(ans.size()-1,ans.size());
	return ans;
}
int main() {
	cin>>a;
	int point = 0, percent = 0, divide = 0;
	for(int i = 0;i < a.size();i++) {
		if(a[i]=='.') {//��¼ �� ��λ��
			point = i;break;
		}
		if(a[i]=='/') {//��¼ �� ��λ��
			divide = i;break;
		}
		if(a[a.size()-1]=='%') {
			percent = 1;break;
		}
	}
	if(point) {//С������ flag Ϊ0
		cout<<solve(0,point,1)<<'.'<<solve(point+1,a.size(),0)<<endl;
	}
	else if(divide){
		cout<<solve(0,divide,1)<<'/'<<solve(divide+1,a.size(),1)<<endl;
	}
	else if(percent) cout<<solve(0,a.size()-1,1)<<'%'<<endl;
	else cout<<solve(0,a.size(),1)<<endl;
	return 0;
}
