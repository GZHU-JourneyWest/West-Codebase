/* 
斯特林公式的应用 
求n!的位数 
利用斯特林（Stirling）公式的进行求解。下面是推导得到的公式： 
　　res=(long)( (log10(sqrt(4.0*acos(0.0)*n)) + n*(log10(n)-log10(exp(1.0)))) + 1 ); 
　　当n=1的时候，上面的公式不适用，所以要单独处理n=1的情况！ 
　　这种方法速度很快就可以得到结果。 
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
