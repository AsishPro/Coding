import java.util.*;
public class scores {
    public static int findBestGrade(int grades[]){
         int max=grades[0];
         for(int i=0;i<grades.length;i++)
            if(grades[i]>max)
              max=grades[i];
        return max;
    }
    public static void printLetterGrades(int[] grades,int bestGrade){
        
        for(int i=0;i<grades.length;i++){
          System.out.print("Student ");
          if(grades[i]>=bestGrade-10)
          System.out.println(i+" score is "+grades[i]+" and grade is A");
          else if(grades[i]>=bestGrade-20)
          System.out.println(i+" score is "+grades[i]+" and grade is B");
          else if(grades[i]>=bestGrade-30)
          System.out.println(i+" score is "+grades[i]+" and grade is C");
          else if(grades[i]>=bestGrade-40)
          System.out.println(i+" score is "+grades[i]+" and grade is D");
          else
          System.out.println(i+" score is "+grades[i]+" and grade is F");
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
           a[i]=sc.nextInt();
        int bestGrade=findBestGrade(a);
        printLetterGrades(a,bestGrade);
    }
}
