#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�����Ǽ��������Գ���1��λ������
//���Կ��Դ�ͷ��β�������������Ƿ��н������н��������򣬷�������

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x,m;
        cin>>n>>x>>m;
        int l = x,r = x;//��ʼ����Χ��Ϊx
        for(int i = 1;i <= m;i++) {
            int a,b;
            cin>>a>>b;
            if(a>r||b<l) continue;//û�н�����������
            l = min(l, a);//l����Ϊ��С��
            r = max(r, b);//r����Ϊ�ϴ��
        }
        cout<<(r-l+1)<<"\n";//����[l,r]������
    }
    return 0;
}
