#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define yes "1.000000000000"
#define no "0.000000000000"
using namespace std;
int pos,tpos,unknown,num;
void dfs(int p, int step) {//����������������Ľ������
    //pΪ��ǰλ�ã�stepΪ����
    if(step==unknown) {//�ѵ���unknown��
        if(p==pos) num++;//���Ե���pos������++
        return;
    }
    dfs(p+1,step+1);//���Լ�Ҳ���Լ�
    dfs(p-1,step+1);
}
int main() {
    string a,b;
    cin>>a>>b;
    for(int i = 0;i < a.size();i++) {//�ȼ������������λ��
        if(a[i]=='+') pos++;
        else pos--;
    }
    for(int i = 0;i < b.size();i++) {
        if(b[i]=='+') tpos++;
        else if(b[i]=='-') tpos--;//�ȼ�����֪��λ��
        else unknown++;//ʣ���δ֪���
    }
    if(unknown==0&&tpos==pos) cout<<yes;//û��δ֪�����ѵ�������λ��
    else if(abs(pos-tpos)>unknown) cout<<no;//δ֪���� С�� ����λ�ú͵�ǰ�ľ����
    else {
        dfs(tpos, 0);//numΪ���Ե���Ŀ�ĵ������
        double ans = num*1.0/(1<<unknown);//���п���Ϊ 2^unknown ��
        printf("%.12f\n", ans);
    }
    return 0;
}
