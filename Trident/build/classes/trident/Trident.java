/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trident;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class Trident {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        for(int i =0; i<a; i++){
            System.out.print("*");
            for(int j=0; j<b;j++){
                System.out.print(" ");
            }
            System.out.print("*");
            for(int j=0; j<b;j++){
                System.out.print(" ");
            }
            System.out.println("*");
        }
        for(int i = 0; i<b*2+2; i++){
            System.out.print("*");
        }
        System.out.println("*");
        for(int j = 0; j<c;j++){
            for(int i = 0; i<b+1; i++){
                System.out.print(" ");
            }
            System.out.println("*");
        }
    }
    
}
