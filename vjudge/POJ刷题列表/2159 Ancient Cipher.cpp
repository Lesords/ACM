#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//���⣺���ַ����е� ͬһ�ֵ��ַ� ת��� ����һ�����ַ�
 
//��⣺ֻ��Ҫ�ж������ַ����и��ַ����ֵĴ����Ƿ����һ��
//���ԵĻ��������ת��

int one[30],two[30];
int main() {
	string a,b;
	cin>>a>>b;
	for(int i = 0;i < a.size();i++) one[a[i]-'A']++;
	for(int i = 0;i < b.size();i++) two[b[i]-'A']++;
	sort(one, one+26);
	sort(two, two+26);
	int flag = 0;
	for(int i = 0;i < 26;i++) {
		if(one[i] != two[i]) {
			flag = 1;break;
		}
	}
	cout<<(flag?"NO":"YES")<<endl;
	return 0;
}
