/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cccstrings;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class CCCStrings {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = readLine();
        String b = readLine();
        int pos = 0;
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i)==b.charAt(pos)){
                pos++;
            }
            if(pos==b.length()){
                System.out.println("YES");
                System.exit(0);
            }
        }
        System.out.println("NO");
        
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
