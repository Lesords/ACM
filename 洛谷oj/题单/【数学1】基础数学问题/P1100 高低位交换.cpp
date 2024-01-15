#include<iostream>//ac
#include<string>
using namespace std;
int num[36],change[36];
unsigned int solve(unsigned int n) {//32位，所以用unsigned
    unsigned int tmp = n,cnt = 0,ans = 0;
    //1-32（1低位，32高位）
    while(tmp) {
        num[++cnt] = tmp&1;//记录当前位的大小
        tmp >>= 1;
    }
    while(cnt<32) num[++cnt] = 0;//高位不够补其
    for(int i = 1;i <= 16;i++) change[i] = num[i+16];//高位成低位
    for(int i = 17;i <= 32;i++) change[i] = num[i-16];//低位成高位
    unsigned int val = 1;//对应位置的值
    for(int i = 1;i <= 32;i++) {//二进制转十进制
        if(change[i]) ans += val;
        val <<= 1;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
