#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��¼���п�ѧ�һ�����ԣ���ͳ������
//�������Ե�ֵ�������Կ�����ɢ��
//Ȼ��������е�Ӱ��ȡ�����������ĵ�Ӱ

const int MAXN = 2e5+5;
int a[MAXN],b[MAXN],au[MAXN],su[MAXN],num[MAXN];
int cnt;
int query(int val) {//��ѯvalֵ��λ��
    int pos = lower_bound(b+1,b+1+cnt,val)-b;
    if(b[pos]!=val) return 0;//���posλ�ò�Ϊval�����ʾ�����ڸ�ֵ
    //���Է���0����Ϊλ��0��ֵΪ0
    return pos;
}
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1,b+1+n);//����
    cnt = unique(b+1,b+1+n)-b-1;//ȥ��
    for(int i = 1;i <= n;i++) {
        num[query(a[i])]++;//ͳ��ÿ����ѧ�һ������
    }
    //��ʼ��indexΪ1���ڶ�û��������˵�ʱ��ѡ���һ����Ӱ����
    int index = 1,numa = 0,nums = 0;
    cin>>m;
    for(int i = 1;i <= m;i++) {
        cin>>au[i];
    }
    for(int i = 1;i <= m;i++) {
        cin>>su[i];
        int tmpa = num[query(au[i])];//��������
        int tmps = num[query(su[i])];//������Ļ����
        //Ҫô�������˶࣬Ҫô��������һ���൫�ǿ���Ļ���˶�
        if(tmpa>numa||(tmpa==numa&&tmps>nums)) {
            numa = tmpa;
            nums = tmps;
            index = i;
        }//��ͬ����£�nums�������ˣ�wa�㣩������
    }
    cout<<index;
    return 0;
}
