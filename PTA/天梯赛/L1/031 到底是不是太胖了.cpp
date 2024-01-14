#include<iostream>//ac
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n--) {
        double a,b;
        cin>>a>>b;
        double sta = (a-100.0)*0.9*2;//标准体重
        if(abs(sta-b)<sta*0.1) cout<<"You are wan mei!\n";
        else if(b-sta>=sta*0.1) cout<<"You are tai pang le!\n";//大于等于！！！
        else cout<<"You are tai shou le!\n";
    }
    return 0;
}
