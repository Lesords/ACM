#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺dfs��������ѡ��������ж�����Ⱥ��ܿ�ȵ���С���Բ�

int s[15],b[15],op[15],n,ans=INF;
//sΪ��ȣ�bΪ��ȣ�opΪ��ǰʳ���Ƿ�ѡ��
void dfs(int pos) {//posΪ��ǰ��Ҫ�жϵ�ʳ��
    if(pos==n+1) {//n+1ʱ����ʾǰ��n�����Ѿ�ѡ������
        int tmps = 1,tmpb = 0,flag = 1;//�����Ҫ��ʼ��Ϊ1���ˣ�
        for(int i = 1;i <= n;i++) if(op[i]) {//��ѡ��ʱ
            tmps *= s[i],tmpb += b[i];
            flag = 0;
        }
        if(flag) return ;//ȫ��ûѡ
        ans = min(ans,abs(tmps-tmpb));//ȡ��Сֵ
        return ;
    }
    dfs(pos+1);//��ǰ��ѡ
    op[pos] = 1;//��¼��ǰpos
    dfs(pos+1);//��ǰѡ
    op[pos] = 0;//ȡ����¼�����ݵ���һ����ʱ���ٴε���pos�㣩������
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i]>>b[i],ans = min(ans,abs(s[i]-b[i]));
    //ans��¼ ��ѡʳ�� �� ����Ⱥ��ܿ�ȵ���С���Բ�
    dfs(1);//dfs���п�����
    cout<<ans<<endl;
    return 0;
}
