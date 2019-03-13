/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package blindfold;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Blindfold {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        //Not done
        int y = readInt();
        int x = readInt();
        boolean hasWall[][] = new boolean [y][x];
        for(int i=0; i<y; i++){
            String in = readLine();
            for(int j=0; j<x; i++){
                if(in.charAt(j)=='X'){
                    hasWall[i][j]=true;
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
