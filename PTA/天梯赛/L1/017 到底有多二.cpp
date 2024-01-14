#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;
    int two = 0,len = s.size(),sign = 0,even = 0;
    for(int i = 0;i < len;i++) {//计算2的数量
        if(s[i]=='2') two++;
    }
    if((s[len-1]-'0')%2==0) even = 1;//先判断是否为偶数
    if(s[0]=='-') sign = 1,len--;//再判断是否为负数，负数len需减一位
    double ans = 1;
    ans = two*1.0/len*(sign?1.5:1.0)*(even?2.0:1.0);
    printf("%.2f%%",ans*100);//保留两位小数
    return 0;
}
