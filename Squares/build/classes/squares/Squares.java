/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package squares;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class Squares {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        System.out.println("The largest square has side length " + (int) Math.sqrt(in.nextDouble())+".");
    }
    
}
