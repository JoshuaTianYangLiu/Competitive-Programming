/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pkg11498;

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
        int size = readInt();
        while(size!=0){
            int x = readInt();
            int y = readInt();
            for(int i=0; i<size; i++){
                int x1 = readInt();
                int y1 = readInt();
                if(x==x1||y==y1) System.out.println("divisa");
                else if(x1>x&&y1>y) System.out.println("NE");
                else if(x1<x&&y1>y) System.out.println("NO");
                else if(x1>x&&y1<y) System.out.println("SE");
                else if(x1<x&&y1<y) System.out.println("SO");
            }
            size=readInt();
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
