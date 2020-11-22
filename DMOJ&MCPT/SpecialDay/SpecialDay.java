/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package specialday;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class SpecialDay {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        if(a<2) System.out.println("Before");
        else if(a>2) System.out.println("After");
        else{
            if(b<18) System.out.println("Before");
            else if(b>18) System.out.println("After");
            else System.out.println("Special");
        }
    }
    
}
