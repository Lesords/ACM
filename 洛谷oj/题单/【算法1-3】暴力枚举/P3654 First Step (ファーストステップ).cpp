#include<iostream>//ac
#include<algorithm>
using namespace std;
char map[105][105];
int main() {
    int r,c,k;
    cin>>r>>c>>k;//r��c�� k������
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++) cin>>map[i][j];
    int ans = 0;
    for(int i = 1;i <= r;i++) {//�������п���վλ�ķ�ʽ��
        int tmp = 0;
        for(int j = k;j <= c;j++) {//�ӵ�k����ʼ����i�е�Ԫ��
            int flag = 1;
            //�ж�k�������Ƿ�Ϊ .
            for(int z = j;z >= j-k+1;z--) if(map[i][z]!='.') {
                flag = 0;break;
            }
            tmp += flag;
        }
        ans += tmp;//��ӵ�ǰ�еķ�ʽ��
    }
    for(int j = 1;j <= c;j++) {//�������п���վλ�ķ�ʽ��
        int tmp = 0;
        for(int i = k;i <= r;i++) {//�ӵ�k����ʼ����j�е�Ԫ��
            int flag = 1;
            //�ж�k�������Ƿ�Ϊ .
            for(int z = i;z >= i-k+1;z--) if(map[z][j]!='.') {
                flag = 0;break;
            }
            tmp += flag;
        }
        ans += tmp;//��ӵ�ǰ�еķ�ʽ��
    }
    if(k==1) ans/=2;//���ֻ��Ҫһ���Ļ����������ظ����㣬�����2 ������
    cout<<ans<<endl;
    return 0;
}
