#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int pos[MAXN];//记录虫子的所属堆号
int main() {
    int n,tmp,cnt = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        for(int j = 1;j <= tmp;j++) {//记录当前堆的所有虫子位置
            pos[++cnt] = i;
        }
    }
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        cout<<pos[tmp]<<"\n";//输出对应位置即可
    }
    return 0;
}
