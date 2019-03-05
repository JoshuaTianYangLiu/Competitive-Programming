/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package isbn;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class ISBN {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
//        Scanner in = new Scanner(System.in);
//        int a = in.nextInt();
//        int b = in.nextInt();
//        int c = in.nextInt();
//        System.out.println("The 1-3-sum is "+ (91+a+3*b+c));
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter the 9-digit ISBN:");
        String isbn = keyboard.nextLine();
        if(isbn.length()!=9){
            System.out.println("Invalid Number");
        }else{
            int checkSumDigit=0;
            for(int d1 =0; d1<=10; d1++){
                int number = d1+2*(isbn.charAt(8)-'8')
                + 3*(isbn.charAt(7)-'0')
                + 4*(isbn.charAt(6)-'0')
                + 5*(isbn.charAt(5)-'0')
                + 6*(isbn.charAt(4)-'0')
                + 7*(isbn.charAt(3)-'0')
                + 8*(isbn.charAt(2)-'0')
                + 9*(isbn.charAt(1)-'0')
                + 10*(isbn.charAt(0)-'0');
                if(number%11==0){
                    checkSumDigit=d1;
                    break;
                }
            }
            if(checkSumDigit<10){
                System.out.println("ISBN:"+isbn+checkSumDigit);
            }else{
                System.out.println("ISBN:"+isbn+"X");
            }
        }
    }
    
}
