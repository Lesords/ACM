#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺9������ֱ��죬ÿ�������Ե�ǰ��Ϊ�������й���
//ÿ����һ���죬(2x,1y) (2x,2y) (1x,3y) �������

//��⣺��򵥵ķ�����ֱ�ӽ� �����ַ� �����滻���ɣ�����2����1����

struct node{
    int x,y;
};
char s[10][10];
int pos[10] = {0,2,3,1,5,6,4,8,9,7};//��������Ҫ����λ��
vector<node> val;
int main() {
    int t;
    cin>>t;
    while(t--) {
        for(int i = 1;i <= 9;i++) cin>>s[i]+1;
        val.clear();
        val.push_back(node{0,0});//�����0��λ��
        for(int i = 1;i <= 9;i+=3) {
            for(int j = 1;j <= 9;j+=3) {//����9�����񣡣���
                //���ܰ����˳����ң�����
                for(int ii = i;ii < i+3;ii++) {//������ǰ�������������
                    for(int jj = j;jj < j+3;jj++) {//�ҵ���1����λ��
                        if(s[ii][jj]=='1') val.push_back(node{ii,jj});
                    }
                }
            }
        }
        for(int i = 1;i <= 9;i++) {//�Ե�ǰ��Ϊ���������޸ļ���
            s[val[pos[i]].x][val[i].y] = '1';
        }
        for(int i = 1;i <= 9;i++) {
            for(int j = 1;j <= 9;j++) cout<<s[i][j];
            cout<<"\n";
        }
    }
    return 0;
}
