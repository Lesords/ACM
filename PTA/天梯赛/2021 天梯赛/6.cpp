#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN = 1e4+5;
string s[50];
string one = "easy";
string two = "qiandao";
bool judge(int pos) {
    string ss = s[pos];
    int len = ss.size();
    int flag = 0;
    // 判断是否含有easy
    for(int i = 0;i < len;i++) {
        int vis = 1;//vis表示当前行是否含有easy，为1表示含有，为0表示不含有
        for(int j = 0;j < one.size();j++) {//遍历所有位置（easy每个字符）
            if(i+j>=len) {//位置超过了，肯定无解，因为后面的字符数量不够
                vis = 0;break;
            }
            if(ss[i+j]!=one[j]) {//从i位置开始，如果第i+j位置不相等，直接结束
                // 因为如果每个位置都相等的话，括号内的语句肯定不会执行
                vis = 0;
                break;
            }
        }
        if(vis) {
            return false;
        }
    }
    // 判断是否含有qiandao
    for(int i = 0;i < len;i++) {
        int vis = 1;
        for(int j = 0;j < two.size();j++) {
            if(i+j>=len) {
                vis = 0;break;
            }
            if(ss[i+j]!=two[j]) {
                vis = 0;
                break;
            }
        }
        if(vis) {
            return false;
        }
    }
    return true;
}
int main() {
    int n,ans = 0,m,cnt = 0;//ans记录对应结果的行，cnt记录所有还未完成的题目
    cin>>n>>m;
    getchar();//处理行末空格，
    for(int i = 1;i <= n;i++) {
        getline(cin,s[i]);//每次读入一行
        if(judge(i)) {//判断当前行是否含有easy和qiandao
            cnt++;
            // !ans表示ans为0的时候为真，那么如果ans不为0
            // 也就是说已经记录了结果，那么为假也就是不进行括号内的操作
            if(!ans&&cnt>m) {//总共只有m题，如果当前cnt超过了m，说明当前题目还未完成
                ans = i;//ans记录结果
            }
        }
    }
    if(cnt<=m) {
        cout<<"Wo AK le";
    }
    else {
        cout<<s[ans];
    }
    return 0;
}
