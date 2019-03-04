/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package whatistheromannumeral;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class WhatIsTheRomanNumeral {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int i =0; i<5; i++){
            System.out.println(romanToNum(readLine()));
        }
    }
    static int value(char r){ 
        if (r == 'I') 
            return 1; 
        if (r == 'V') 
            return 5; 
        if (r == 'X') 
            return 10; 
        if (r == 'L') 
            return 50; 
        if (r == 'C') 
            return 100; 
        if (r == 'D') 
            return 500; 
        if (r == 'M') 
            return 1000; 
        return -1; 
    } 
    static int romanToNum(String x){
        int t =0;
        for(int i=0; i<x.length()-1; i++){
            if(value(x.charAt(i))<value(x.charAt(i+1))){
                t-=value(x.charAt(i));
            }else{
                t+=value(x.charAt(i));
            }
        }
        t+=value(x.charAt(x.length()-1));
        return t;
    }
    static String next () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
         return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
         return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
          return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
