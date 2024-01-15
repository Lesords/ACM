#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//题解：从头到尾按顺序先给公主找王子，然后最后判断是否有公主没有王子
//若有，则遍历所有王子，找到第一个没有匹配的即可

const int MAXN = 1e5+5;
int vis[MAXN],done[MAXN];//done记录公主是否匹配，vis为王子是否匹配
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,mark = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {//初始化，不用memset
            vis[i] = done[i] = 0;
        }
        for(int i = 1;i <= n;i++) {
            int tmp,flag = 0;//flag来记录当前是否匹配成功
            cin>>tmp;
            for(int j = 1;j <= tmp;j++) {
                int tt;
                cin>>tt;
                if(flag) continue;//避免重复匹配
                if(vis[tt]==0) {
                    done[i] = vis[tt] = 1;//i公主和tt王子匹配
                    flag = 1;
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            if(done[i]==0) {//表示当前公主没有匹配
                mark = 1;//标记
                for(int j = 1;j <= n;j++) {
                    if(vis[j]==0) {//找到第一个没有匹配的王子即可
                        cout<<"IMPROVE\n";
                        cout<<i<<" "<<j<<"\n";
                        break;
                    }
                }
                break;//记得结束循环！！！
            }
        }
        if(!mark) cout<<"OPTIMAL\n";
    }
    return 0;
}
