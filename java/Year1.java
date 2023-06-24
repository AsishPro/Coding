class Year1{
    public static void main(String[] args){
      int pop=312032486;
        int birth,death,immi;
        int sec=31536000;
        int i=0,k=0;
        System.out.println("Initial Given population is "+pop);
        while(i<5){
             birth=sec/7;
             death=sec/13;
             immi=sec/45;
             k=birth-death+immi;
             pop+=k;
             i=i+1;
             System.out.println("Then Population after "+(i)+" Year is "+pop);
        }        
    }
}
