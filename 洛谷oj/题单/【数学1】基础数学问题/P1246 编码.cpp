#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//题解；对于给定字符串来说，由于是升序的，所以可以根据位数以及各个位置的字符
//来计算之前的字符串数量，从而算出当前字符串代表的数字
//对于位数n的字符串来说
//之前的字符串有：位数1,2,3···,n-1 对应的数量为C(26,i) (从26个字符选i个的组合数)
//对于位数等于当前字符串来说：
//逐个判断字符，由于后面的字符必须大于当前字符，所有后面的字符可以选择的数量为'z'-j（j为当前字符）

int c(int n,int m) {//n个字符中选m个字符的组合数
    int ans = 1;
    for(int i = n-m+1;i <= n;i++) ans *= i;
    for(int i = 1;i <= m;i++) ans /= i;
    return ans;
}
int main() {
    string s;
    cin>>s;
    int len = s.size(),ans = 0;
    for(int i = 1;i < len;i++) {//不满足升序即为不存在
        if(s[i]<=s[i-1]) {//不能等于！！！
            cout<<"0";
            return 0;
        }
    }
    for(int i = 1;i < len;i++) {//先计算小于当前位数的字符串数量
        ans += c(26,i);
    }
    for(int i = 0;i < len;i++) {//逐个字符判断
        char tmp = i==0?'a':s[i-1]+1;//边界（即下一个位置的字符起始状态
        for(char j = tmp;j < s[i];j++) {//不能等于当前字符！！！
            ans += c('z'-j,len-i-1);//初始位置为0，所以后面可以填充的位数需-1
        }
    }
    cout<<ans+1;//还有本身一位
    return 0;
}
