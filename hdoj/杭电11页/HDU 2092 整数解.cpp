#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n,m;
	while(cin>>n>>m&&n+m) {//n��m��Ϊ0�Ž��������� 
		if((int)(n+sqrt((n*n)- 4*m))/2==(n+sqrt((n*n)- 4*m))/2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
