#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 5000005

char col[MAXN];
vector<vector<int> > adj;

char buff[105];
char bu2[105];

///////////HASH CODE
// primo cercano al tamaño la tabla
const int NHASH = 29989;
const int MULT = 31;
typedef struct node *nodeptr;

typedef struct node {
char *word;
int id;
nodeptr next;
}node;

nodeptr bin[NHASH];
unsigned int hash(char *p) {
	unsigned int h = 0;
	for(; *p;p++)
		h = MULT * h + *p;
		return (h % NHASH);
}

int findid(char *s) {
	unsigned int h = hash(s);
	nodeptr p;
	for(p = bin[h]; p != NULL; p = p->next)
		if(strcmp(s,p->word)==0) {
			return p->id;
	}
	return -1;
}

void insertid(char *s,int id) {
	unsigned int h = hash(s);
	nodeptr p;
	
	p = (nodeptr)malloc(sizeof(node));
	p->id = id;
	p->word = (char *)malloc(strlen(s)+1);
	strcpy(p->word,s );
	p->next = bin[h];
	bin[h] = p;
}

// Para ejecutar hay que inicilazar
// y luego insertar cada palabra en incword

int main(int argc, char *argv[]){
    freopen(argv[1],"r",stdin);
    
    int n;
    gets(buff);
    sscanf(buff,"%d",&n);
    adj.resize(n);
    
    int de;
    
    int c=0;
    for(int i=0;i<n;i++){
        gets(buff);
        sscanf(buff,"%s %d",bu2,&de);
        int aa,bb;
        if((aa=findid(bu2))==-1){
            insertid(bu2,c);
            aa=c;
            c++;
        }
        
        for(int j=0;j<de;j++){
            gets(buff);
            
            if((bb=findid(buff))==-1){
                insertid(buff,c);
                bb=c;
                c++;
            }
            adj[aa].push_back(bb);
            adj[bb].push_back(aa);
        }
    }
    //printf("aab\n");
    memset(col,-1,sizeof(col));
    queue<int> q;
    q.push(0);
    col[0]=0;
    
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=0;i<adj[x].size();i++)
            if(col[adj[x][i]]==-1){
                col[adj[x][i]]=(col[x]+1)%2;
                q.push(adj[x][i]);
            }
    }
    
    int a=0,b=0;
    for(int i=0;i<n;i++)
        if(col[i]==0) a++;
        else if(col[i]==1) b++;
    
    cout<<max(a,b)<<" "<<min(a,b)<<endl;

    return 0;
}
