/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package steinsnumber;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class SteinsNumber {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int q = readInt();
        
        for(int i=0; i<q;i++){
            int total = 0;
            int a = readInt();
            int b = readInt();
            for(int j=a; j<=b; j++){
                String c = Integer.toString( Integer.parseInt(Integer.toString(j), 10),3);
                if(!c.contains("2")){
                    total++;
                }
            }
            System.out.println(total);
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
