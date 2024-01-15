#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：根据样例可以知道前几个移动都是选中中间的 o* 移到空格位
//然后再把空格位移到最右的 ** 位置
//对于最后四行来说，直接打表（最后三个o*组合，需要多一个o*交换）
//需要注意的是，打表添加的 o* 需要少一组，因为数据中是多出一组 o* 的

/*
样例：
输入：7
输出：
ooooooo*******--
oooooo--******o*
oooooo******--o*
ooooo--*****o*o*
ooooo*****--o*o*
oooo--****o*o*o*
oooo****--o*o*o*
ooo--***o*o*o*o*

ooo*o**--*o*o*o*  （ooo***--o*o*o*o*）
o--*o**oo*o*o*o*
o*o*o*--o*o*o*o*
--o*o*o*o*o*o*o*
空行方便观察
*/

string s;
string last[4] = {"ooo*o**--*","o--*o**oo*","o*o*o*--o*",
    "--o*o*o*o*"};//数据中有4组 o*
int main() {
    int n;
    cin>>n;
    s = string(n,'o')+string(n,'*')+"--";//初始情况
    for(int i = 1;i <= n-3;i++) {//除了最后三组，其他直接转移
        cout<<s<<"\n";//未移动前
        for(int i = 0;i < s.size();i++) {//将中间的 o* 改为 --
            if(s[i]=='o'&&s[i+1]=='*') {
                s[i] = s[i+1] = '-';
                break;
            }
        }
        //可以倒序寻找
        for(int i = s.size()-1;i >= 0;i--) {//将末尾的 -- 改为 o*
            if(s[i]=='-'&&s[i-1]=='-') {
                s[i] = '*';
                s[i-1] = 'o';
                break;
            }
        }
        cout<<s<<'\n';//移动后的字符串
        //空格归位（移到右边
        for(int i = 0;i < s.size();i++) {//中间的 -- 改为 **
            if(s[i]=='-'&&s[i+1]=='-') {
                s[i] = s[i+1] = '*';
                break;
            }
        }
        //可以倒序寻找
        for(int i = s.size()-1;i >= 0;i--) {//末尾的 **改为 --
            if(s[i]=='*'&&s[i-1]=='*') {
                s[i] = s[i-1] = '-';
                break;
            }
        }
    }
    for(int i = 0;i < 4;i++) {//最后四行
        s = last[i];
        //需要多减去一组操作的 o*，本来为 n-3组
        for(int j = 1;j <= n-4;j++) s += "o*";
        cout<<s<<"\n";
    }
    return 0;
}
