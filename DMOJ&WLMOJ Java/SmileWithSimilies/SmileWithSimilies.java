/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smilewithsimilies;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class SmileWithSimilies {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        String[] c = new String[a];
        String[] d = new String[b];
        
        for(int i=0; i<a; i++){
            c[i]=in.next();
        }
        for(int i=0; i<b; i++){
            d[i]=in.next();
        }
        for(int i =0;i<a; i++){
            for(int j=0;j<b;j++){
                System.out.println(c[i]+" as "+ d[j]);
            }
        }
    }
}
