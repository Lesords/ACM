#include<iostream>//ac
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m,tmp,min = 999;
		cin>>n>>m;
		//复习效率最高就是只复习最差的一门课
		while(n--) {
			cin>>tmp;
			if(tmp<min) min = tmp;
		}
		cout<<(100-min)*(100-min)<<endl;
	}
	return 0;
}
