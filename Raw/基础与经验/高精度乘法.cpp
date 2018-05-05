ll A[10000],B[10000],C[10000];

void mt(string a,string b)
{
	if(a.length()<b.length())swap(a,b);
    ll mi=b.length();
    
    string zero(a.length()-mi,'0');
    b=zero+b;
    for(int i=0;i<=a.length()-1;i++)
    {
        A[i]=a[a.length()-1-i]-48;
        B[i]=b[a.length()-1-i]-48;
    }
     
    ll temp=0,digit=0;
    for(int i=0;i<=a.length()-1;i++)
    {
        for(int t=0;t<=mi-1;t++)
        {
            temp=temp+A[i]*B[t];
            if(i+t>=digit)C[digit++]=temp%10;
            else
			{
				temp=temp+C[i+t];
                C[i+t]=temp%10;
            }
            temp=temp/10;
        }
        while(temp)
        {
            C[digit++]=temp%10;
            temp=temp/10;
        }
    }
    for(;digit>1 && C[digit-1]==0;digit--);
    for(int i=digit-1;i>=0;i--)printf("%lld",C[i]);
    printf("\n");
}

int main()
{
    string a,b;
    cin>>a>>b;
    mt(a,b);
}
