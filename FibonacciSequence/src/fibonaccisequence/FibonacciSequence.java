/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonaccisequence;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class FibonacciSequence {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        long x = 1;
        long y = 0;
        long v;
        switch()
        for(int i=0;i<a;i++){
            v=x;
            x=x+y;
            y=v;
            
        }
        System.out.println(y%1000000007);
        
    }
    
    
    
}
