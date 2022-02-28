class Solution {
    public String reverseOnlyLetters(String s) {
        char[] x=s.toCharArray();
        int t=x.length-1;
        char ii;
        for(int i=0;i<x.length;i++){
            if(Character.isLetter(x[i])){
                while(!Character.isLetter(x[t])){
                    t--;
                }
                if(t<=i){
                    break;
                }
                ii=x[i];
                x[i]=x[t];
                x[t]=ii;
                t--;
            }
        }
        return new String(x);
    }
}