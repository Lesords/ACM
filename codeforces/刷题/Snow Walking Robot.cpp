#include<iostream>//ac
#include<cstring>
#include<map>
#include<string> 
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
//const int MAXN = 1e5 + 5;
//char a[MAXN];

//��⣺ͳ��UDLR��������ȡͬһ�����������Сֵ
//����һ������Ϊ0��������һ���������ֻ��Ϊ1
//Ȼ�����������ҷ������
int main() {
	int t;
	fast;
	cin>>t;
	while(t--) {
		string a;//string���ַ�����죨������a.size()��strlen()��
		cin>>a;
		map<char,int> map; 
		/*for(int i = 0;i < a.size();i++) {
			map[a[i]]++; 
		}*/
		for(char &c :a) map[c]++;//����string��д��
		int min_1 = min(map['U'],map['D']);
		int min_2 = min(map['L'],map['R']);
		if(!min_1) min_2 = min(1,min_2);
		if(!min_2) min_1 = min(1,min_1);
		cout<<2*(min_1+min_2)<<endl;
		for(int i = 1;i <= min_1;i++) cout<<'U';
		for(int i = 1;i <= min_2;i++) cout<<'L';
		for(int i = 1;i <= min_1;i++) cout<<'D';
		for(int i = 1;i <= min_2;i++) cout<<'R';
		cout<<endl;
	}
	return 0;
}
