/* 
˹���ֹ�ʽ��Ӧ�� 
��n!��λ�� 
����˹���֣�Stirling����ʽ�Ľ�����⡣�������Ƶ��õ��Ĺ�ʽ�� 
����res=(long)( (log10(sqrt(4.0*acos(0.0)*n)) + n*(log10(n)-log10(exp(1.0)))) + 1 ); 
������n=1��ʱ������Ĺ�ʽ�����ã�����Ҫ��������n=1������� 
�������ַ����ٶȺܿ�Ϳ��Եõ������ 
*/  
#include<bits/stdc++.h> 
using namespace std;
#define ll long long  
int main()  
{  
    int T,n;  
    cin>>T;  
    while(T--)  
    {  
        cin>>n;  
        if(n==1)  
        {  
            cout<<"1"<<endl;  
            continue;  
        }  
        cout<<(ll)( (log10(sqrt(4.0*acos(0.0)*n)) + n*(log10(n)-log10(exp(1.0)))) + 1 )<<endl;  
    }  
    return 0;  
}  
