/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;




/**
 *
 * @author Joshua
 */
public class HelloWorld {

    /**
     * @param args the command line arguments
     */
//        public static int FindNumber(int a,int b, int c, int d){
//            int case1 = a+b;
//            int case2 = a-b;
//            int case3 = c+d;
//            int case4 = c-d;
//            if(case1==case3){
//                return case1;
//            }
//            if(case1==case4){
//                return case1;
//            }
//            if(case2==case3){
//                return case2;
//            }
//            if(case2==case4){
//                return case2;
//            }
//            return '0';
//        }
   public static void main(String[] args) {
    public class old
    {
        public static void SoM(){
       private int a = 0;
        for(int i = 5; i<=110; i+=7){
                a++;
        }
        private int[] set = new int[a];
        private int b = 5;
        
        for(int i = 0; i<a; i++){            
            set[i]=b;
            b+=7;
        }
        System.out.println(set[15]);
        private int [] possibilities = new int[100];
        for(int i=0; i<100;i++){
            possibilities[i]=-1;
        }
        private int d = 0;
        for(int i = 0; i<a-3; i++){
            for(int j = i+1; j<a-2; j++){
                for(int k = j+1; k<a-1; k++){
                    for(int l = k+1; l<a; l++){
                        int c = -1;
                        for(int m = 0; m<100; m++){
                            if(set[i] +set[j]+set[k]+set[l] == possibilities[m]){
                                c=1;    
                            }
                        }
                        if(c == -1){
                            possibilities[d]=set[i]+set[j]+set[k]+set[l];
                            d++;
                        }
                    }
                }
            }
        } 
        System.out.println(a);
        System.out.println(d);
        System.out.println("-------------------------");
        
        
        //New problem
        int counter = 0;
        for(int ab = -13; ab<=13; ab++){
            for(int bc= -13;bc<=13; bc++){
                for(int cd = -13; cd<=13; cd++){
                    if(ab*ab+bc*bc+cd*cd==169){
                        counter++;
                        System.out.println(ab+" "+bc+" "+cd);
                    }
                }
            }
        }
        System.out.println(counter);
        
        System.out.println("--------------------");
        }   
    }
        SoM();
    
    
    
        //New problem
//        long counter1 = 0;
//        long counter2 = 0;
//        boolean counter3 = false;
//        for(long i = 10000000; i>=0; i-- ){
//            counter1 = 0;
//            counter3 = false;
//            for(long j = i; j<i+999; j++){
//                counter1+=2*j-1;
//            }
//            
//            if((counter1 <999999999) && (counter1 >counter2) ){
//                for(int k = 0; k<=1000; k++){
//                    if(k*k*k==counter1){
//                    counter3 = true;
//                    counter2 = counter1;
//                    }
//                }
//            }
//        }
//        System.out.println(counter2);
//        System.out.println(counter1);
    }
}    
//       Scanner sc = new Scanner(System.in);
//       int abc = Integer.parseInt(sc.nextLine());
//
//       int b = -1;
//       int c = -1;
//       String[] name = new String[abc];
//       String[] gender = new String[abc];
//       int[] votes = new int[abc];
//       
//       for(int i = 0; i<abc; i++){
//           System.out.println("Name: ");
//           name[i]=sc.nextLine();
//           System.out.println("gender: ");
//           gender[i]=sc.nextLine();
//           System.out.println("votes: ");
//           votes[i]=Integer.parseInt(sc.nextLine());
//       }
//name[0]="a";
//name[1]="b";
//name[2]="c";
//gender[0]="F";
//gender[1]="M";
//gender[2]="M";
//votes[0]=5;
//votes[1]=4;
//votes[2]=7;
//       for(int i = 0; i<abc; i++){
//           if(gender[i].compareTo("M") == 0){
//               if(b != -1){
//                   if(votes[b]<votes[i]){
//                        b=i;
//                   }
//               }else
//               {
//                    b=i;
//               }
//           }
//           else{
//               if(c != -1){
//                   if(votes[c]<votes[i]){
//                        c=i;
//                   }
//               }else{
//                    c=i;
//               }
//           }
//       }
////       System.out.print(a[c*3-3]+" ");
//       System.out.print(name[c]+" ");
//       System.out.print(name[b]);
//       
//       
//       Scanner sc = new Scanner(System.in);
//       int cases = sc.nextInt();
//       int[] lines = new int[cases*4];
//       for(int i = 0; i<(cases*4); i++){
//           lines[i] = sc.nextInt();
//       }
//       for(int i = 1; i<((lines.length/4)+1);i++){
//           System.out.println(FindNumber(lines[4*i-4],lines[4*i-3],lines[4*i-2],lines[4*i-1]));
//       }  
////       DateCalculate a = new DateCalculate();
//        String totalText = "Here is the perfect system for cleaning your room. First, move all of the items that do not have a proper place to the center of the room. Get rid of at least five things that you have not used within the last year. Take out all of the trash, and place all of the dirty dishes in the kitchen sink. Now find a location for each of the items you had placed in the center of the room. For any remaining items, see if you can squeeze them in under your bed or stuff them into the back of your closet. See, that was easy!";
//        String[] sentence = totalText.split("\\.");
//        Object[] words = new Object[sentence.length];
//        for(int i = 0; i < sentence.length; i++){
//            words[i] = sentence[i].split(" ");
//        }
//        for(int i = 0; i < sentence.length; i++){
//            for(int j = 0; j < ((String[])words[i]).length; j++){
//                System.out.println(((String[])words[i])[j]);
//            }
//        }
       
       
//        Student joshua = new Student("Joshua", "Liu");
//        Student james = new Student("James", "Lin");
//        joshua.firstName = "Joshua";
//        joshua.lastName = "Liu";
//        james.lastName = "Lin";
//        james.firstName = "James";
//        joshua.MakeFriends(james);
//        james.MakeFriends(joshua);
//        joshua.GoToSchool();
//        james.GoToSchool();
//        Flight f1 = new Flight();
//        CargoFlight f2 = new CargoFlight();
//        Flight f3 = new CargoFlight();
//        CargoFlight f4 = new Packages();
//        int a = 5;
//        System.out.println(f1.GetSeats());
//        System.out.println(f2.GetSeats());
//        System.out.println(f3.GetSeats());
//        System.out.println(f4.Test());
//        Integer A = 20*500;
//        Integer B = 10*1000;
//        Integer C = 8*8*2;
//        Integer D = 128;
//        System.out.println(A);
//        System.out.println(A==B);
//        System.out.println(C==D);
//    }
//   
//}
