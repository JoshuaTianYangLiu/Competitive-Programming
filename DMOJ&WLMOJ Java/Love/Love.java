/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package love;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class Love {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String s = next();
        int a = s.length();
        int total =0;
        for(int i =0; i<a; i++){
            if(s.charAt(i)=='l'){
                for(int j = i+1; j<a; j++){
                    if(s.charAt(j)=='o'){
                        for(int k=j+1; k<a; k++){
                            if(s.charAt(k)=='v'){
                                for(int l = k+1; l<a; l++){
                                    if(s.charAt(l)=='e'){
                                        total++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
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
