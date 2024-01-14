#include<iostream>//ac  £¿£¿£¿
#include<string>
using namespace std;
string s[105],ans[105];
int main() {
    char op;
    int n;
    cin>>op>>n;
    getchar();
    for(int i = 1;i <= n;i++) getline(cin,s[i]);
    for(int i = 1;i <= n;i++) {
        if(s[i].size()==n) continue;
        for(int j = (int) s[i].size();j < n;j++) s[i].push_back(' ');
    }
    int flag = 0;
    for(int i = n,ii = 1;i >= 1;i--,ii++) {
        for(int j = n-1,jj = 0;j >= 0;j--,jj++) {
            if(s[i].size()<=j) {
                ans[ii].push_back(' ');//ÓÃpush_back£¬·ñÔò»á¶Î´íÎó£¡£¡£¡
                continue;
            }
            if(s[i][j]!=' ') ans[ii].push_back(s[i][j]);
            else ans[ii].push_back(' ');
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < n;j++) if(ans[i][j]!=s[i][j]) {
            if(ans[i][j]=='\0'||s[i][j]=='\0') continue;
            flag = 1;break;
        }
    }
    if(!flag) cout<<"bu yong dao le\n";
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < n;j++) {
            if(ans[i][j]!=' '&&ans[i][j]!='\0') cout<<op;
            else cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
