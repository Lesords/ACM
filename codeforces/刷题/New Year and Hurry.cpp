#include<iostream>//ac
using namespace std;
int main() {
	int n,k,ans = 0;
	cin>>n>>k;
	for(int i=5,j=i;i<=240-k;j+=5,i+=j) {//iΪ��ʱ��,jΪÿ��ʱ��
		ans++;
		if(ans>=n) break;
	}
	cout<<ans<<endl;
	return 0;
} 
