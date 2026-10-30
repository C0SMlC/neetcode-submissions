class Solution {
   public:
    void calcNumOfIslands(int i, int j, int numRows, int numCols, vector<vector<int>>& grid, vector<vector<int>>& visited, int& maxAreaFromThisCell) {
        if (i < 0 || j < 0 || i >= numRows || j >= numCols || visited[i][j] || grid[i][j] == 0) return;

        visited[i][j] = 1;

        maxAreaFromThisCell++;

        calcNumOfIslands(i + 1, j, numRows, numCols, grid, visited, maxAreaFromThisCell);  
        calcNumOfIslands(i, j - 1, numRows, numCols, grid, visited, maxAreaFromThisCell);  
        calcNumOfIslands(i, j + 1, numRows, numCols, grid, visited, maxAreaFromThisCell); 
        calcNumOfIslands(i - 1, j, numRows, numCols, grid, visited, maxAreaFromThisCell); 

        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        vector<vector<int>> visited(numRows, vector<int>(numCols, 0));

        int overallMaxArea = 0;

        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    int maxAreaFromThisCell = 0;
                    calcNumOfIslands(i, j, numRows, numCols, grid, visited, maxAreaFromThisCell);
                    overallMaxArea= max(overallMaxArea, maxAreaFromThisCell);
                }
            }
        }

        return overallMaxArea;
    }
};
