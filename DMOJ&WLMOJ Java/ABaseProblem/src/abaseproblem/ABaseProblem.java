/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package abaseproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ABaseProblem {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int base = readInt();
        String a = readLine();
        String b = readLine();
        long out1 = Long.parseLong(switchBase(a,base,10))+Long.parseLong(switchBase(b,base,10));
        long out2 = Long.parseLong(switchBase(a,base,10))*Long.parseLong(switchBase(b,base,10));
        System.out.println(switchBase(Long.toString(out1),10,base));
        System.out.println(switchBase(Long.toString(out2),10,base));
    }
    static String switchBase(String in,int from,int to){
        return Long.toString(Long.parseLong(in, from), to);
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

