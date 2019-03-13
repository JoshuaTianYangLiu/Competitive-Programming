/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package purchasingpresents;

import java.util.*;
import java.io.*;
import java.math.BigDecimal;

/**
 *
 * @author liuti
 */


public class PurchasingPresents {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        BigDecimal cost = new BigDecimal(next());
        for(int i=0; i<size; i++){
            BigDecimal p = new BigDecimal(next());
            cost = cost.subtract(p);
        }
        if(cost.doubleValue()<0) System.out.println("Fardin's broke");
        else System.out.println(cost);
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
