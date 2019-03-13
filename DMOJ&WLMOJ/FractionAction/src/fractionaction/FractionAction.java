/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fractionaction;

import java.util.*;

/**
 *
 * @author Joshua
 */
public class FractionAction {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int w = a/b;
        int n = 0;
        int d = 0;
        int temp =gcd(a, b);
        if(temp!=0){
            n = (a-w*b)/temp;
            d = b/temp;
        }
        if(w==0) System.out.println(n+"/"+d);
        else if(n!=0) System.out.println(w + " "+n+"/"+d);
        else System.out.println(w);
        
    }
    public static int gcd(int p, int q) {
        while (q != 0) {
            int temp = q;
            q = p % q;
            p = temp;
        }
        return p;
    }

    
}
