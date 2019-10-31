/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package nextsemiprime;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class NextSemiPrime {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int cnt[]=new int[1000000001];
        for(int i=2; i<1000000001; i++){
            if(cnt[i]==0){
                for(int j=i; j<1000000001; j+=i){
                    cnt[j]++;
                }
            }
        }
        
        System.out.println("e");
        int size=readInt();
        for(int i=0; i<size; i++){
            int point=readInt();
            while(cnt[point++]!=2){
                
            }
            System.out.println(point);
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
