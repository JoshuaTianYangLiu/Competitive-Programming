/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snakesandladders2;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class SnakesAndLadders2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = 1;
        int read=1;
        while(a<100){
            read = Integer.parseInt(in.nextLine());
            if (read<=0)
                break;
            a+=read;
            if(a==54) a= 19;
            else if(a==90) a= 48;
            else if(a==99) a= 77;
            else if(a==9) a= 34;
            else if(a==40) a= 64;
            else if(a== 67) a= 86; 
            if (a ==11)
                System.out.println("You are now on square 11");
            else if(a==19)
                System.out.println("You are now on square 19");
            else
                System.out.println("You "+ a);
        }
        if(a>=100) System.out.println("You Win!");
        else System.out.println("You Quit!");
    }
    
}
