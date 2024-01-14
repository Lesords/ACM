//005 考试座位号
#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
struct info{
    string id;//准考证号
    int num;//考试座位号
}data[1005];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string s;
        int a,b;
        cin>>s>>a>>b;//利用下标存储数据，然后直接获取即可
        data[a].id = s;//a为试机号码
        data[a].num = b;
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int op;cin>>op;//试机号码
        cout<<data[op].id<<" "<<data[op].num<<"\n";
    }
    return 0;
}
