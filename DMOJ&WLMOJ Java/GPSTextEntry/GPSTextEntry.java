/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package gpstextentry;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class GPSTextEntry {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String in = readLine();
        int size = in.length();
        int x =0;
        int y=0;
        int mX=0;
        int mY=0;
        int total=0;
        for(int i=0; i<size; i++){
            if(in.charAt(i)>64){
                int a=(int)in.charAt(i)-65;
                mX=a%6;
                mY=a/6;
            }else if(in.charAt(i)==' '){
                mX=2;
                mY=4;
            }else if(in.charAt(i)=='-'){
                mX=3;
                mY=4;
            }else if(in.charAt(i)=='.'){
                mX=4;
                mY=4;
            }
            total+=Math.abs(x-mX);
            total+=Math.abs(y-mY);
            x=mX;
            y=mY;
        }
        System.out.println(total+Math.abs(x-5)+Math.abs(y-4));
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
