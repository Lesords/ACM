#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：遍历整个字符串，以当前点为回文串中心，向前后拓展判断最长的回文串大小
//需要注意的是，回文串有奇数和偶数，即有一个中心和两个中心
//所以需要判断两次

int main() {
    string s;
    getline(cin,s);
    int ans = 0,len = s.size();
    for(int i = 0;i < len;i++) {//遍历整个字符串
        int num = 1;//奇数回文串，一个中心
        for(int j = 1;j < len;j++) {
            if(i-j<0||i+j>=len) break;//前后有一个越界了都不行
            if(s[i-j]!=s[i+j]) break;//前后不相等则，结束
            num += 2;//否则回文串的长度 +2（前后各一个）
        }
        ans = max(ans,num);//取较大值
        if(i+1>=len||s[i]!=s[i+1]) continue;//若后一个越界，或者不相等
        num = 2;//两个中心: 一个是i，一个是(i+1)
        for(int j = 1;j < len;j++) {
            if(i-j<0||(i+1)+j>=len) break;//越界
            if(s[i-j]!=s[(i+1)+j]) break;//i-j！！！
            num += 2;
        }
        ans = max(ans,num);//取较大值
    }
    cout<<ans<<endl;
    return 0;
}
