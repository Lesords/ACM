#include<iostream>//ac
#include<cstring>
#include<string>
using namespace std;
char a[55][1005];
int book[30];
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		int sum = 0;//总距离和
		cin>>n>>m;
		string ans = "";//保存DNA串
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 0;i < m;i++) {
			memset(book,0,sizeof(book));
			int tmp = 0;//当前位置出现最频繁的字符的次数
			char ch;
			for(int j = 1;j <= n;j++) {//遍历n个串
				book[a[j][i]-'A']++;//记录各字符出现的次数
				if(book[a[j][i]-'A']>tmp) {
					ch = a[j][i];
					tmp = book[a[j][i]-'A'];
				}
				else if(book[a[j][i]-'A'] == tmp) {
					if(a[j][i]<ch) ch = a[j][i];//字典序
				}
			}
			ans += ch;//添加字符ch到DNA串末尾
			sum += n - tmp;//累加当前位置的Hamming距离
		}
		cout<<ans<<endl<<sum<<endl;
	}
	return 0;
}
