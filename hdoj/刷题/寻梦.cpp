#include<iostream>//ac
#include<cstring>
using namespace std;
char a[55],b[55];
int main(){
	int T;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		int mid = strlen(a)/2 - 1;//�м�λ��
		for(int i = 0;i <= mid ;i++) {//ǰ�벿��
			cout<<a[i];
		}
		cout<<b;//�м� 
		for(int i = mid+1;i<strlen(a);i++) cout<<a[i];//��벿�� 
		cout<<endl;
	}
	return 0;
} 
