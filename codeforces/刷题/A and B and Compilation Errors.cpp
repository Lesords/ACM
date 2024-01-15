#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e5 + 5;
int a[MAXN],b[MAXN],c[MAXN];
int main() {
	int T,tmp,num_1 = 0,num_2 = 0;
	cin>>T;
	for(int i = 1;i <= T;i++) cin>>a[i];
	for(int i = 1;i <= T-1;i++) cin>>b[i];
	for(int i = 1;i <= T-2;i++) cin>>c[i];
	sort(a+1,a+T+1);
	sort(b+1,b+T);
	sort(c+1,c+T-1);
	for(int i = 1;i <= T;i++) {
		if(a[i]!=b[i]&&!num_1) num_1 = a[i];//a有b没有
		if(b[i]!=c[i]&&!num_2) num_2 = b[i];//b有c没有
		if(num_1&&num_2) break;
	}
	cout<<num_1<<endl<<num_2<<endl;
	return 0;
} 
