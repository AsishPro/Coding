import java.util.*;

public class arraylist{
    
	public static void main(String[] args) {
	    
		ArrayList <String> s=new ArrayList <String>();
		Scanner sc=new Scanner(System.in);
			while(true)
		{
		int ch=sc.nextInt();
	
	switch(ch)
	{
	    case 1:
	        String a=sc.next();
	        s.add(a);
	        System.out.println(s);
	        break;
	   case 2:
	       String c=sc.next();
	      System.out.println(s.remove(c));
	       break;
	   case 3:
	   String b=sc.next();
	       System.out.println(s.indexOf(b));
	       break;
	   case 4:
	       System.out.println("wrong option");
	       break;        
	        
	}
	}
	}
}