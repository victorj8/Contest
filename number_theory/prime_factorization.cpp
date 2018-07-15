#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<int,int> prime_factorization(int x){
    map<int,int> res;
    
    while(x%2==0) {x/=2; res[2]++;}
    
    int c=3;
    while(c<=sqrt(double(x))+1)
        if(x%c==0) {x/=c; res[c]++;}
        else c+=2;
    
    if(x>1) res[x]++;
    return res;
}

int main(){
    map<int,int> test = prime_factorization(4840);

    for(auto &elem:test) {
        cout<<elem.first<<" "<<elem.second<<endl;
    }

    return 0;
}