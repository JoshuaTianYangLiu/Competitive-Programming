/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package trik;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class Trik {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = next();
        boolean b[] = {true,false,false};
        boolean temp = false;
        for(int i=0; i<a.length(); i++){
            if(a.substring(i,i+1).equals("A")){
                temp = b[1];
                b[1]=b[0];
                b[0]=temp;
            }
            if(a.substring(i,i+1).equals("B")){
                temp = b[2];
                b[2]=b[1];
                b[1]=temp;
            }
            if(a.substring(i,i+1).equals("C")){
                temp = b[2];
                b[2]=b[0];
                b[0]=temp;
            }
        }
        for(int i =0; i<3; i++){
            if(b[i]){
                System.out.println(i+1);
            }
        }
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
