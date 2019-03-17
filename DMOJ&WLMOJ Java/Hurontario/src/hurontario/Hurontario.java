/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hurontario;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Hurontario {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = next();
        String b = next();
        int aL=a.length();
        int bL=b.length();
        int charSame =0;
        int marker =0;
        out:
        for(int i=Math.max(0, aL-bL); i<aL;){
            if(a.charAt(i)==b.charAt(marker)){
                while(a.charAt(i)==b.charAt(marker)){
                    i++;
                    charSame++;
                    marker++;
                    if(i==aL){
                        break out;
                    }
                }
            }
            i++;
            if(i==aL)charSame=0;
        }
        pr.print(a);
        pr.println(b.substring(charSame, bL));
        pr.close();
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
