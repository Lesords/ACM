#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n,ans_a=0,ans_b=0;
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>ch;
		if(ch=='A') ans_a++;
		else ans_b++; 
	}
	if(ans_a>ans_b) cout<<"Anton"<<endl;
	else if(ans_a==ans_b) cout<<"Friendship"<<endl;
	else cout<<"Danik"<<endl;
	return 0;
} 
