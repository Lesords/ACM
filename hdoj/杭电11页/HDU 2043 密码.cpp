#include<iostream>//ac
#include<cstring>
using namespace std;
char a[55];
int cnt[6];
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>a;
		int len = strlen(a),ans = 0;
		memset(cnt,0,sizeof(cnt));//统计密码类别
		if(len<8||len>16) {//长度
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 0;i<len;i++) {
			if(a[i]>='A'&&a[i]<='Z') cnt[1] = 1;
			else if(a[i]>='a'&&a[i]<='z') cnt[2] = 1;
			else if(a[i]>='0'&&a[i]<='9') cnt[3] = 1;
			else cnt[4] = 1;
		}
		for(int i = 1;i <= 4;i++) ans += cnt[i];
		if(ans>=3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
