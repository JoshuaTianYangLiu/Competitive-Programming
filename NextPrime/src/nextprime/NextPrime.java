/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nextprime;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class NextPrime {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        while(!isPrime(a)){
            a++;
        }
        System.out.println(a);
    }
    static boolean isPrime(int a){
        for(int i=2; i<=Math.sqrt(a); i++){
            if(a%i==0) return false;
        }
        if(a==1)return false;
        return true;
    }
    
}
