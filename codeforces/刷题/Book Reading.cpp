#include<iostream>
using namespace std;
int a[20],sum[20],book;
int main(){
	int T;cin>>T;
	while(T--) {
		long long n,m,cnt;
		cin>>n>>m;
		cnt=n/m,m%=10;//cnt��n��m�ı����������� 
		for(int i=1;;i++) {
			a[i]=(i*m)%10;//a���浱ǰ��С  
			sum[i]=sum[i-1]+a[i];//sum�����ܴ�С
			if(a[i]==0) {
				book=i;//bookΪѭ���Ĵ��� 
				break;
			}
		}
		cout<<(cnt/book)*sum[book]+sum[cnt%book]<<endl;
	}
	return 0;
} 
