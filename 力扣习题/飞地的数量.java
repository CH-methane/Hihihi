class Solution {
    public int numEnclaves(int[][] grid) {
        int[][] dir = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
        Deque<Integer> d = new ArrayDeque<>();
        Set<Integer> vis = new HashSet<>();
        int i=0;
        int ii=0;
        int t=0;
        int tt=0;
        int m=grid.length;
        int n=grid[0].length;
        for(i=0;i<m;i++){
            for(ii=0;ii<n;ii++){
                if(grid[i][ii]==1){
                    tt++;
                    if(i==0||ii==0||i==m-1||ii==n-1){
                        d.add(i*1000+ii);
                        vis.add(i*1000+ii);
                        t++;
                    }
                }
            }
        }
        while(!d.isEmpty()){
            int p = d.pollFirst();
            int px = p / 1000;
            int py = p - px * 1000;
            for (i = 0; i < 4; i++) {
                int nx = px + dir[i][0];
                int ny = py + dir[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n){
                    continue;
                }
                if (vis.contains(nx * 1000 + ny)) 
                    continue;
                if (grid[nx][ny]==1){
                    d.add(nx*1000+ny);
                    vis.add(nx*1000+ny);
                    t++;
                }
            }
        }
        return tt-t;
    }
}