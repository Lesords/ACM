#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：负进制
//短除法求余数，特殊处理负数的余数
//若余数为负数，则向接下来的商借位
//由于模数为负数，则 余数 - 模数 即为正数
//即 余数 -= 模数，商++
//证明：(商+1-1)*模数+余数 = (商+1)*模数 + (余数 - 模数) = 被除数

char s[30] = {'0','1','2','3','4','5','6','7','8','9','A',
'B','C','D','E','F','G','H','I','K'};//记录对应值的字符
int n,r;
string solve() {
    string ans = "";
    while(n) {
        int tmp = n%r;//取余数
        n /= r;//取商
        if(tmp<0) tmp -= r,n++;//特判负数
        ans += s[tmp];//添加对应字符
    }
    reverse(ans.begin(),ans.end());//反转字符串
    return ans;
}
int main() {
    cin>>n>>r;
    cout<<n<<"=";
    cout<<solve();
    cout<<"(base"<<r<<")";
    return 0;
}
