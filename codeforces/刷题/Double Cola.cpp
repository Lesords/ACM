#include<iostream>//ac
using namespace std;
int main() {
	char a[][8] = {"Sheldon","Leonard","Penny","Rajesh",
	"Howard"};
	int n,cnt = 5,num = 1;
	cin>>n;
	if(n<=5) {//5ÒÔÄÚ
		cout<<a[n-1]<<endl;
		return 0;
	}
	while(cnt<n) {
		num *= 2;
		cnt += num * 5;
	}
	n -= (num-1) * 5 - 0.5;//ÕÒµ½num-1
	cout<<a[n/num]<<endl;
	return 0;
}
