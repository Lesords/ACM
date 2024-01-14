//002 打印沙漏
#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n;
    char ch;
    cin>>n>>ch;
    int cnt = 1;
    n -= 1;//中间一层
    for(int i = 3;;i += 2) {//计算层数（每层多2）
        if(n>(i*2)) n -= (i*2),cnt++;
        else break;
    }
    for(int i = cnt;i >= 1;i--) {//上面一半
        for(int j = cnt;j > i;j--) cout<<" ";//空格
        for(int j = 1;j <= 1+(i-1)*2;j++) cout<<ch;//字符
        cout<<'\n';
    }
    for(int i = 2,siz = (cnt-1);i <= cnt;i++,siz--) {//下半部分
        for(int j = 1;j < siz;j++) cout<<" ";//空格
        for(int j = 1;j <= 1+(i-1)*2;j++) cout<<ch;//字符
        cout<<'\n';
    }
    cout<<n<<'\n';
    return 0;
}
