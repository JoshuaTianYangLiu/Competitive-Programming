/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tolower;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ToLower {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = readLine();
        int size = a.length();
        boolean isCap=true;
        String out="";
        for(int i=0; i<size; i++){
            if(isCap&&(a.charAt(i)!=' '&&a.charAt(i)!='.')){
                out+=a.charAt(i);
                isCap=false;
            }else{
                if(a.charAt(i)==' '||a.charAt(i)=='.'){
                    out+=a.charAt(i);
                    if(a.charAt(i)=='.')isCap=true;
                }else{
                    if(a.charAt(i)=='I'&&(i==size-1||a.charAt(i+1)==' ')){
                        out+=a.charAt(i);
                    }else{
                        if(a.charAt(i)>47&&a.charAt(i)<58)out+=a.charAt(i);
                        else out+=(char)(a.charAt(i)+32);
                    }
                }
            }
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
