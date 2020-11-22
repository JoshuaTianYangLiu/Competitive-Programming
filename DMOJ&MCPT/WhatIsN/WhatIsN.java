/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package whatisn;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class WhatIsN {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int i = in.nextInt();
        if(i<=5) System.out.println(((int)i/2)+1);
        else System.out.println((int)(10-i)/2 +1);
        
    }
    
}
