#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：首先如果字符串最左边或者最右边出现0的话，肯定无解
//因为最后在最左边会出现 ')' 字符，最右边会出现 '(' 字符，这两种肯定无法匹配
//还有的就是记录 0 和 1 出现的次数，为奇数则肯定无法匹配！！！
//那么对于所有的0来说，两两成对匹配（奇数为'('，偶数位')'）
//对于所有的1来说，前面一半为 '(',后面一半为 ')'

const int MAXN = 1e5+5;
int pos[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        int zero = 0;
        for(int i = 0;i < s.size();i++) {
            zero += s[i]=='0';//统计零出现的次数
        }
        int one = n-zero;//计算1出现的次数
        if(s[0]=='0'||s[n-1]=='0'||zero%2) {//首尾为0或者，出现奇数次数的1
            cout<<"NO\n";
            continue;
        }
        int tzero = 0,tone =0;//当前位置的0和1的数量
        string ansA = "",ansB = "";//记录最后的结果
        for(int i = 0;i < n;i++) {//遍历所有位置
            if(s[i]=='1') {//当前位置为1
                tone++;//更新数量
                if(tone<=one/2) {//前面一半的话，即为 ( 字符
                    ansA += '(';
                    ansB += '(';
                }
                else {//否则为 ) 字符
                    ansA += ')';
                    ansB += ')';
                }
            }
            else {//当前位置为0的话
                tzero++;//更新数量
                if(tzero%2) {//奇数位置为 ( 字符
                    ansA += '(';
                    ansB += ')';
                }
                else {//偶数位置为 ) 字符
                    ansA += ')';
                    ansB += '(';
                }
            }
        }
        cout<<"YES\n"<<ansA<<"\n"<<ansB<<"\n";
    }
	return 0;
}
/*
样例：
3
6
100001
8
11000011
10
1110000111
*/
