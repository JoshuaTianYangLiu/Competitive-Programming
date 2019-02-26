/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ragaman;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class Ragaman {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = next();
        String b = next();
        int c[] = new int[26];
        int d[] = new int[26];
        int num =0;
        for(int i=0; i<a.length(); i++){
            if(b.substring(i, i+1).equals("*")){
                num++;
            }else{
                d[(int)b.charAt(i) - 97]++;
            }
            c[(int)a.charAt(i) - 97]++;
        }
        for(int i=0; i<26; i++){
            if(c[i]<d[i]){
                System.out.println("N");
                System.exit(0);
            }
        }
        System.out.println("A");
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
