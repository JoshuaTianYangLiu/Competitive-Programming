/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package thekeytocryptography;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class TheKeyToCryptography {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String in=readLine();
        String key = readLine();
        Queue<Character> q = new LinkedList<Character>();
        String out="";
        for(int i=0; i<key.length(); i++)q.add(key.charAt(i));
        for(int i=0; i<in.length(); i++){
            if(in.charAt(i)-(q.peek()-65)<65)out+=(char)(in.charAt(i)-(q.peek()-65)+26);
            else out+=(char)(in.charAt(i)-(q.peek()-65));
            q.add(out.charAt(i));
            q.remove();
        }
        System.out.println(out);
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
