#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int num[11],pos[11];//num为对应数字出现的数量，pos为对应数字出现的位置
string s;//可能有前置零，所以用字符串存储！！！
int main() {
    cin>>s;
    for(int i = 0;i < (int)s.size();i++) {//统计出现的数字的数量
        int tmp = s[i]-'0';
        num[tmp]++;
    }
    int cnt = 0,flag = 0;
    cout<<"int[] arr = new int[]{";
    for(int i = 9;i >= 0;i--) {//从大到小输出出现的数字，并记录位置
        if(num[i]==0) continue;
        if(cnt!=0) cout<<",";
        cout<<i;
        pos[i] = cnt++;//记录位置
    }
    cout<<"};\nint[] index = new int[]{";
    for(int i = 0;i < (int)s.size();i++) {
        int tmp = s[i]-'0';
        if(flag) cout<<",";
        flag = 1;
        cout<<pos[tmp];//输出对应数字的位置即可
    }
    cout<<"};";
    return 0;
}
