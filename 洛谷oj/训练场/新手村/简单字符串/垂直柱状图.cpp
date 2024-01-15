#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int book[30];
char row[500];//字符最多只有400个，所以最多输出400行
int main() {
	string a;
	int maxx = 0;
	for(int i = 1;i <= 4;i++) {//总输入只有四行
		getline(cin,a);
		for(int i = 0;i < a.size();i++) {
			if(a[i]>='A'&&a[i]<='Z')//记录字符，更新出现次数最大值
				book[a[i]-'A']++,maxx = max(maxx,book[a[i]-'A']);
		}
	}
	for(int i = 1;i <= maxx;i++) {//总共maxx行
		for(char c = 'Z';c >= 'A';c--) {
			if(book[c-'A']>=i) {//判断每行末尾
				row[i] = c;break;
			}
		}
	}
	for(int i = maxx;i >= 1;i--) {
		for(char c = 'A'; c <= 'Z';c++) {
			if(book[c-'A']>=i) cout<<"* ";//当前字符出现i次及以上时
			else cout<<"  ";
			if(row[i]==c) {//到达行末
				cout<<endl;break;
			}
		}
	}
	for(char i = 'A';i <= 'Z';i++) cout<<i<<' ';
	return 0;
}
