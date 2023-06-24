import java.util.*;

class currency2 {
    
    String convert(String number, char from, char to) {
        int baseFrom = getBase(from);
        int baseTo = getBase(to);
        int decimalValue = Integer.parseInt(number, baseFrom);
        System.out.print(decimalValue);
        return Integer.toString(decimalValue, baseTo);
    }
    
    int getBase(char code) {
        switch (code) {
            case 'D':
                return 10;
            case 'B':
                return 2;
            case 'O':
                return 8;
            case 'H':
                return 16;
            default:
                return 0;
        }
    }

}
class Main{
    public static void main(String[] args){
        currency2 o1=new currency2();
        Scanner sc=new Scanner(System.in);
        char a=sc.next().charAt(0);
        char b=sc.next().charAt(0);
        String str=sc.next();
        System.out.print(o1.convert(str, a, b));
    }
}