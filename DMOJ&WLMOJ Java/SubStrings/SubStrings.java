/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package substrings;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SubStrings {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size= readInt();
        for(int a=0; a<size; a++){
            String in=readLine();
            HashMap<String,Integer> m = new HashMap<String,Integer>();
            for(int i=0; i<in.length(); i++){
                for(int j=i; j<=in.length(); j++){
                    m.put(in.substring(i,j), 1);
                }
            }
            System.out.println(m.size());
            
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
