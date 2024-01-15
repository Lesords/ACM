#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：统计所有连续的0的数量，然后计算以k为间隔，可以有多少个1
//特判首尾的情况或首尾都有的情况
//首尾只有一个时：不需要多一个间隔k
//首尾都有时：将第一个设为1，然后加下来的当成只有一个尾来计算

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        string s;
        cin>>n>>k>>s;
        int last = -1,now = 0,ans = 0;
        for(int i = 0;i < s.size();i++) {
            //1或者最后一个
            if(s[i]=='1'||i==s.size()-1) {
                if(s[i]=='0') {//最后一个才会有可能出现0
                    if(last==-1) last = i;
                    now = i;
                }
                if(last==-1) continue;//没有0的情况则跳过
                if(last==0&&now==i) ans++,last++;//首尾都包含的情况
                int dis = now - last + 1;//0的数量
                if(last!=0&&now!=i) dis-=k;//多删除一个间隔k
                if(dis>0) ans += dis/(k+1);// 间隔 + 一个变的位置
                last = -1;//更新last的值
            }
            else {//空位的情况
                if(last==-1) last = i;//如果是第一个的话
                now = i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
