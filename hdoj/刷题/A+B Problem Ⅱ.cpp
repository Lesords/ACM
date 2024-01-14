#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void initial(string &a, string &b) {
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;
}
void del(string &a) {
    if(a[0]=='0') {
        a.erase(0,1);
    }
}
string bigadd(string a, string b) {
    initial(a, b);
    a='0'+a;
    b='0'+b;
    for(int i=a.size()-1;i>=0;i--) {
        int num1=a[i]-'0';
        int num2=b[i]-'0';
        if(num1+num2>9) {
            a[i-1]=a[i-1]+1;
            a[i]=(num1+num2)-10+'0';
        }
        else {
            a[i]=(num1+num2)+'0';
        }
    }
    while(a[0]=='0')
    del(a);
    return a;
}
int main() {
    int n;
    string a,b;
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>a>>b;
    	cout<<"Case "<<i<<":"<<endl;
    	cout<<a<<" + "<<b<<" = "<<bigadd(a,b)<<endl;
    	if(i!=n) cout<<endl;
    }
    return 0;
}
