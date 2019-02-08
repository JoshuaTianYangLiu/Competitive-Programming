/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quadrantselection;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class QuadrantSelection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        if(a>0&&b>0) System.out.println("1");
        if(a<0&&b>0) System.out.println("2");
        if(a<0&&b<0) System.out.println("3");
        if(a>0&&b<0) System.out.println("4");
    }
    
}
