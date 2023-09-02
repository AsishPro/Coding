public class trial {
    public static void main(String[] args){
        String s="1101011";
        // System.out.print(s.substring(2,s.length()));
        String k="";
        int j=5;
        // k+=s.substring(j, Math.min(s.length(),j+1));
        k+=s.substring(6,s.length());
        System.out.print(k);
    }
}
