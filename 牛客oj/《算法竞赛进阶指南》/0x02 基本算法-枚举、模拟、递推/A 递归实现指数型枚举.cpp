#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs��������������ǵ������һ������Ϊ��ǰ���������
//ʹ�����㣬ÿ�ж��ǵ��������

int a[20],n;
void dfs(int last, int pos) {
    //�����ǰ״̬
    for(int i = 1;i <= pos;i++) cout<<a[i]<<" ";
    cout<<"\n";
    //�� last+1 Ϊ��㣬��֤���򣡣���
    for(int i = last+1;i <= n;i++) {
        a[pos+1] = i;
        dfs(i, pos+1);
    }
}
int main() {
    cin>>n;
    dfs(0,0);
    return 0;
}
