import java.util.*;
class fsfs{
	public static void main(String[] args)
	{
		Scanner a= new Scanner(System.in);
		int n=a.nextInt();
		int t=a.nextInt();
		int count=0;
		int[] arr= new int[n];
		Stack <Integer> st= new Stack<Integer>();
		for(int i=0;i<n;i++ )
		{
			arr[i]=a.nextInt();
		}
		count=0;
		for(int i=0;i<n;i++)
		{
			int q= st.search(arr[i]);
            
            
			if(q>0)
			{
				//nothing
			}
			else if(st.size()==t)
			{
				st.removeElementAt(0);
                st.push(arr[i]);
				count+=1;
			}
            else{
            st.push(arr[i]);
            count+=1;
            }
			System.out.println(q+" "+st.size());
		}
		System.out.println(count);
	}
}