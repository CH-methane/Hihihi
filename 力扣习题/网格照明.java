class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        long N=n;
        int i=0;
        int x=0;
        int y=0;
        int ii=0;
        int xx=0;
        int yy=0;
        int[] ans=new int[queries.length];
        Map<Integer,Integer> row=new HashMap<Integer,Integer>();
        Map<Integer,Integer> col=new HashMap<Integer,Integer>();
        Map<Integer,Integer> le=new HashMap<Integer,Integer>();
        Map<Integer,Integer> ri=new HashMap<Integer,Integer>();
        int[][] dir=new int[][]{{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{0,0}};
        HashSet<Long> m=new HashSet<Long>();
        for(int[] l:lamps){
            x=l[0];
            y=l[1];
            if(m.contains(x*N+y)) {
                continue;
            }
            m.add(x*N+y);
            increment(row,x);
            increment(col,y);
            increment(le,x+y);
            increment(ri,x-y);
        }
        for(i=0;i<queries.length;i++){
            x=queries[i][0];
            y=queries[i][1];
            if(row.containsKey(x)||col.containsKey(y)||le.containsKey(x+y)||ri.containsKey(x-y)){
                ans[i]=1;
            }
            for(ii=0;ii<9;ii++){
                xx=x;
                yy=y;
                xx+=dir[ii][0];
                yy+=dir[ii][1];
                if(xx<0||yy<0||xx>n-1||yy>n-1){
                    continue;
                }
                if(m.contains(xx*N+yy)){
                    m.remove(xx*N+yy);
                    decrement(row,xx);
                    decrement(col,yy);
                    decrement(le,xx+yy);
                    decrement(ri,xx-yy);
                }
            }
        }
        return ans;
    }
    void increment(Map<Integer, Integer> map, int key) {
        map.put(key, map.getOrDefault(key, 0) + 1);
    }
    void decrement(Map<Integer, Integer> map, int key) {
        if (map.get(key) == 1) map.remove(key);
        else map.put(key, map.get(key) - 1);
    }
}