#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：判断一个数是否为8的倍数只需要判断最后三位是否为8的倍数即可
//对应一位来讲只需要0或者8
//两位和三位分别开始构造，然后判断是否为8的倍数即可

int to_n(char ch) {//字符转数字
    return ch - '0';
}
int main() {
    string s;
    cin>>s;
    int len = s.size(),flag = 0;
    for(int i = 0;i < len;i++) {
        if(s[i]=='0') {//出现0
            flag = 1;break;
        }
        if(s[i]=='8') {//出现8
            flag = 8;break;
        }
    }
    if(flag==1) {//单个数0
        cout<<"YES\n0\n";
        return 0;
    }
    if(flag==8) {//单个数8
        cout<<"YES\n8\n";
        return 0;
    }
    for(int i = 0;i < len;i++) {
        for(int j = i+1;j < len;j++) {//构造两位数
            int num = to_n(s[i])*10+to_n(s[j]);
            if(num%8==0) {//为8的倍数即可结束
                flag = 1;
                cout<<"YES\n"<<num<<"\n";
                return 0;
            }
        }
    }
    for(int i = 0;i < len;i++) {//构造三位数
        if(flag) break;
        for(int j = i+1;j < len;j++) {
            if(flag) break;
            for(int k = j+1;k < len;k++) {
                int num = to_n(s[i])*100+to_n(s[j])*10+to_n(s[k]);
                if(num%8==0) {//为8的倍数即可结束
                    flag = 1;
                    cout<<"YES\n";
                    cout<<num<<"\n";
                    break;
                }
            }
        }
    }
    if(flag==0) cout<<"NO\n";
    return 0;
}
