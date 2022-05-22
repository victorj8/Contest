//1293. Shortest Path in a Grid with Obstacles Elimination
//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
//
//Lesson(s): 
// - make sure that the all the variables on which the heuristics function depend on
//   are updated before pushing to the priority_queue

class Solution {
    
    struct state{
        int y,x;
        int remaining;
        int len;
    };
    
    int seen[50][50][50*50];
    
    int dy[4] = {0,-1,0,1};
    int dx[4] = {1,0,-1,0};
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        
        int target_y = r-1;
        int target_x = c-1;
        
        auto comparator = [&](const state &a, const state &b){
            int cost_a = a.len;
            cost_a += abs(target_y-a.y) + abs(target_x-a.x);
            
            int cost_b = b.len;
            cost_b += abs(target_y-b.y) + abs(target_x-b.x);
            
            return cost_a > cost_b;
        };
        
        memset(seen, 0, sizeof(seen));
            
        priority_queue<state, vector<state>, decltype(comparator)> q(comparator);
        state start{0,0,k,0};
        
        seen[0][0][k] = 1;
        q.push(start);
        
        while(!q.empty()){
            state current_node = q.top(); q.pop();
            
            if(current_node.y == r-1 && current_node.x == c-1){
                return current_node.len;
            }
            
            for(int i=0;i<4;i++){
                state next_node;
                next_node.y = current_node.y + dy[i];
                next_node.x = current_node.x + dx[i];
                
                if(next_node.y>=0 && next_node.y<r && next_node.x>=0 && next_node.x<c){
                    if(grid[next_node.y][next_node.x]==1){
                        if(current_node.remaining>0){
                            next_node.remaining = current_node.remaining - 1;
                            if(!seen[next_node.y][next_node.x][next_node.remaining]){
                                seen[next_node.y][next_node.x][next_node.remaining] = 1;
                                next_node.len = current_node.len + 1;
                                q.push(next_node);
                                
                            }
                        }
                    }else{
                        next_node.remaining = current_node.remaining;
                        if(!seen[next_node.y][next_node.x][next_node.remaining]){
                                seen[next_node.y][next_node.x][next_node.remaining] = 1;
                                next_node.len = current_node.len + 1;
                                q.push(next_node);                            
                            }
                    } 
                }
            }
        }
        
        return -1;
    }
};