/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rotatingletters;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class RotatingLetters {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        String a = in.next();
        boolean b = true;
        for(int i = 0; i<a.length(); i++){
            String c = a.substring(i, i+1);
            if(c.contains("I")||c.contains("O")||c.contains("S")||c.contains("H")||c.contains("Z")||c.contains("X")||c.contains("N")){}else{
                b=false;
            }
        }
        if(b) System.out.println("YES");
        else System.out.println("NO");
    }
    
}
