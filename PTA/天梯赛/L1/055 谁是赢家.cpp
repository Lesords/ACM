#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int a,b,tmp,one = 0,two = 0;
    cin>>a>>b;
    for(int i = 1;i <= 3;i++) {
        cin>>tmp;
        if(!tmp) one++;//记录评委票数
        else two++;
    }
    //a胜利的情况只有两种
    if(a>b&&one||one==3) cout<<"The winner is a: "<<a<<" + "<<one;
    else cout<<"The winner is b: "<<b<<" + "<<two;
    return 0;
}
