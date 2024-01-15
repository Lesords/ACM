#include<iostream>//ac  暴力判断回文字符串对应的两行
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：暴力枚举对应的两个行的字符串，判断是否有相同的字符出现
//如果没有，则无法形成回文字符串

int n;
string s[105];
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>s[i];
        int flag = 0;//0为可以构成字符串
        for(int i = 1,j = n;i<j;i++,j--) {//结束条件为i < j！！！
            int mark = 0;
            for(int aa = 0;aa < s[i].size();aa++) {//判断aa和bb行是否存在相同的字符
                for(int bb = 0;bb < s[j].size();bb++) {
                    if(s[i][aa]==s[j][bb]) {
                        mark = 1;break;
                    }
                }
                if(mark) break;
            }
            if(mark==0) {//没有相同字符，无法构成回文字符串
                flag = 1;break;
            }
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
