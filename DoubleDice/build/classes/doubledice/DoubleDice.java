/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package doubledice;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class DoubleDice {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int size = 0;
        try{
            size = Integer.parseInt(input.readLine());
        }catch(Exception e){}
        int x = 100;
        int y = 100;
        for(int i = 0; i<size; i++){
            String temp = "";
            try{
                temp = input.readLine(); 
            }catch(Exception e){}
            String[] b;
            int[] a = new int[2];
            b = temp.split(" ");
            a[0] = Integer.parseInt(b[0]);
            a[1] = Integer.parseInt(b[1]);
            if(a[0]==(a[1])){}
            else if(a[0]>a[1]) x-=a[1];
            else y-=a[0];
        }
        System.out.println(x);
        System.out.println(y);
    }
    
}
