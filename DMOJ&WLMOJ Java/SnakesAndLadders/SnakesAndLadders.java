/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakesandladders;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class SnakesAndLadders {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = 1;
        int read=1;
        while(a<100){
            read = in.nextInt();
            if(read==0)break;
            if(read>=2 && read<=12 && a+read<=100){
                a+=read;
                if(a==54) a= 19;
                else if(a==90) a= 48;
                else if(a==99) a= 77;
                else if(a==9) a= 34;
                else if(a==40) a= 64;
                else if(a== 67) a= 86; 
                
            }
            System.out.println("You are now on square "+a);
        }
        if(a>=100) System.out.println("You Win!");
        else System.out.println("You Quit!");
    }
    
}
