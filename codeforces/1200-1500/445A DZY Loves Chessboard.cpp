#include<iostream>//ac
using namespace std;

//题解：以BW混合的形式输出，特判 - 字符即可

char s[105][105];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>s[i][j];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i][j]=='-') cout<<s[i][j];//-则直接输出-即可
            else {
                if((i+j)%2) cout<<"B";//利用奇偶性来判断输出的字符
                else cout<<"W";
            }
        }
        cout<<"\n";//每行后面的回车字符
    }
    return 0;
}
