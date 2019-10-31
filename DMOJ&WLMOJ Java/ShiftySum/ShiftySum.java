/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shiftysum;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class ShiftySum {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int total = 0;
        for(int i =0; i<b+1;i++){
            total+=a*Math.pow(10, i);
        }
        System.out.println(total);
    }
    
}
