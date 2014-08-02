#include <cstdio>
#include <iostream>
#include<string.h>
using namespace std;
 
char S[100005];
int dp[100005];
int trace[100005];
int hash[11];
int queue[1000005];
int check[11];
 
int main()
{

	//reading input string
	cin>>S;
	int count,loop;
	//getting length of the input string
	int len=strlen(S);
	
	for(int i=0;i<=10;++i)
	{
		hash[i]=-1;
		check[i]=-1;
	}
	
	hash[S[0]-'0']=0;
	trace[0]=0;
	
	/*take each element and store the index of its current index 
	in hash array and previously occured index in 
	corresponding position of trac array*/

	for(int i=1;i<len;++i)
	{
		dp[i]=-1;
		if(hash[S[i]-'0']==-1)
		{
			hash[S[i]-'0']=i;
			trace[i]=i;
		}
		else
		{
			trace[i]=hash[S[i]-'0'];
			hash[S[i]-'0']=i;
		}
	}
	//fisrt element need no jump
	dp[0]=0;
	int head=1;
	int tail=1;
	
	//insert first element into queue
	queue[tail]=0;
	// do bfs traversal and store correcponding jumps in dp array
	while(head<=tail)
	{
		int num=S[queue[head]]-'0';
		int k=dp[queue[head]];
		int index=queue[head];
		++head;
		if((index+1)<len and dp[index+1]==-1)
		{
 
			++tail;
			queue[tail]=index+1;
			dp[index+1]=k+1;
		}
		if((index-1)>=0 and dp[index-1]==-1)
		{
 
			++tail;
			queue[tail]=index-1;
			dp[index-1]=k+1;
		}
		if(check[num]==-1)
		{
 
			loop=hash[num];
			while(trace[loop]!=loop)
			{
 
				if(dp[loop]==-1)
				{
					++tail;
					queue[tail]=loop;
					dp[loop]=k+1;
				}
				loop=trace[loop];
			}
			if(trace[loop]==loop and dp[loop]==-1)
			{
				++tail;
				queue[tail]=loop;
				dp[loop]=k+1;
			}
			check[num]=1;
		}
	}
	cout<<dp[len-1]<<"\n";
	return 0;
}	

