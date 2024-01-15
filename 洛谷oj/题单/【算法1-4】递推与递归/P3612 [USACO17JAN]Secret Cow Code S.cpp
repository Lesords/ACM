#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：每次判断n在从当前串转成上一个短串的位置
//对于上一个串而言当前串为  1 2...n  -> 1 2...n n 1 2...
//也就是说 pos在上一个串的位置 为 pos-(len/2)-1
//注意：若所得的值为0，则需修改成 len/2

typedef long long ll;
int main() {
    string s;
    ll n;
    cin>>s>>n;
    ll len = s.size();//记录原串的长度
    while(n>len) {//如果在原串的长度范围，则结束
        ll i = len;
        while(i<n) i <<= 1;//寻找满足n长的串
        i >>= 1;//取其一半值，即为上一个串的长
        n = (n-i-1);//更新n在上一个串的位置
        if(n==0) n = i;//特判为0的情况！！！
    }
    cout<<s[n-1];//串从0开始记录
    return 0;
}
