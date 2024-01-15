#include<iostream>
using namespace std;
int a[20],sum[20],book;
int main(){
	int T;cin>>T;
	while(T--) {
		long long n,m,cnt;
		cin>>n>>m;
		cnt=n/m,m%=10;//cnt是n中m的倍数的总数量 
		for(int i=1;;i++) {
			a[i]=(i*m)%10;//a保存当前大小  
			sum[i]=sum[i-1]+a[i];//sum保存总大小
			if(a[i]==0) {
				book=i;//book为循环的次数 
				break;
			}
		}
		cout<<(cnt/book)*sum[book]+sum[cnt%book]<<endl;
	}
	return 0;
} 
