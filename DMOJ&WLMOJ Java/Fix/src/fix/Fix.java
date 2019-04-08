/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fix;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Fix {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            String a = readLine();
            String b = readLine();
            String c = readLine();
            if(a.startsWith(b)||a.startsWith(c)||b.startsWith(a)||b.startsWith(c)||c.startsWith(b)||c.startsWith(a)||a.endsWith(b)||a.endsWith(c)||b.endsWith(a)||b.endsWith(c)||c.endsWith(b)||c.endsWith(a)) System.out.println("No");
            else System.out.println("Yes");
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
