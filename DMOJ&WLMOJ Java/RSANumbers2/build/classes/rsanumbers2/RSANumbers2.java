/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsanumbers2;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class RSANumbers2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
            // TODO code application logic here
        int a = 0;
        int b = 0;
        Scanner input;
        input = new Scanner(System.in);
        a=input.nextInt();
        b=input.nextInt();

        int counter = 0;
        for (int i=a; i<=b;i++){
            if (isTwoPrimeFactors(i))
                counter++;
        }
        System.out.println("The number of RSA numbers between " + a +" and " + b+" is "+counter);
        // TODO code application logic here
    }
    
    static boolean isTwoPrimeFactors(int number)
    {
        //int mid = (int)(Math.sqrt(number))+1;
        int count=0;
        for (int i=2; i<number; i++)
        {
            if (number%i ==0)
                count++;
        }
        if (count == 2)
            return true;
        else
            return false;
    }
}
