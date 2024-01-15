#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
#define ull unsigned long long
using namespace std;

//题解：计算字符串对应的哈希值，然后放入set中去重即可

const int MOD = 100000007;//模数
const int BIT = 131;//进制数
set<int> st;//去重，判断字符串个数
ull getN(char ch) {//给对应字符一个值
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='a'&&ch<='z') return ch-'a'+10;
    return ch-'A'+50;
}
ull Hash(string tmp) {//计算哈希值
    int len = tmp.size();
    ull bit = 1, ans = 0;
    for(int i = len-1;i >= 0;i--) {//从低位到高位开始计算
        ans += getN(tmp[i])*bit;
        bit *= BIT;//当前位置的进制值
    }
    return ans;//返回哈希值
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        st.insert(Hash(tmp));
    }
    cout<<st.size();//统计st数量即为答案
    return 0;
}
