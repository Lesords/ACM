#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺ͳ������������0��������Ȼ�������kΪ����������ж��ٸ�1
//������β���������β���е����
//��βֻ��һ��ʱ������Ҫ��һ�����k
//��β����ʱ������һ����Ϊ1��Ȼ��������ĵ���ֻ��һ��β������

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        string s;
        cin>>n>>k>>s;
        int last = -1,now = 0,ans = 0;
        for(int i = 0;i < s.size();i++) {
            //1�������һ��
            if(s[i]=='1'||i==s.size()-1) {
                if(s[i]=='0') {//���һ���Ż��п��ܳ���0
                    if(last==-1) last = i;
                    now = i;
                }
                if(last==-1) continue;//û��0�����������
                if(last==0&&now==i) ans++,last++;//��β�����������
                int dis = now - last + 1;//0������
                if(last!=0&&now!=i) dis-=k;//��ɾ��һ�����k
                if(dis>0) ans += dis/(k+1);// ��� + һ�����λ��
                last = -1;//����last��ֵ
            }
            else {//��λ�����
                if(last==-1) last = i;//����ǵ�һ���Ļ�
                now = i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
