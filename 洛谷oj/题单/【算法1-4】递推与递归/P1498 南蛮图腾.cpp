#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：直接模拟
//初始时，宽度为4，高度为2
//每增大一次，相等于宽度和高度*2
//那么可以直接计算当前所需的图腾的大小（即宽和高
//先初始化所有位置为空格字符
//然后计算第一阶的位置及对应字符
//接着从底向上，一阶一阶扩大

char s[(2<<10)+5][(4<<10)+5];
int main() {
    memset(s,' ',sizeof(s));                        //初始化为空格字符
    int n;
    cin>>n;
    int hei = 2<<(n-1);                             //总的高度
    int wid = 4<<(n-1);                             //总的宽度
    s[hei][1] = s[hei-1][2] = '/';                  //初始化第一阶的值
    s[hei][2] = s[hei][3] =  '_';
    s[hei][4] = s[hei-1][3] = '\\';
    for(int i = 1;i < n;i++) {                      //扩大n-1次
        int thei = 2<<(i-1);                        //当前阶的高度
        int twid = 4<<(i-1);                        //当前阶的宽度
        for(int j = hei;j >= hei-thei+1;j--) {      //复制到右边
            for(int k = twid+1;k <= twid<<1;k++) {
                s[j][k] = s[j][k-twid];
            }
        }
        for(int j = hei-thei;j >= hei-(thei<<1)+1;j--) {//复制到上面
            for(int k = (twid>>1)+1;k <= (twid>>1)+twid;k++) {
                s[j][k] = s[j+thei][k-twid/2];
            }
        }
    }
    for(int i = 1;i <= hei;i++) {
        for(int j = 1;j <= wid;j++) cout<<s[i][j];
        cout<<"\n";
    }
    return 0;
}
/*
   /\
  /__\
 /\  /\
/__\/__\
*/
