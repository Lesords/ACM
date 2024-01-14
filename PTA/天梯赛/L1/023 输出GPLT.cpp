#include<iostream>//ac
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

//注意：字符串可以改变顺序，所以根据num数组输出即可

string s;
int len,num[5],pos,sum;
char ord[5] = {'G','P','L','T'};
int main() {
    cin>>s;
    len = s.size();
    for(int i = 0;i < len;i++) {
        for(int j = 0;j < 4;j++) {
            if(toupper(s[i])==ord[j]) {
                sum++;//统计对应字符的数量，以及总的数量
                num[j]++;break;
            }
        }
    }
    while(num[pos]==0) pos = (pos+1)%4;//第一个字符可能也为空！！！
    for(int i = 1;i <= sum;i++) {//输出共sum个字符
        cout<<ord[pos];
        num[pos]--;//对应字符数--
        pos = (pos+1)%4;//向后移位
        //最后一位无需找下一位！！！
        while(i!=sum&&num[pos]==0) pos = (pos+1)%4;//找到下一个字符数量不为0的字符
    }
    return 0;
}
