#include<iostream>//ac
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����ÿ��k�Ӷζ���Ҫ��ȣ���ô����Ҫk������ѭ����k����ѭ��
//���Գ���k���������Թ���ѭ����С��k����������1����

const int MAXN = 105;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        set<int> st;//ͳ�Ʋ�ͬ���ĸ���
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            st.insert(a[i]);
        }
        if(st.size()>k) {//����k�����޽⣬����������
            cout<<"-1\n";
            continue;
        }
        cout<<n*k<<"\n";//ÿ������������ͬ��˳������һ���������棩
        for(int i = 1;i <= n;i++) {
            for(int val:st) {//�������ֵ�������
                cout<<val<<" ";
            }
            //����k������1����
            for(int j = 1;j <= k-st.size();j++) cout<<"1 ";
        }
        cout<<"\n";
    }
}
