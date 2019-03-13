/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rolethedice;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class RoleTheDice {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        if (a>9) a=9;
        if (b>9) b=9;
        int total=0;
        for(int i=1; i<a+1; i++){
            for(int j=1; j<b+1; j++){
                if(i+j==10){
                    total++;
                    break;
                }
            }
        }
        if(total==1) System.out.println("There is 1 way to get the sum 10.");
        else System.out.println("There are "+total+" ways to get the sum 10.");
    }
    
}
