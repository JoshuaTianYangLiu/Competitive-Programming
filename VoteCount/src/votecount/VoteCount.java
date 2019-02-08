/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package votecount;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class VoteCount {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        String b = in.next();
        int c=0;
        int d=0;
        for(int i = 0; i<a; i++){
            if (b.charAt(i)=='A') c++; 
            else if (b.charAt(i)=='B') d++; 
        }
        if(c>d) System.out.println("A");
        else if(c<d) System.out.println("B");
        else System.out.println("Tie");
    }
    
}
