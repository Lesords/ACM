#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

//��⣺Ҫô����ȫΪ0��Ҫô��ÿ��1�������߽磩���·������ҷ���Ҫ��һ��1

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
                if(i==n||j==n) continue;//�����߽�
                if(s[i][j]=='1') {//Ϊ1�����
                    //�ҷ������·�������һ��1
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
