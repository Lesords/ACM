#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//��⣺�Ӻ���ǰ��ɨ��ά���ϴ�ֵ��λ��
//��Ҫ�ж���ȵ����������
//�����ǰλ�õ�ֵ����ջ��λ�õ�ֵ����˵��ջ��λ�ò��������������ջ
//��ǰջΪ�գ�˵��û��ֵ�ȵ�ǰ��Ϊ0������Ϊջ����ֵ
//���Űѵ�ǰλ����ջ

const int MAXN = 3e6+6;
int a[MAXN],ans[MAXN];
stack<int> st;
int main() {
    int n;
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = n;i >= 1;i--) {//�Ӻ���ǰ����
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();//�����ȵ�ǰС��ֵ
        ans[i] = st.empty()?0:st.top();//���㵱ǰ���
        st.push(i);//��ǰλ����ջ
    }
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
