#include<iostream>//ac
#include<string>
using namespace std;
bool f(string a,string b) {
	if(a.size()>b.size()) return 1;//aλ������b
	else if(a.size()<b.size()) return 0;//aλ��С��b
	for(int i = 0;i < a.size();i++) {//λ����ͬ����Ҫ�Ƚ�
		if(a[i]>b[i]) return 1;//a��ֵ����b
		else if(a[i]<b[i])return 0;//a��ֵС��b
	}
	return 0;
}
int main() {
	int n,num;
	string ans,tmp;
	cin>>n;
	for(int i = 1;i <= n;i++) {//ֱ�ӱ�����ʵʱ�������ֵ����
		cin>>tmp;
		if(f(tmp,ans)) ans = tmp, num = i;//tmp>ansʱ����
	}
	cout<<num<<endl<<ans<<endl;
	return 0;
}
