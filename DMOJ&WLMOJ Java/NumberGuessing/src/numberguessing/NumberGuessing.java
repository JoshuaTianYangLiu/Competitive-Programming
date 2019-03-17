/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package numberguessing;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class NumberGuessing {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            int a = readInt();
            int b = readInt();
            int n = readInt();
            for(int j=0; j<n; j++){
                int c = Math.round((a+b)/2);
                System.out.println(c);
                String in = readLine();
                if(in.equals("CORRECT")){
                    break;
                }else if(in.equals("TOO_SMALL")){
                    b=c;
                }else if(in.equals("TOO_BIG")){
                    a=c;
                }
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
