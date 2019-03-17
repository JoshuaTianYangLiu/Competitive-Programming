/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package primecounter;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PrimeCounter {

    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Enter the value of N:");
        int N = Integer.parseInt(keyboard.nextLine());
        int numberOfPrimes =0;
        for(int i=2; i<N; i++){
            if(isPrime(i)){
                numberOfPrimes++;
            }
        }
        System.out.println("Number of Primes: "+numberOfPrimes);
    }
    static boolean isPrime(int a){
        for(int i=2; i<=Math.sqrt(a); i++){
            if(a%i==0){
                return false;
            }
        }
        return true;
    }
}
