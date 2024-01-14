//003 个位数统计
#include<iostream>//ac
#include<string>
using namespace std;
int num[10];
int main() {
    string s;//1000位，需要用字符串存储
    cin>>s;
    for(int i = 0;i < s.size();i++) num[s[i]-'0']++;//统计数量
    for(int i = 0;i <= 9;i++) {
        if(num[i]==0) continue;//跳过0
        cout<<i<<":"<<num[i]<<"\n";
    }
    return 0;
}
