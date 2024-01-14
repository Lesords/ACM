#include<iostream>//ac
#include<cstring>
using namespace std;
char a[55],b[55];
int main(){
	int T;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		int mid = strlen(a)/2 - 1;//中间位置
		for(int i = 0;i <= mid ;i++) {//前半部分
			cout<<a[i];
		}
		cout<<b;//中间 
		for(int i = mid+1;i<strlen(a);i++) cout<<a[i];//后半部分 
		cout<<endl;
	}
	return 0;
} 
