#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：由于字符的顺序可以任意，所以决定字符串是否是回文串的条件是：
//为 奇数个字符 的数量
//奇数个字符 的数量为0或者为奇数都是第一个人赢，否则为第二个人赢
//因为每个人的最优选择都是删除 一个奇数个的字符
//因为对应的 偶数个字符 双方都可以删除，删除后与删除前不受影响

int cnt[30];
int main() {
    string s;
    cin>>s;
    //统计所有字符出现的次数
    for(int i = 0;i < s.size();i++) cnt[s[i]-'a']++;
    int num = 0;
    for(int i = 0;i <= 25;i++) {
        if(cnt[i]&1) num++;//记录出现奇数次的数量
    }
    if(num==0||num&1) cout<<"First";//为0或者为奇数个都是第一个人赢
    else cout<<"Second";
    return 0;
}
