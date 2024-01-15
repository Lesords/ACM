#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//题解：9个方格分别构造，每个方格都以当前列为基础进行构造
//每三个一起构造，(2x,1y) (2x,2y) (1x,3y) 三种组合

//题解：最简单的方法：直接将 其他字符 整体替换即可（例将2换成1即可

struct node{
    int x,y;
};
char s[10][10];
int pos[10] = {0,2,3,1,5,6,4,8,9,7};//对于列需要的行位置
vector<node> val;
int main() {
    int t;
    cin>>t;
    while(t--) {
        for(int i = 1;i <= 9;i++) cin>>s[i]+1;
        val.clear();
        val.push_back(node{0,0});//填补索引0的位置
        for(int i = 1;i <= 9;i+=3) {
            for(int j = 1;j <= 9;j+=3) {//遍历9个方格！！！
                //不能按输出顺序查找！！！
                for(int ii = i;ii < i+3;ii++) {//遍历当前方格的所有数据
                    for(int jj = j;jj < j+3;jj++) {//找到‘1’的位置
                        if(s[ii][jj]=='1') val.push_back(node{ii,jj});
                    }
                }
            }
        }
        for(int i = 1;i <= 9;i++) {//以当前列为基础进行修改即可
            s[val[pos[i]].x][val[i].y] = '1';
        }
        for(int i = 1;i <= 9;i++) {
            for(int j = 1;j <= 9;j++) cout<<s[i][j];
            cout<<"\n";
        }
    }
    return 0;
}
