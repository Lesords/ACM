#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
using namespace std;
int main() {
    int n;
    char a[1050];
    cin>>n;
    scanf("%*c");
    for(int i=1;i<=n;i++) {
		gets(a);
		int ans1,ans2,ans3,ans4,ans5;
        ans1=ans2=ans3=ans4=ans5=0;
        for(int j=0;j<strlen(a);j++) {
           	if(a[j]=='a') ans1++;
           	else if(a[j]=='e') ans2++;
    	    else if(a[j]=='i') ans3++;
            else if(a[j]=='o') ans4++;
    		else if(a[j]=='u') ans5++;
    	}
        cout<<"a:"<<ans1<<endl;
        cout<<"e:"<<ans2<<endl;
        cout<<"i:"<<ans3<<endl;
        cout<<"o:"<<ans4<<endl;
        cout<<"u:"<<ans5<<endl;
        if(i!=n) cout<<endl;
    }
    return 0;
}
