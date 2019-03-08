/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package dressingup;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DressingUp {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size =readInt();
        for(int i=0; i<(size+1)/2; i++){
            String out = "";
            for(int j=0; j<2*i+1; j++){
                out+="*";
            }
            for(int j=0; j<size-(2*i+1); j++){
                out+=" ";
            }
            for(int j=0; j<size-(2*i+1); j++){
                out+=" ";
            }
            for(int j=0; j<2*i+1; j++){
                out+="*";
            }
            System.out.println(out);
        }
        for(int i=(size-1)/2 -1; i>=0; i--){
            String out = "";
            for(int j=0; j<2*i+1; j++){
                out+="*";
            }
            for(int j=0; j<size-(2*i+1); j++){
                out+=" ";
            }
            for(int j=0; j<size-(2*i+1); j++){
                out+=" ";
            }
            for(int j=0; j<2*i+1; j++){
                out+="*";
            }
            System.out.println(out);
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
