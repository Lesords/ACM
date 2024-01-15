#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：先统一转为十进制，然后再转成指定进制数

char v[20] = {'0','1','2','3','4','5','6','7','8','9','A','B',
'C','D','E','F'};//存储对应值的字符
int get_n(char c) {//获取当前字符对应的值
    if(c>='0'&&c<='9') return c-'0';
    return c-'A'+10;
}
int solve(string s,int bit) {//字符串为s，当前进制为bit
    int len = s.size()-1,val = 1,sum = 0;//sum存储结果，val为对应进制位的值
    for(int i = len;i >= 0;i--) {//从低位到高位
        int num = get_n(s[i]);//当前位的值
        sum += num*val;//更新结果
        val *= bit;//更新对应进制位的值
    }
    return sum;//返回结果
}
string change(int val,int bit) {//val转为bit位的字符串
    string ans = "";//从低位向高位存储，然后再翻转字符串即可
    while(val) {
        ans += v[val%bit];//添加对应值的字符
        val /= bit;
    }
    reverse(ans.begin(),ans.end());//翻转字符串
    return ans;
}
int main() {
    string s;
    int n,m;
    cin>>n>>s>>m;
    int val = solve(s,n);
    cout<<change(val,m);
    return 0;
}
