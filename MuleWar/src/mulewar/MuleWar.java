/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mulewar;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class MuleWar {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        for(int i=0;i<size; i++){
            int N = readInt();
            int C = readInt();
            int mule[] = new int[N];
            boolean cov[] = new boolean[N];
            Arrays.fill(cov, true);
            for(int j =0; j<C; j++){
                String q = next();
                if(q.equals("A")){
                    int x = readInt();
                    int pos =readInt();
                    if(cov[pos-1]){
                        mule[pos-1]+=x;
                    }
                }else if(q.equals("Q")){
                    int x = readInt();
                    System.out.println(mule[x-1]);
                }else if(q.equals("G")){
                    int x =readInt();
                    int total =0;
                    for(int k=0; k<x; k++){
                        total+=mule[k];
                    }
                    System.out.println(total);
                }else if(q.equals("L")){
                    int x =readInt();
                    int total =0;
                    for(int k =N-1; k>=N-x; k--){
                        total+=mule[k];
                    }
                    System.out.println(total);
                }else if(q.equals("Covfefe")){
                    int x =readInt();
                    cov[x-1]=false;
                    mule[x-1]=0;
                }
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
