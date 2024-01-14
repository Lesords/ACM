#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题意：将字符串中的 同一种的字符 转译成 另外一个的字符
 
//题解：只需要判断两个字符串中各字符出现的次数是否可以一致
//可以的话，则可以转译

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
