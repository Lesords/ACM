#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[105];
int main()
{
	int n;
	cin>>a;
	sort(a,a+strlen(a));
	n=unique(a,a+strlen(a))-a;
	if(n%2==0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;
	return 0;
}
