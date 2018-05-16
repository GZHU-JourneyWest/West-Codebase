ll a[50];
ll b[50];
ll x,y,sum;
map<ll,ll> M;

void dfs1(ll index,ll sumx,ll sumy,ll e)
{
    if(index==e)
    {
        M[x*sumy-y*sumx]++;
        return ;
    }
    dfs1(index+1,sumx+a[index],sumy+b[index],e);
    dfs1(index+1,sumx,sumy,e);
}

void dfs2(ll index,ll sumx,ll sumy,ll e)
{
    if(index==e)
    {
        sum=sum+M[-x*sumy+y*sumx];
        return;
    }
    dfs2(index+1,sumx+a[index],sumy+b[index],e);
    dfs2(index+1,sumx,sumy,e);
}

int main()
{
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        ll n;
        sum=0;
        M.clear();
        scanf("%lld%lld%lld",&n,&x,&y);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
        }
        dfs1(1,0,0,n/2+1);
        dfs2(n/2+1,0,0,n+1);
        cout<<sum-1<<endl; //-1是因为2部分都没选的情况只有1种 
    }
}