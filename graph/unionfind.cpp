//Estructura union-find

const int MAX=1005;  //Numero de nodos maximo
                              
int p[MAX],rank[MAX];
                          
void make_set(int x){
     p[x] = x;
     rank[x]=0;
}

void link(int x, int y) {
    if(rank[x]>rank[y])
        p[y] = x;
    else 
        p[x] = y;
}

int find_set(int x) {
	if(x != p[x])
		p[x] = find_set(p[x]);
	return p[x];
}

void union_set(int x, int y) {
	link(find_set(x),find_set(y));
}

