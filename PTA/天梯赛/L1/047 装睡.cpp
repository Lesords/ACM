#include<iostream>//ac
#include<string>
using namespace std;
string ans[15];
int main() {
    int n,cnt = 1;;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string name;
        int a,b;
        cin>>name>>a>>b;
        if(a<15||a>20||b<50||b>70) ans[cnt++] = name;//װ˯
    }
    for(int i = 1;i < cnt;i++) cout<<ans[i]<<"\n";
    return 0;
}
