/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pkg12250;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = readLine();
        int count =0;
        while(!a.equals("#")){
            System.out.print("Case "+(++count)+": ");
            if(a.equals("HELLO"))System.out.println("ENGLISH");
            else if(a.equals("HOLA"))System.out.println("SPANISH");
            else if(a.equals("HALLO"))System.out.println("GERMAN");
            else if(a.equals("BONJOUR"))System.out.println("FRENCH");
            else if(a.equals("CIAO"))System.out.println("ITALIAN");
            else if(a.equals("ZDRAVSTVUJTE"))System.out.println("RUSSIAN");
            else System.out.println("UNKNOWN");
            a=readLine();
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
