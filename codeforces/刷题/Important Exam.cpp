#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans;
int main() {
	int n,m,book[6],b[1005];
	char a[1005][1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<m;i++) {
		memset(book,0,sizeof(book));
		for(int j=1;j<=n;j++) {
			if(a[j][i]=='A') book[1]++;
			else if(a[j][i]=='B') book[2]++;
			else if(a[j][i]=='C') book[3]++;
			else if(a[j][i]=='D') book[4]++;
			else book[5]++;
		}
		sort(book+1,book+6);
		ans+=b[i]*book[5];
	}
	cout<<ans<<endl;
	return 0;
}
