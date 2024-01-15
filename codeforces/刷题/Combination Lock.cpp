#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
char a[1005],b[1005];
int main() {
	int T,ans = 0;
	cin>>T>>a>>b;
	for(int i=0;i<T;i++) {
		int num_1 = a[i] - '0';
		int num_2 = b[i] - '0';
		ans += min(min(num_2+10-num_1,num_1+10-num_2),abs(num_1-num_2));
		//直接减，或则两个其中一个加10再减
	}
	cout<<ans<<endl;
	return 0;
} 
