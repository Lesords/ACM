#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(int i = 6;i <= 9;i++) cout<<s[i];//Äê
    cout<<"-";
    for(int i = 0;i <= 1;i++) cout<<s[i];//ÔÂ
    cout<<"-";
    for(int i = 3;i <= 4;i++) cout<<s[i];//ÈÕ
    return 0;
}
