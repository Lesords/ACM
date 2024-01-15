#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

//题解：要么矩阵全为0，要么在每个1（跳过边界）的下方或者右方需要有一个1

const int MAXN = 55;
char s[MAXN][MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        for(int i = 1;i <= n&&flag!=1;i++) {
            for(int j = 1;j <= n;j++) {
                if(i==n||j==n) continue;//跳过边界
                if(s[i][j]=='1') {//为1的情况
                    //右方或者下方必须有一个1
                    if(s[i][j+1]!='1'&&s[i+1][j]!='1') {
                        flag = 1;break;
                    }
                }
            }
        }
        puts(flag?"NO":"YES");
    }
    return 0;
}
