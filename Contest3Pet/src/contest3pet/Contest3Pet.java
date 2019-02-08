/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package contest3pet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Joshua
 */
public class Contest3Pet {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = null;
        String coded = "";
        int r = 0;
        int c = 0;
        int a = 0;
        int b = 0;
        String decoded = "";
        input = new BufferedReader(new InputStreamReader(System.in));
        try {
            coded = input.readLine();
        } catch (Exception e) {}
        
        for(int i = 1;i<=(int)Math.sqrt((double)coded.length());i++){
            if(coded.length()%i==0){
                r=i;
                c=coded.length()/i;
            }
        }
        int i = 0;
        char table[][] = new char[r][c];
        
        for(int e = 0; e<c; e++){
            for(int d = 0; d<r; d++){
                table[d][e]=coded.charAt(i);
                i++;
            }
        }
        
        for(int e = 0; e<r; e++){
            for(int d = 0; d<c; d++){
                decoded+=table[e][d];
            }
        }
        System.out.println(decoded);
    }
}
