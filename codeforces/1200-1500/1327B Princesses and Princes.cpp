#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺��ͷ��β��˳���ȸ����������ӣ�Ȼ������ж��Ƿ��й���û������
//���У�������������ӣ��ҵ���һ��û��ƥ��ļ���

const int MAXN = 1e5+5;
int vis[MAXN],done[MAXN];//done��¼�����Ƿ�ƥ�䣬visΪ�����Ƿ�ƥ��
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,mark = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {//��ʼ��������memset
            vis[i] = done[i] = 0;
        }
        for(int i = 1;i <= n;i++) {
            int tmp,flag = 0;//flag����¼��ǰ�Ƿ�ƥ��ɹ�
            cin>>tmp;
            for(int j = 1;j <= tmp;j++) {
                int tt;
                cin>>tt;
                if(flag) continue;//�����ظ�ƥ��
                if(vis[tt]==0) {
                    done[i] = vis[tt] = 1;//i������tt����ƥ��
                    flag = 1;
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            if(done[i]==0) {//��ʾ��ǰ����û��ƥ��
                mark = 1;//���
                for(int j = 1;j <= n;j++) {
                    if(vis[j]==0) {//�ҵ���һ��û��ƥ������Ӽ���
                        cout<<"IMPROVE\n";
                        cout<<i<<" "<<j<<"\n";
                        break;
                    }
                }
                break;//�ǵý���ѭ��������
            }
        }
        if(!mark) cout<<"OPTIMAL\n";
    }
    return 0;
}
