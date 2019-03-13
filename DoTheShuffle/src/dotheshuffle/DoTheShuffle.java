/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package dotheshuffle;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DoTheShuffle {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a = readInt();
        char b[] = {'A','B','C','D','E'};
        int size = readInt();
        while(a!=4){
            for(int j=0; j<size; j++){
                switch(a){
                    case 1:
                        char temp = b[0];
                        for(int i=0; i<4; i++){
                            b[i]=b[i+1];
                        }
                        b[4]=temp;
                        break;
                    case 2:
                        char tempA = b[4];
                        for(int i=4; i>0; i--){
                            b[i]=b[i-1];
                        }
                        b[0]=tempA;
                        break;
                    case 3:
                        char tempB = b[1];
                        b[1]=b[0];
                        b[0]=tempB;
                        break;
                }
            }
            a=readInt();
            size=readInt();
        }
        System.out.println(b[0]+" "+b[1]+" "+b[2]+" "+b[3]+" "+b[4]);
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
