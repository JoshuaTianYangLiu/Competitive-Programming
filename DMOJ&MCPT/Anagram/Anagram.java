/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package anagram;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Anagram {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = readLine().replaceAll("[ ]", "");
        String b = readLine().replaceAll("[ ]", "");
        int c = a.length();
        int aL[] = new int[26];
        int bL[] = new int[26];
        
        for(int i=0; i<c; i++){
            aL[a.charAt(i)-65]++;
            bL[b.charAt(i)-65]++;
        }
        for(int i=0; i<26; i++){
            if(aL[i]!=bL[i]){
                System.out.println("Is not an anagram.");
                System.exit(0);
            }
        }
        System.out.println("Is an anagram.");
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
