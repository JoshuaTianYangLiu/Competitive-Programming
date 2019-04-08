/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ccchappyorsad;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class CCCHappyOrSad {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input;
        input = new Scanner(System.in);
        String text = input.nextLine();
        int happy= 0;
        int sad =0;
        for(int i =0;i<text.length()-3;i++){
            if(text.subSequence(i, i+3).equals(":-)")){
                happy++;
            }
            if(text.subSequence(i, i+3).equals(":-(")){
                sad++;
            }
        }
        if(happy>sad){
            System.out.println("happy");
        } 
        else if(happy<sad){
            System.out.println("sad");
        }
        else if(happy==0 && sad==0) {
            System.out.println("none"); 
        }
        else if(happy==sad){
            System.out.println("unsure");
        }
    }
    
}
