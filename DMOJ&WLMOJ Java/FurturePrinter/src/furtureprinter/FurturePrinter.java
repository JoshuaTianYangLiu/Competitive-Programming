/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package furtureprinter;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class FurturePrinter {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int a=0; a<5; a++){
        int n = readInt();
            int width = n %2 == 0 ? n - 1 : n;
            for (int i = 0; i < n; i++) {
                int w = i% 2 == 0? i + 1 : i;
                for(int j=0; j<(width-w)/2; j++)System.out.print(".");
                for(int j=0; j<w; j++)System.out.print("*");
                for(int j=0; j<(width-w)/2; j++)System.out.print(".");
                System.out.println();
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
