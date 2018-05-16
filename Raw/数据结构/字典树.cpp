#define MAXN 1000//数组最大值，可修改
#define Offset 10000
#define INF 10000 
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0)) 
// -eps<x<eps:0  x>=eps:1  x<=-eps:2 

struct _node
{
	_node *next[26];
	ll num;
	_node()
	{
		num=0;
		for(int i=0;i<26;i++)next[i]=NULL;
	} 
} root;

ll build(char* s) //判断s是否为前缀 是则返回个数 否则返回0 
{
	_node *q=&root;
	ll a;
	ll ans=0;
	for(int i=0;i<strlen(s);i++)
	{
		a=s[i]-'a';
		if(q->next[a]==NULL)
		{
			q->next[a]=new _node(); 
			ans=0;
		} 
		else ans=q->next[a]->num;
		q->next[a]->num++;
		q=q->next[a];
	}
	return ans;
} 

int main()
{
	char s[50];
	while(~scanf("%s",s))
	{
		cout<<build(s)<<endl;
	}
}
