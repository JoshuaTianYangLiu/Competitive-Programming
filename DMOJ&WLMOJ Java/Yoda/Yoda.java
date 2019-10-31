/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package yoda;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Yoda {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = next();
        String b = next();
        
        char end = b.charAt(b.length()-1);
        
        if(b.length()>1){
            a=a.toLowerCase();
            String start = b.charAt(1)+"";
            start=start.toUpperCase();
            b=b.substring(2, b.length()-1);
            
            System.out.printf("%s%s %s%c",start,b,a,end);
        }else{
            System.out.printf("%s%s",a,end );
        }
        
    }


    static String next () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine(),",");
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
