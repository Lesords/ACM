#include<iostream>
using namespace std;
int main() {
	int a,b,min,max;
	cin>>a>>b;
	if(a>b) {
		min=b,max=a;
	}
	else{
		min=a,max=b;
	}
	cout<<min<<' '<<(max-min)/2<<endl;
	return 0;
}
