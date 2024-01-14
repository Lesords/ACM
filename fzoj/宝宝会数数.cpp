#include<iostream>
using namespace std;
long long a[100005],ans;
long long f(int x) {
	long long ans=0;
	while(x!=0) {//必须从1开始 
		int a=x%10;
		if(a==0||a==6||a==9) ans+=6;
		else if(a==1) ans+=2;
		else if(a==2||a==3||a==5) ans+=5;
		else if(a==4) ans+=4;
		else if(a==7) ans+=3;
		else if(a==8) ans+=7;
		/*switch(a) {//两种都可以 
			case 0:
			case 6:
			case 9:ans+=6;break;
			case 1:ans+=2;break;
			case 2:
			case 3:
			case 5:ans+=5;break;
			case 4:ans+=4;break;
			case 7:ans+=3;break;
			case 8:ans+=7;break;
		}*/
		x/=10;
	}
	return ans;
}
int main() {
	int n;
	ans=a[0]=6;//判断原因 
	for(int i=1;i<=100002;i++) {
		ans+=f(i);
		a[i]=ans;
	}
	while(cin>>n) {
		cout<<a[n]<<endl;
	}
	return 0;
}
