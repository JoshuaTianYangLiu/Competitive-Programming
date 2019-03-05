/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package diamonds;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Diamonds {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        String out[][] = new String[size][size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                out[i][j]="*";
            }
        }
        int begin = (size+1)/2-1;
        int end = (size+1)/2-1;
        for(int i=1; i<(size+1)/2; i++){
            for(int j=begin; j<end+1; j++){
                out[i][j]=" ";
            }
            begin--;
            end++;
        }
        begin+=2;
        end-=2;
        for(int i=(size+1)/2; i<size-1; i++){
            for(int j=begin; j<end+1; j++){
                out[i][j]=" ";
            }
            begin++;
            end--;
        }
        for(int i=0; i<size; i++){
            String a = "";
            for(int j=0; j<size; j++){
                a+=out[i][j];
            }
            System.out.println(a);
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
