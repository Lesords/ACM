#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;

//题解：直接边统计6的数量，边输出即可

string s;
int main() {
    getline(cin,s);//读入一行
    int cnt = 0,len = s.size();
    for(int i = 0;i < len;i++) {
        if(i==len-1||s[i]!='6') {//最后一个字符或则不为6时
            if(i==len-1&&s[i]=='6') cnt++;//特判最后一个字符
            if(cnt>9) {
                cout<<"27";
                if(s[i]!='6') cout<<s[i];//当前不为6才需要输出
            }
            else if(cnt>3) {
                cout<<"9";
                if(s[i]!='6') cout<<s[i];//当前不为6才需要输出
            }
            else {
                //输出所有的6
                for(int i = 1;i <= cnt;i++) cout<<'6';
                cout<<s[i];
            }
            cnt = 0;//cnt清零
        }
        else ++cnt;//累加
    }
    return 0;
}
