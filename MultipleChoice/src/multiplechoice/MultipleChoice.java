/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiplechoice;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class MultipleChoice {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int size = in.nextInt();
        String[] s = new String[size];
        String[] a = new String[size];
        in.next();
        for(int i = 0; i<size; i++){
            s[i]=in.nextLine();
        }
        for(int i = 0; i<size; i++){
            a[i]=in.nextLine();
        }
        int answer=0;
        for(int i = 0; i<size; i++){
            if(a[i].equals(s[i]))answer++;
        }
        System.out.println(answer);
    }
    
}
