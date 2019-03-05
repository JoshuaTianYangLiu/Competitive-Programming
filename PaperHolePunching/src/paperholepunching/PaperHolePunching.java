/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package paperholepunching;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PaperHolePunching {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        boolean letters[] = new boolean[6];
        String temp = readLine();
        int b = 0;
        for(int i=1; i<temp.length(); i++){
            letters[temp.charAt(i)-65]=true;
        }
        int size = readInt();
        for(int i=0; i<size; i++){
            String a =readLine();
            b=0;
            for(int j=1; j<a.length(); j++){
                if(letters[a.charAt(j)-65]){
                    b++;
                }
            }
            if(b==temp.length()-1){
                System.out.println("yes");
            }else{
                System.out.println("no");
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
