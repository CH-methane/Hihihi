class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        int[] inDegree = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        //把出现的字符保存在图HashMap里，每个不重复字符对应一个表示有序的有向边
        for(String word : words){
            for(char ch : word.toCharArray()){
                graph.putIfAbsent(ch, new HashSet<>());
            }
        }
        //两两比较相邻字符串之间的关系
        for(int i = 1; i < words.length; ++i){
            String w1 = words[i-1];
            String w2 = words[i];
            if(checkPre(w1,w2) && !w1.equals(w2)) return ""; //检查为不合法输入
            for(int j = 0; j < Math.min(w1.length(), w2.length()); ++j){
                char c1 = w1.charAt(j);
                char c2 = w2.charAt(j);
                //找到不同的字符才说明有顺序关系，把前一个字符指向后一字符，同时后一字符的入度+1
                if(c1 != c2){
                    if(!graph.get(c1).contains(c2)){
                        graph.get(c1).add(c2);
                        inDegree[c2 - 'a']++;
                    }
                    break;
                }
            }
        }
        //把所有入度为0的字符先加入队列，准备拓扑排序
        for(char ch : graph.keySet()){
            if(inDegree[ch - 'a'] == 0) q.offer(ch);
        }
        while(!q.isEmpty()){
            char node = q.poll();
            //从队列出来的这个字符肯定是入度为0，可以确定它的顺序，就把它加进字符顺序的结果里
            sb.append(node);
            //取出当前出来的节点以后，该节点所有的出度(有向边指向所有节点的节点入度)都要减1，若有入度为0的节点字符出现，把它加进队列准备之后的拓扑排序遍历
            for(char next : graph.get(node)){
                inDegree[next - 'a']--;
                if(inDegree[next - 'a'] == 0) q.offer(next);
            }
        }
        //如果结果集里的字符数量和图中所有节点数量相同，说明拓扑排序成功，返回结果集，否则不成功，不存在合法字母顺序
        return sb.length() == graph.size() ? sb.toString() : "";
    }

    public boolean checkPre(String s1, String s2){
        int m = s1.length(), n = s2.length();
        if(m < n) return false;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(s2.charAt(j) != s1.charAt(i)) return false;
            i++;
            j++;
        }
        return true;
    }
}