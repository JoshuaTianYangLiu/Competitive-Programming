/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telemarketer;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class Telemarketer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic 
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();
        boolean e = true;
        if(!(a==8||a==9)) e = false;
        if(!(b==c)) e = false;
        if(!(d==8||d==9)) e = false;
        if(e)System.out.println("ignore");
        else System.out.println("answer");
    }
    
}
