#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//�ӵ㣺��Ҫ�жϸ�У�����һ֧�������һ��λ��ʱ��У�Ļ�������ѧУ��
//��Ϊ��У��������2����Ϊ��У��ֻ��Ҫ��1

vector<int> ord[105];//��¼��ӦѧУ��ѧ������˳��
int num[105],n,val,last;//last��¼��һ��λ��ѧ����ѧУ
//numΪ��ӦѧУ�Ĳ���ѧ������valΪ��ǰѧ��������
int check() {//�жϻ��ж��ٸ�ѧУ��û����
    int cnt = 0;
    for(int i = 1;i <= n;i++) if(num[i]) cnt++;
    return cnt;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>num[i],num[i] *= 10;//ѧ��������*10
    while(1) {//ֱ������ѧ����ѧУ����С�ڵ���1
        for(int i = 1;i <= n;i++) {//��������ѧУ
            if(num[i]==0) continue;//����û��ѧ����ѧУ
            ord[i].push_back(++val);//��˳��������
            num[i]--;//��ǰѧУ��ѧ������--
            last = i;//����last��ֵ����ʾѧУ
        }
        if(check()<=1) break;//С�ڵ���1,��ֹͣ
    }
    int index = 0;//������¼���һ��ѧУ�ı��
    for(int i = 1;i <= n;i++) {
        if(num[i]) {//����һ�������Կ�ֱ���˳�
            index = i;break;
        }
    }
    //��������һ��ѧУ
    if(index) for(int i = 1;i <= num[index];i++) {//����ʣ����������
        if(i==1&&last!=index) val++;//����һ���Ǳ�Уѧ����ֻ��+1������
        else val += 2;
        ord[index].push_back(val);
    }
    for(int i = 1;i <= n;i++) {
        cout<<"#"<<i<<"\n";
        int cnt = 1;//cnt��ʾ��ǰΪ�ڼ���
        for(int j = 0;j < (int)ord[i].size();j++) {
            if(cnt!=1) cout<<" ";
            cout<<ord[i][j];
            if(cnt==10) cout<<"\n",cnt = 1;//��ʮ��һ���س�
            else cnt++;
        }
    }
    return 0;
}
