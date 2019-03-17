/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg16bitonly;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int size = in.nextInt();
        for(int i=0; i<size; i++){
            long a = in.nextLong();
            long b = in.nextLong();
            long c = in.nextLong();
            if(a*b!=c) System.out.println("16 BIT S/W ONLY");
            else System.out.println("POSSIBLE DOUBLE SIGMA");
        }
    }
    
}
