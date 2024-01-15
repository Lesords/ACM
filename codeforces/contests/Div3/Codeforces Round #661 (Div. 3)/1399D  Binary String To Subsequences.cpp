#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int pos[MAXN];
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        string s;
        cin>>n>>s;
        queue<int> one,zero;//值为子序列号
        int cnt = 0,tmp;
        for(int i = 0;i < n;i++) {
            if(s[i]=='0') {//当前为0对应为1
                if(one.empty()) {//1为空，则0结尾序列增加
                    zero.push(++cnt);
                    pos[i] = cnt;
                }
                else {//需要将1修改成0
                    tmp = one.front();
                    one.pop();//去除1结尾队列队首
                    pos[i] = tmp;
                    zero.push(tmp);//将其放入0结尾队列中
                }
            }
            else {//当前为1对应为0
                if(zero.empty()) {//0为空，则1结尾序列增加
                    one.push(++cnt);
                    pos[i] = cnt;
                }
                else {//需要将0结尾序列修改成1结尾序列
                    tmp = zero.front();
                    zero.pop();//去除0结尾序列队首
                    pos[i] = tmp;
                    one.push(tmp);//将其放入1结尾队列中
                }
            }
        }
        cout<<cnt<<endl;
        for(int i = 0;i < n;i++) {
            if(i!=0) cout<<' ';
            cout<<pos[i];
        }
        cout<<endl;
    }
	return 0;
}
