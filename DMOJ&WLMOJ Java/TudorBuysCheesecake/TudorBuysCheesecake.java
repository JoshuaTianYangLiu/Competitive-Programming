/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tudorbuyscheesecake;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class TudorBuysCheesecake {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int letters[] = new int[26];
        String a = readLine();
        String b = readLine();
        for(int i=0;i<a.length(); i++){
            letters[a.charAt(i)-65]++;
        }
        for(int i=0; i<b.length(); i++){
            if(letters[b.charAt(i)-65]>0){
                letters[b.charAt(i)-65]--;
            }
        }
        int total=0;
        for(int i=0;i<26; i++){
            total+=letters[i];
        }
        System.out.println(total);
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
