#include<iostream>//ac
#include<cstdio>
#include<string>
//#define hhh
using namespace std;
int main() {
	int t;
	#ifdef hhh
	freopen("dat.in","r",stdin);
	freopen("dat.out","w",stdout);
	#endif
	cin>>t;
	getchar();
	while(t--) {
		string a,ans;
		getline(cin,a);
		int begin = 0,len = a.size() - 1;
		ans = "";
		for(int i = 0;i <= len;i++) {
			//判断最后一位是否为空格还是字符（pe点）
			if(i == len&&a[i] != ' ') {
				for(int j = i;j >= begin;j--) ans += a[j];
			}
			else if(a[i] == ' '||(i == len&&a[i] == ' ')) {
				for(int j = i - 1;j >= begin;j--)
					ans += a[j];
				ans += ' ';
				begin = i + 1;//更新起点
			}
		}
		cout<<ans<<endl;
	} 
	#ifdef hhh
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
} 
