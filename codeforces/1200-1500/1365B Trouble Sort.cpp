#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��������������ֵ��϶���������
//������Ҫ�ж��Ƿ��Ѿ�����

const int MAXN = 505;
int a[MAXN],b[MAXN];
int main() {
    int t;cin>>t;
    while(t--) {
        int n,one = 0,zero = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            b[i]?one++:zero++;//ͳ�ƶ�Ӧ���͵�����
        }
        if(is_sorted(a+1,a+1+n)) {//�Ѿ��������н�
            cout<<"Yes\n";
            continue;
        }
        if(one>=1&&zero>=1) cout<<"Yes\n";//�����������Ͷ��в����н�
        else cout<<"No\n";
    }
    return 0;
}
