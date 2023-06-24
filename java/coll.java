import java.util.*;

class coll{
    public static void main(String[] args){
    List<Integer> s=new Vector<Integer>();
    //   Map<Integer,String> s=new HashMap<Integer,String>();
    //    s.put(3,"good");
    //    s.put(2,"aa");
    //    s.put(0,"wtf");
    //    s.put(5,"nice");
    //   for(Map.Entry<Integer, String> et :s.entrySet()){
    //     System.out.println(et);
    //   }
    //   for (Integer t:s.keySet()){
    //     System.out.println(t+" "+s.get(t));
    //   }
    //    s.remove((Integer)3);
        s.add(2);
        s.add(4);
        System.out.print(s);
        Iterator<Integer> it=s.iterator();
       while(it.hasNext()){
        System.out.print(it.next());
       }
    }
}