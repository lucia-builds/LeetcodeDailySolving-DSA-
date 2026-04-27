#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // visited array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Define connections: {row_change, col_change, allowed_cell_types}
        // Street types: 
        // 1: Left/Right, 2: Up/Down, 3: Left/Down, 4: Right/Down, 5: Left/Up, 6: Right/Up
        
        // Direction vectors: {left, right, up, down}
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        
        // Mapping street types to their respective directions (left, right, up, down)
        unordered_map<int, vector<int>> streetDirs = {
            {1, {0, 1}},    // Left, Right
            {2, {2, 3}},    // Up, Down
            {3, {0, 3}},    // Left, Down
            {4, {1, 3}},    // Right, Down
            {5, {0, 2}},    // Left, Up
            {6, {1, 2}}     // Right, Up
        };
        
        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            
            int r = curr.first;
            int c = curr.second;
            int type = grid[r][c];
            
            // If we reached bottom-right cell
            if(r == m-1 && c == n-1) return true;
            
            // Explore connected directions for current street
            for(int dirIdx : streetDirs[type]){
                int nr = r + dr[dirIdx];
                int nc = c + dc[dirIdx];
                
                // Check bounds
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                    // Check if neighbor connects back to current
                    int nType = grid[nr][nc];
                    for(int nDirIdx : streetDirs[nType]){
                        if(nr + dr[nDirIdx] == r && nc + dc[nDirIdx] == c){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            break;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
