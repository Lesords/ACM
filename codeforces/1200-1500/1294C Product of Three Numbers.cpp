#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;

//��⣺��ȡn����С����a��Ȼ����ȡn/a����С���ӣ�����ж�ʣ��ֵ�Ƿ�Ϊn����1
//��set��������

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        set<int> st;
        for(int i = 2;i*i <= n;i++) {//����n����С����
            if(n%i==0) {
                st.insert(i);
                n /= i;//ȥ������
                break;
            }
        }
        for(int i = 2;i*i <= n;i++) {//n/a�е���С����
            if(n%i==0&&!st.count(i)) {
                st.insert(i);
                n /= i;
                break;
            }
        }
        //�ж��Ƿ��ҵ��������ӣ��������һ������δ�����Ҳ�Ϊ1
        if(st.size()<2||st.count(n)||n==1) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            st.insert(n);//������һ������
            for(int x:st) cout<<x<<" ";//���3�����ӣ���ݱ�����
            cout<<"\n";
        }
    }
    return 0;
}
