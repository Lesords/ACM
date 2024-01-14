#include<iostream>//ac
using namespace std;
int main() {
	int l, r,flag = 0;
	cin>>l>>r;
	for(int i = l;i <= r;i++) {
		int tmp = i;
		while(tmp) {
			if(tmp%10==7) {
				cout<<i<<endl;
				flag = 1;
				break;
			}
			tmp /= 10;
		}
	}
	if(!flag) cout<<"None"<<endl;
	return 0;
} 
