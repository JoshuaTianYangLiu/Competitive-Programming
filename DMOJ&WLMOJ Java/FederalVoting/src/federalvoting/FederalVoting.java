/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package federalvoting;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class FederalVoting {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            int y = readInt();
            int m = readInt();
            int d = readInt();
            //1989 2 27
            if(y<1989){
                System.out.println("Yes");
            }else if(y==1989){
                if(m<2){
                    System.out.println("Yes");
                }else if(m==2){
                    if(d<28){
                        System.out.println("Yes");
                    }else{
                        System.out.println("No");
                    }
                }else{
                    System.out.println("No");
                }
            }else{
                System.out.println("No");
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
