#include<iostream>//ac
using namespace std;
int main() {
	int k,n = 1;//初始值为1
	cin>>k;
	double s = 1;//初始值为1
	while(s<=k) {
		n++;
		s += 1.0/n;//总和++ 
	}
	cout<<n<<endl;
	return 0;
} 
