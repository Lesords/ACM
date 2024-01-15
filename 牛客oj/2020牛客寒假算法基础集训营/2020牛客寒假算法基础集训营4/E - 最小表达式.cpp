#include<iostream>//ac （使用字符串的大数会tle）
#include<string>
using namespace std;
const int MAXN = 5e5+10;
string s;
int book[11],ans[MAXN],Plus;
int main() {
	cin>>s;
	int len = s.size();
	for(int i = 0;i < len;i++) {
		(s[i]=='+')?Plus++:book[s[i]-'0']++;
	}
	if(!Plus) {//没有加号，直接从小到大输出即可
		for(int i = 1;i <= 9;i++)
			for(int j = 1;j <= book[i];j++) cout<<i;
	}
	else {
		int cnt = 0,sum = 0,num = 0,end = 0,pos = 0;
		for(int i = 9;i >= 1;i--) {
			for(int j = 1;j <= book[i];j++) {
				sum += i;
				end++;
				if(num==Plus||end==len-Plus) {
					ans[pos++] = (sum+cnt)%10;
					cnt = (sum+cnt)/10;
					sum = 0;
				}
				num = (num+1)%(Plus+1);
			}
		}
		while(cnt) {//多出来的进位数
			ans[pos++] = cnt%10;
			cnt /= 10;
		}
		for(int i = pos-1;i >= 0;i--) cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
