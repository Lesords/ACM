#include<iostream>//ac
#include<cstring>
#include<stack>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

//题解：利用栈先计算每个左括号匹配的右括号位置
//然后开始遍历整个字符串，如果为字符，直接添加
//如果为括号，先计算括号后面的数字大小
//然后递归计算括号内的字符串，次数直接循环添加即可

const int MAXN = 2e4+5;
char s[MAXN];
int len,pos[MAXN];//pos记录左括号匹配的右括号位置
string solve(int l,int r) {//计算[l,r]区间的字符串
    string ans = "";//初始化为空
    for(int i = l;i <= r;i++) {
        if(isalpha(s[i])) {                     //为字符直接添加
            ans += s[i];
        }
        else {
            int cnt = 0,now = i;                //cnt为次数，now为当前计算的位置
            while(isdigit(s[now+1])) {          //若下一位为数字
                cnt = cnt*10 + (s[++now]-'0');  //计算数字
            }
            string tmp = "";                    //存储括号内的字符
            tmp = solve(now+1,pos[i]-1);        //计算括号内的字符，记得修改区间范围
                                                //now为数字的位置，pos[i]为右括号的位置
            while(cnt--) {                      //循环添加cnt次tmp
                ans += tmp;
            }
            i = pos[i];                         //移动i的位置
        }
    }
    return ans;
}
int main() {
    cin>>s+1;
    len = strlen(s+1);
    stack<int> sta;
    for(int i = 1;i <= len;i++) {               //计算字符串内对应左括号匹配的右括号位置
        if(s[i]=='[') sta.push(i);              //左括号，直接将位置放入栈中
        else if(s[i]==']') {                    //碰到右括号，直接将栈顶的左括号匹配到当前位置
            pos[sta.top()] = i;
            sta.pop();                          //弹出栈顶元素
        }
    }
    cout<<solve(1,len);                         //计算[1,len]内的字符串
    return 0;
}
