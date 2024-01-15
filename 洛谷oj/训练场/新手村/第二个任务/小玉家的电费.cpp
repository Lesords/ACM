#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	double t;
	cin>>t;
	if(t<=150) printf("%.1f\n",t*0.4463);
	else if(t<=400) printf("%.1f\n",150*0.4463 + (t-150)*0.4663);
	else printf("%.1f\n",150*0.4463+250*0.4663 + (t-400)*0.5663);
	return 0;
} 
