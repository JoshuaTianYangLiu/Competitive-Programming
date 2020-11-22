/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package triangletimes;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class TriangleTimes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        if(a+b+c!=180){
            System.out.println("Error");
        }else if(a==60&&b==60&&c==60){
            System.out.println("Equilateral");
        }else if(a!=b&&b!=c&&c!=a){
            System.out.println("Scalene");
        }else{
            System.out.println("Isosceles");
        }
    }
    
}
