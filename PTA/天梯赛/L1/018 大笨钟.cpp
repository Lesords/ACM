#include<iostream>//ac
#include<cstdio>
#include<string>
using namespace std;
string tim(int n) {//处理个位数没有前置0的情况
    string ans = "";
    if(n<10) ans += '0', ans += char(n+'0');
    else ans += char(n/10+'0'),ans += char(n%10+'0');
    return ans;
}
int main() {
    int hour,minute;
    scanf("%d:%d",&hour,&minute);
    if(hour>12||(hour==12)&&minute) {//超过12点都需要当
        int cnt = hour-12 + (minute?1:0);//判断分针是否有值
        for(int i = 1;i <= cnt;i++) cout<<"Dang";
    }
    else cout<<"Only "<<tim(hour)<<":"<<tim(minute)<<".  Too early to Dang.\n";
    return 0;
}
