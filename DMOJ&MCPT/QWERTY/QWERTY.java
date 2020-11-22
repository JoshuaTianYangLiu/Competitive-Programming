/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package qwerty;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class QWERTY {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        
        int size =readInt();
        String in = readLine();
        int max =0;
        int c =0;
        for(int i=0; i<size; i++){
            if(a(in.charAt(i))){
                c++;
                if(c>max) max=c;
            }else{
                c=0;
            }
        }
        System.out.println(max);
    }

    static boolean a(char in){
        char letters[] = {'Q','W','E','R','T','A','S','D','F','G','Z','X','C','V','B'}; //15 elements
        for(int j=0; j<15; j++){
            if(in==letters[j])return true;
        }
        return false;
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
