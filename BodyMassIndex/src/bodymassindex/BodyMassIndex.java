/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bodymassindex;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class BodyMassIndex {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        double b = in.nextDouble();
        double BMI = a/(b*b);
        if(BMI>25){
            System.out.println("Overweight");
        }else if(BMI<18.5){
            System.out.println("Underweight");
        }else{
            System.out.println("Normal weight");
        }
    }
    
}
