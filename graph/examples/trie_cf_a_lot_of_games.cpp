// Link to problem (at the moment of creation): https://codeforces.com/contest/456/problem/D

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <unordered_set>

using namespace std;

struct Trie{
    static const int MAX_NODES = 2000005;
    static const int MAX_CHILDREN = 27;
    static const int ROOT_NODE_INDEX = 0;

    Trie(){
        init();
    }

    void init(void){
        memset(next, -1, sizeof(next));
        node_count = 1;
    }

    struct TrieNode{
        char value;
        bool endWord;
        bool can_win;
        bool can_lose;
    } nodes[MAX_NODES];

    inline int get_childrend_index(char c){
        return c - 'a';
    }

    void push_string(string s){
        push_string(s.c_str());
    }

    void push_string(char *s) {
        int current_node = ROOT_NODE_INDEX;
        for(int i=0;s[i]!='\0';i++){
            int next_index = get_childrend_index(s[i]);

            if(next[current_node][next_index] == -1){
                next[current_node][next_index] = node_count++;
            }

            current_node = next[current_node][next_index];
            
            nodes[current_node].value = s[i];            
            if(s[i+1]=='\0') {
                nodes[current_node].endWord = true;
            } else {
                nodes[current_node].endWord = false;
            }
        }
    }

    void traverse(int root){
        nodes[root].can_win = false;
        nodes[root].can_lose = false;

        bool is_leaf = true;
        for(int i=0;i<MAX_CHILDREN;i++)
            if(next[root][i] != -1) {
                is_leaf = false;
                traverse(next[root][i]);
                nodes[root].can_win |=  !nodes[next[root][i]].can_win;
                nodes[root].can_lose |=  !nodes[next[root][i]].can_lose;
            }
        
        if(is_leaf){
            nodes[root].can_win = false;
            nodes[root].can_lose = true;
        }
    }

    int node_count;
    int next[MAX_NODES][MAX_CHILDREN];
};

char input_string[1000005];
Trie trie;

int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=0;i<n;i++){
        scanf("%s", input_string);
        trie.push_string(input_string);        
    }

    trie.traverse(trie.ROOT_NODE_INDEX);

    bool can_first_win = trie.nodes[trie.ROOT_NODE_INDEX].can_win;
    bool can_first_lose = trie.nodes[trie.ROOT_NODE_INDEX].can_lose;

    if(!can_first_win){
        printf("Second");
    }else if(can_first_win&&can_first_lose){
        printf("First");
    }else{
        if(k%2) printf("First");
        else printf("Second");
    }

    printf("\n");

    return 0;
}