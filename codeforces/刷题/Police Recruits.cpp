#include<iostream>//ac
using namespace std;
int main() {
	int n,tmp,ans = 0,man = 0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>tmp;
		if(tmp!=-1) man+=tmp;//招警察
		else man?man--:ans++;//抓罪犯，有警察则--，无则ans++
	}
	cout<<ans<<endl;
	return 0;
} 
