/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package whoisinthemiddle;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class WhoIsInTheMiddle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int[] a = new int[3];
        a[0] = in.nextInt();
        a[1] = in.nextInt();
        a[2] = in.nextInt();
        Arrays.sort(a);
        System.out.println(a[1]); 
    }
    
}
