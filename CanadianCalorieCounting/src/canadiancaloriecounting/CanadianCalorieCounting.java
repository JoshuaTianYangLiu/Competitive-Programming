/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package canadiancaloriecounting;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class CanadianCalorieCounting {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int count = in.nextInt();
        int total = 0;
        switch(count){
            case 1:
                total+=461;
                break;
            case 2:
                total+=431;
                break;
            case 3:
                total+=420;
                break;
        }
        count = in.nextInt();
        switch(count){
            case 1:
                total+=100;
                break;
            case 2:
                total+=57;
                break;
            case 3:
                total+=70;
                break;
        }
        count = in.nextInt();
        switch(count){
            case 1:
                total+=130;
                break;
            case 2:
                total+=160;
                break;
            case 3:
                total+=118;
                break;
        }
        count = in.nextInt();
        switch(count){
            case 1:
                total+=167;
                break;
            case 2:
                total+=266;
                break;
            case 3:
                total+=75;
                break;
        }
        System.out.println("Your total Calorie count is " + total + ".");
    }
    
}
