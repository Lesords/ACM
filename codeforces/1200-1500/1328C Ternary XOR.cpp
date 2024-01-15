#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：从左开始构造，a当前值如果比b大，则后面的大值全给b

const int MAXN = 5e4+5;
char s[MAXN], a[MAXN], b[MAXN];//按a值大，b值较小来构造
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,mark = 0;//mark标记第一个串中是否出现较大值
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>s[i];
            if(s[i]=='0') a[i] = b[i] = '0';//0只有一种可能
            else if(s[i]=='2') {//化为 1+1 或 2+0
                if(mark==0) a[i] = b[i] = '1';//两个值一样大时均分
                else a[i] = '0', b[i] = '2';//否则较大值给b
            }
            else {
                if(mark==0) a[i] = '1', b[i] = '0';//a优先给大值
                else a[i] = '0', b[i] = '1';//否则都给b
                mark = 1;
            }
        }
        for(int i = 1;i <= n;i++) cout<<a[i];
        cout<<"\n";
        for(int i = 1;i <= n;i++) cout<<b[i];
        cout<<"\n";
    }
    return 0;
}
