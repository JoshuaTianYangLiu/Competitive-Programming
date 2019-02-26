/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ribboncolouring;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class RibbonColouring {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        boolean a[] = new boolean[size];
        Arrays.fill(a,false);
        int q = readInt();
        for(int i=0; i<q; i++){
            int b=readInt();
            int c = readInt();
            for(int j=b; j<c; j++){
                a[j]= true;
            }
        }
        int b =0;
        for(int i=0; i<size; i++){
            if(a[i]) b++;
        }
        System.out.println(size-b+" "+b);
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
