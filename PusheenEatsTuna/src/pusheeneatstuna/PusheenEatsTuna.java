/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pusheeneatstuna;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class PusheenEatsTuna {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            int x = readInt();
            int y = readInt();
            int t = readInt();
            if(intPossible(x,y,t)){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }

    static boolean intPossible(int x,int y, int t){
        for(int j=0;j<(t/x)+1; j++){
            for(int k=0;k<(t/y)+1; k++){
                if(x*j+y*k==t){
                    return true;
                }
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
