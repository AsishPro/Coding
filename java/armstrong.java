import java.util.Scanner;
import java.lang.Math;
class armstrong{
public static void main(String args[]){
Scanner gc = new Scanner(System.in);
int num = gc.nextInt();
int k=num;
int count=0;
int sum=0;
double b;
while(num!=0){
num=num/10;
count=count+1;
}
num=k;
System.out.print(count+" ");
while(num!=0){
b=num%10;
sum= sum+Math.pow(b,count);
num=num/10;
}

if(sum==k){
System.out.println("armstrong");
}
else{
System.out.println(num);
}
}
}