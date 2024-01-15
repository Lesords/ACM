#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：直接模拟即可
//计算图形所需要的空间大小，然后从中间层开始计算
//先初始化所有位置为 |，可方便计算

const int MAXN = 1e3+5;
char meat[MAXN<<1][MAXN];
void change(int mid, int val, char ch) {
    //对应两行为 mid+val, mid-val;最后一个为2+val
    for(int i = 1;i <= 2+val;i++) {//两个横向的
        meat[mid-val][i] = meat[mid+val][i] = ch;
    }
    if(ch=='-') return;//膜层直接跳过，因为初始化过了
    for(int i = 0;i <= val;i++) {//最后一列
        meat[mid-i][2+val] = meat[mid+i][2+val] = ch;
    }
}
int main() {
    string s;
    cin>>s;
    int len = s.size();
    int col = len+1;
    int raw = len*2-1;
    for(int i = 1;i <= raw;i++) {//初始化所有位置为|
        for(int j = 1;j <= col;j++) meat[i][j] = '|';
    }
    for(int i = 0;i < len;i++) {
        char now = (s[i]-'0')?'-':'*';
        change(len, i,now);//中间层len，向两边扩散i大小，操作对应字符为now
    }
    for(int i = 1;i <= raw;i++) {
        for(int j = 1;j <= col;j++) {
            cout<<meat[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
/*
0000001
0101001
*/
