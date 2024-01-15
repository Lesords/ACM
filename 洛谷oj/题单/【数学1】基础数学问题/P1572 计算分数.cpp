#include<iostream>//ac
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

//题解：字符串模拟
//先根据 / 字符分割出所有的分子
//再根据 + 或 - 字符分割出所有的分母
//需要特判最后一位
//利用变量mark来判断数字的符号，添加数字的时候记得乘mark
//然后通分
//根据所有分母，求最小公倍数，然后根据 最小公倍数/分母*分子 求解

vector<int> up,down;                            //up是存储分子，down存储分母
int gcd(int a,int b) {                          //最大公约数
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b) {                          //最小公倍数
    return a*b/gcd(a,b);
}
int main() {
    string s;
    cin>>s;
    int tmp = 0,mark = 1;                       //tmp为当前数的值，mark为数的符号
    int len = s.size();
    for(int i = 0;i < len;i++) {
        if(isdigit(s[i])) {                     //若为数字，直接操作
            tmp = tmp*10 + s[i]-'0';
        }
        else {
            if(s[i]=='/') {                     //除号，说明前面的数为分子
                up.push_back(tmp*mark);
                mark = 1;                       //符号需初始化为1（正
            }
            else if(s[i]=='-') {                //若为负数，说明前面为分母，且接下来的符号需为-1
                down.push_back(tmp*mark);
                mark = -1;
            }
            else if(s[i]=='+') {                //若为整数，说明前面也为分母
                down.push_back(tmp*mark);
                mark = 1;                       //符号需初始化为1（正
            }
            tmp = 0;
        }
        if(i==len-1) {                          //特判末尾情况
            down.push_back(tmp*mark);
        }
    }
    int sumDown = 1;
    for(auto v:down) sumDown = lcm(sumDown,v);  //计算最小公倍数
    int sumUp = 0;                              //累加分子的值
    for(int i = 0;i < down.size();i++) {
        sumUp += sumDown/down[i]*up[i];
    }
    tmp = gcd(sumDown,sumUp);                   //记录分子和分母之间是否有公因数
    if(sumDown/tmp==1) {                        //分母为1，只需要输出分子！！！
        cout<<sumUp/tmp;
    }
    else if(sumDown/tmp<0) {                    //若分母为负数，需移到前面！！！
        cout<<"-"<<sumUp/tmp<<"/"<<-1*sumDown/tmp;
    }
    else cout<<sumUp/tmp<<"/"<<sumDown/tmp;     //否则直接输出
    return 0;
}
