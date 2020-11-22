/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iconscaling;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class IconScaling {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        for(int i =0;i<s; i++){
            a("*",s);
            a("x",s);
            a("*",s-1);
            System.out.println("*");
        }
        for(int i = 0; i<s;i++){
            a(" ",s);
            a("x",2*s-1);
            System.out.println("x");
        }
        for(int i = 0; i<s;i++){
            a("*",s);
            a(" ",s);
            a("*",s-1);
            System.out.println("*");
        }
    }
    static void a(String b, int c){
        for(int i =0; i<c; i++){
            System.out.print(b);
        }
    }
    
}
