#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��������������Ա����������޽�
//���������֮�Ͳ����Ա�����������Ϊ���鳤
//�����ҵ���һ�����Ա�����������ȡ�����ֵ��
//�� ���һ�����ɱ�����������ȡǰ���ֵ��

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        int flag = 0,sum = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(a[i]%x) flag = 1;//��ʾ���ֲ�����������
            sum += a[i];
        }
        if(!flag) {//û�г��ֲ����������������޽�
            cout<<"-1\n";
            continue;
        }
        if(sum%x) cout<<n<<"\n";//�ܺͲ�������
        else {
            int l = 0,r = n;
            for(int i = 1;i <= n;i++) {//Ѱ����ߵ㣨����������
                if(a[i]%x) {
                    l = i;break;
                }
            }
            for(int i = n;i >= 1;i--) {//Ѱ���ұߵ㣨����������
                if(a[i]%x) {
                    r = i;break;
                }
            }
            //��������
            cout<<max(n-l,r-1)<<'\n';//ȡ�ϴ�ֵ
        }
    }
    return 0;
}
