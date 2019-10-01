/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package perlconv;
import java.io.*;
import java.util.*;
/**
 *
 * @author Joshua
 */
public class PerlConv {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String a="Hail the Dark Lord Quantum!";
        for(int i=0; i<a.length(); i++){
            for(int j=33; j<127; j++){
                int b=a.charAt(i)^j;
                System.out.println((char)b+" "+(char)j+" "+a.charAt(i));
            }
        }
    }
    
}
