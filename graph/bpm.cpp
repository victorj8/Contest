#include <iostream>
#include <cstring>

using namespace std;

//Maximum number of nodes in the left side           
const int M=1005;                                   
//Maximum number of nodes in the right side     
const int N=1005;                                     

//graph[i][j]=1,if there is an edge from i to j          
bool graph[M][N];                                   
bool seen[N];                                       
//-1 if they are not matched, otherwise matchL contains the mth index, and matchR the nth index             
int matchL[M], matchR[N]; 
int n,m;

bool bpm( int u )
{
	for(int v=0;v<n;v++) if(graph[u][v])
	{
		if(seen[v]) continue;
		seen[v] = true;

		if(matchR[v]<0||bpm(matchR[v]))
		{
			matchL[u] = v;                                                                                  
			matchR[v] = u;
			return true;
		}                                    
	}
	return false;                                                 
}

//Use example
                                             
int main(){
	while(cin>>m>>n){
		memset(graph,0,sizeof(graph));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>graph[i][j];

		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );

		int cnt = 0;
		for(int i = 0; i < m; i++ ){
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) cnt++;
		}

		cout<<cnt<<endl;
	}
	return 0;
}
