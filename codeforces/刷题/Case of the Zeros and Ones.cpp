#include<iostream>//ac
#include<algorithm> 
using namespace std;
char a[200005];
int main() {
	int n,zero = 0,one = 0;
	cin>>n>>a;
	for(int i=0;i<n;i++) {
		if(a[i]=='0') zero++;
		else one++;
	}//0 1总会相邻，n -（最小数量）*2
	//或者abs(zero-one) 
	cout<<n-(min(one,zero))*2<<endl;
	return 0;
}
