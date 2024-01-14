#include<iostream>//???
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char s[6][6];
int a[6][6];
vector<int> tmp,ans;
int main() {
    for(int i = 1;i <= 4;i++) cin>>s[i]+1;
    for(int i = 0;i < (1<<4);i++) {
        for(int j = 1;j <= 4;j++) {
            for(int k = 1;k <= 4;k++) {
                a[j][k] = s[i][j]=='+'?1:0;
            }
        }

    }
    return 0;
}
