#include<iostream>//ac
#include<cstdio>
#include<string>
using namespace std;
string tim(int n) {//�����λ��û��ǰ��0�����
    string ans = "";
    if(n<10) ans += '0', ans += char(n+'0');
    else ans += char(n/10+'0'),ans += char(n%10+'0');
    return ans;
}
int main() {
    int hour,minute;
    scanf("%d:%d",&hour,&minute);
    if(hour>12||(hour==12)&&minute) {//����12�㶼��Ҫ��
        int cnt = hour-12 + (minute?1:0);//�жϷ����Ƿ���ֵ
        for(int i = 1;i <= cnt;i++) cout<<"Dang";
    }
    else cout<<"Only "<<tim(hour)<<":"<<tim(minute)<<".  Too early to Dang.\n";
    return 0;
}
