/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package dodgeball;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Dodgeball {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        int total=0;
        int temp=0;
        char curChar='1';
        for(int i=0; i<size; i++){
            char a=readCharacter();
            a=a>96?(char)(a-32):a;
            if(curChar==a)temp++;
            else{
                total+=(temp*(temp+1))/2;
                total%=1000000007;
                temp=1;
                curChar=a;
            }
        }
        total+=(temp*(temp+1))/2;
        total%=1000000007;
        System.out.println(total);
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
