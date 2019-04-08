/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package dnaorrna;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DNAOrRNA {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        boolean isRNA = false;
        //U
        boolean isDNA = false;
        //T
        boolean notEither = false;
        String a = readLine();
        for(int i=0; i<size; i++){
            char b = a.charAt(i);
            if(b=='U') isRNA=true;
            else if(b=='T') isDNA=true;
            else if(b!='A'&&b!='C'&&b!='G') notEither = true;
        }
        
        if(!isRNA&&!isDNA&&!notEither)System.out.println("both");
        else if(notEither) System.out.println("neither");
        else if(!isRNA&&isDNA)System.out.println("DNA");
        else if(isRNA&&!isDNA)System.out.println("RNA");
        else System.out.println("neither");
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
