#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//��⣺�洢��ջ���У�ֱ��ģ���ж��Ƿ������ջ����
//��ջ����Ϊ��ջ�����֣�����ջ��ֱ���ҵ����Գ�ջ������
//���ҵ����û�ҵ����޽�

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int q,n;
    cin>>q;
    while(q--) {
        cin>>n;
        stack<int> sta;
        int flag = 0,tmp,pos = 0;                   //flag��¼�Ƿ��н⣬posΪ��ջ���е�λ��
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            if(flag) continue;                      //�޽⣬����Ժ���Ĺ���
            while(sta.empty()||sta.top()!=tmp) {    //��ջΪ�ջ�ջ�����ֲ���������������ջ
                if(pos+1>n) {                       //�������ֶ�ѡ���ˣ����޽�
                    flag = 1;break;
                }
                sta.push(a[++pos]);                 //�ǵ��ƶ�pos��λ��
            }
            if(sta.top()==tmp) sta.pop();           //��������������ջ��
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";

    }
    return 0;
}
