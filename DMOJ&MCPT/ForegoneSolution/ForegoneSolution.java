/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package foregonesolution;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ForegoneSolution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        for(int j=0; j<size; j++){
            String a=readLine();
            String c="";
            String d="";
            boolean searched=false;
            for(int i=0; i<a.length(); i++){
                if(a.charAt(i)=='4'){
                    c+="2";
                    d+="2";
                    searched=true;
                }else{
                    c+=a.charAt(i);
                    if(searched)d+="0";
                }
            }
            if(d.length()==0)d="0";
            System.out.println("Case #"+(j+1)+": "+c+" "+d);
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
