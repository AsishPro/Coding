import java.lang.Exception;

class InvalidAgeException extends Exception

{

public InvalidAgeException (String str)

{

// calling the constructor of parent Exception

super(str);

}

}

// class that uses custom exception InvalidAgeException

public class excep

{

// method to check the age

static void validate (int age) {
try{
if(age < 18){

// throw an object of user defined exception

throw new ArrayIndexOutOfBoundsException("OUT");

}   
}
catch(Exception e){
    throw e;
}


}

// main method

public static void main(String args[])

{

try

{

// calling the method

validate(13);

}

catch (ArrayIndexOutOfBoundsException ex)

{

System.out.println("Caught the exception");

System.out.println("Exception occured: " + ex);

}

System.out.println("rest of the code...");

}

}