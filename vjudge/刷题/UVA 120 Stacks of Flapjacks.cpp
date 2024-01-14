#include<iostream>//ac
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

//题解：每次查找最大的煎饼，将其放在当前位置的最低位置
//若所查找的煎饼不在最顶部时，需先将煎饼翻到顶部，然后再翻到当前位置的最底部
//否则直接翻到 当前位置的最底部 即可

int a[55],b[55],num[105];
int main() {
    string s;
    while(getline(cin,s)) {//读入一行
        int cnt = 1,tmp;
        stringstream ss(s);//利用字符串流来读取字符串中的数字
        while(ss>>tmp) a[cnt] = tmp,b[cnt++]= tmp;//给两组数组赋值
        sort(b+1,b+cnt);//排序计算最后的顺序
        int pos = cnt-1;
        for(int i = 1;i < cnt;i++) cout<<a[i]<<" ";
        cout<<"\n";
        for(int i = pos;i >= 1;i--) {
            int tmp;
            for(int j = 1;j <= i;j++) {
                if(a[j]==b[i]) {
                    tmp = j;break;
                }
            }
            if(tmp==i) continue;
            if(tmp!=1) {
                cout<<pos-tmp+1<<" ";
                for(int j = 1;j <= tmp/2;j++) swap(a[j],a[tmp-j+1]);
            }
            cout<<pos-i+1<<" ";
            for(int j = 1;j <= i/2;j++) swap(a[j],a[i-j+1]);
        }
        cout<<"0\n";
    }
    return 0;
}
