#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(int i = 0;i < s.size();i++) {//什么数字都可以选，不需要固定一个数字！！！
        if(i==0&&s[i]=='9') cout<<s[i];//特判第一位
        else {
            int val = s[i]-'0';
            //判断转换后和原来的值哪个小，选择较小值输出即可
            if(9-val<val) cout<<char(9-val+'0');
            else cout<<s[i];
        }
    }
    return 0;
}
