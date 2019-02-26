/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assigningpartners;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class AssigningPartners {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        //Not Finished
        int a = readInt();
        String[][] b1 = new String[a/2][2];
        for(int i=0;i<a/2; i++){
            b1[i][0]=next();
            b1[i][1]=next();
        }
        String[][] b2 = new String[a/2][2];
        for(int i=0;i<a/2; i++){
            b2[i][0]=next();
            b2[i][1]=next();
        }
        
        for(int i=0;i<a/2; i++){
            if (!foundInB2(b1[i][0],b1[i][1], b2, a/2))
            {
                System.out.println("bad");
                System.exit(0);
            }
        }
        System.out.println("good");
        
    }

    static boolean foundInB2(String first, String second, String[][] b2, int size)
    {
        
        for(int i=0;i<size; i++){
            if (  b2[i][0].equals(first) && b2[i][1].equals(second)
               || b2[i][0].equals(second) && b2[i][1].equals(first)   
               )
            {
                return true;
            }
        }
        return false;
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
