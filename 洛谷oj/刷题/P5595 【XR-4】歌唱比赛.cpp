#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：如果字符串中含有Z字符使，Z之后所有的字符都需为Z才满足条件！！！
//其他的直接判断即可

const int MAXN = 1e6+6;
char ansA[MAXN],ansB[MAXN];
bool judge(string tmp) {//判断Z字符后面是否都为Z
    int flag = 0;
    for(int i = 0;i < tmp.size();i++) {
        if(tmp[i]=='Z') flag = 1;
        else if(flag&&tmp[i]!='Z') return true;//不为Z则无解
    }
    return false;
}
int main() {
    string s;
    cin>>s;
    if(judge(s)) {//无解
        cout<<"-1";
        return 0;
    }
    for(int i = 0;i <= s.size();i++) {
        if(s[i]=='X') ansA[i] = '1',ansB[i] = '0';//较大的取1，较小的为0
        else if(s[i]=='Y') ansA[i] = '0',ansB[i] = '1';
        else ansA[i] = ansB[i] = '0';//相等为0
    }
    for(int i = 0;i < s.size();i++) cout<<ansA[i];
    cout<<"\n";
    for(int i = 0;i < s.size();i++) cout<<ansB[i];
    return 0;
}
