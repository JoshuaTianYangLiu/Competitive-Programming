/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listminimum;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class ListMinimum {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        if(a>=b){
            System.out.println("Congratulations, you are within the speed limit!");
        }else if(b-a<=20){
            System.out.println("You are speeding and your fine is $100.");
        }else if(b-a<=30){
            System.out.println("You are speeding and your fine is $270.");
        }else{
            System.out.println("You are speeding and your fine is $500.");
        }
    }
    
}
//Scanner in = new Scanner(System.in);
//        int b = in.nextInt();
//        int[] a = new int[b];
//        for(int i = 0 ; i<b; i++){
//            a[i]=in.nextInt();
//        }
//        Arrays.sort(a);
//        for(int i = 0; i<b; i++){
//            System.out.println(a[i]);
//        } 