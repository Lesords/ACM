#include<iostream>//ac
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
string s[5];
string val[11] = {"####.##.##.####", "..#..#..#..#..#", "###..#####..###",
"###..####..####", "#.##.####..#..#", "####..###..####", "####..####.####",
"####.##.#..#..#", "####.#####.####", "####.####..####", "....#.###.#...."};
map<string,int> num;//val是数字转字符串，num是字符串转数字
vector<int> pnum;//保存最后结果的所有数位
int main() {
    for(int i = 0;i <= 10;i++) num[val[i]] = i;//记录对应字符串的数字
    int t;
    cin>>t;
    while(t--) {
        getchar();//处理回车符
        for(int i = 0;i < 5;i++) {
            getline(cin,s[i]);
        }
        int len = s[0].size(),ans = 0,tnum = 0;//ans为计算结果，tnum为每个项的值
        for(int i = 0;i < len;i += 4) {//4个为一个区间
            string tmp = "";
            for(int j = 0;j < 5;j++) {
                for(int z = i;z <= i+2;z++) {
                    tmp += s[j][z];//构造字符串
                }
            }
            if(num[tmp]==10) {//为加号时
                ans += tnum;//添加结果
                tnum = 0;//清零
            }
            else {
                tnum = tnum*10 + num[tmp];//构造数字
            }
        }
        ans += tnum;//添加最后的一个数字
        pnum.clear();//先清空！！！
        while(ans) {
            pnum.push_back(ans%10);//存储每个数位
            ans /= 10;
        }
        int snum = pnum.size()-1;//数位数量
        for(int i = 0;i < 5;i++) {//逐行输出！！！
            for(int j = snum;j >= 0;j--) {//共snum个
                if(j!=snum) cout<<".";//中间间隔符 .
                for(int z = i*3;z < i*3+3;z++) {//pnum[j]为当前数字
                    cout<<val[pnum[j]][z];//z为输出的位置
                }
            }
            cout<<"\n";
        }
        if(t) cout<<"\n";//中间间隔符
    }
    return 0;
}
