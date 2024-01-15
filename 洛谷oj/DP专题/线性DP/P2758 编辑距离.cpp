#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：线性dp
//令 dp[i][j] 为从字符串a的前i个匹配到字符串b的前j个所花费的次数
//边界状态：dp[i][0], dp[0][i] (1 <= i <= [len_a,len_b])
//dp[i][0] = i（即删除i个字符），dp[0][i] = i（即添加i个字符）
//转移：如果两个字符相等则无需操作：dp[i][j] = dp[i-1][j-1]
//否则可以删除当前字符 dp[i-1][j] + 1
//        插入一个字符 dp[i][j-1] + 1
//        更改当前字符 dp[i-1][j-1] + 1
//三种情况取最小值
//目的状态：dp[len_a][len_b]

const int MAXN = 2e3+5;
char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN];
int main() {
    string a,b;
    cin>>a>>b;
    int len_a = a.size();
    int len_b = b.size();
    //将字符串转换为字符数组，并初始化边界情况
    for(int i = 0;i < len_a;i++) s1[i+1] = a[i], dp[i+1][0] = i+1;
    for(int i = 0;i < len_b;i++) s2[i+1] = b[i], dp[0][i+1] = i+1;
    for(int i = 1;i <= len_a;i++) {
        for(int j = 1;j <= len_b;j++) {
            if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];//相等无需操作
            else {
                //否则三个操作取最小值
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[len_a][len_b];
    return 0;
}
