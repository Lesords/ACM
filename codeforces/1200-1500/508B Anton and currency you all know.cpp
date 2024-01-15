#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：由于给出的数一定是奇数，所以只需要根据是否有偶数位来判断是否有解
//有解的话，先从高位到低位寻找第一个比最后一位小的偶数，找到则交换并输出
//否则继续，从低位到高位寻找第一个比最后一位大的偶数，找到则交换并输出

int main() {
    string s;
    cin>>s;
    int flag = 0,len = s.size();
    for(int i = 0;i < len;i++) {
        int now = s[i] - '0';
        if(now%2==0) {//判断是否有偶数位
            flag = 1;break;
        }
    }
    if(flag==0) {//没有则无解
        cout<<"-1";
        return 0;
    }
    int pos = -1,val = s[len-1]-'0';//val为最后一位的值(转数值！！！
    for(int i = 0;i < len-1;i++) {//从高位到低位寻找第一个小于val的值
        int now = s[i] - '0';
        if(now%2==0&&now<val) {
            pos = i;break;
        }
    }
    if(pos==-1) for(int i = len-1;i >= 0;i--) {
        int now = s[i]-'0';
        if(now%2==0&&now>val) {//从低位到高位寻找第一个大于val的值
            pos = i;break;
        }
    }
    swap(s[pos], s[len-1]);//交换并输出即可
    cout<<s;
    return 0;
}
