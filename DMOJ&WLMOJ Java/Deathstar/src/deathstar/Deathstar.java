/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package deathstar;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Deathstar {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int out[] = new int[size];
        for(int i=0; i<size-1; i++){
            String temp[] = br.readLine().split(" ");
            for(int j=i+1; j<size; j++){
                out[i]|=Integer.parseInt(temp[j]);
                out[j]|=Integer.parseInt(temp[j]);
            }
        }
        for(int i=0; i<size; i++) System.out.print(out[i]+" ");
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
