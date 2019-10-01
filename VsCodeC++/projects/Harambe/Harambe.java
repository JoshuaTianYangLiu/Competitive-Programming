/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Harambe {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static String a[] = new String[101];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int in=readInt();
        for(int i=0; i<in; i++){
            String b=next();
            a[b.length()]=b;
        }
        String c = readLine();
        int d=c.length();
        for(int i=d; i>0; i--){
            if(a[i]!=null){
                System.out.println(a[i]);
                break;
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

