/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package portalcheck;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PortalCheck {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int rank[];
    static int p[];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int i=0; i<5; i++){
            int q = readInt();
            int count=0;
            rank = new int[q];
            p = new int[q];
            HashMap<String, Integer> h = new HashMap<>(2*q); 
            for(int j=0; j<q; j++){
                p[j]=j;
            }
            int rank[] = new int[q];
            for(int j=0; j<q; j++){
                char a=readCharacter();
                int in1=0;
                int in2=0;
                String in=next();
                if(!h.containsKey(in)){
                    h.put(in, count++);
                }
                in1=h.get(in);
                in=next();
                if(!h.containsKey(in)){
                    h.put(in, count++);
                }
                in2=h.get(in);
                if(a=='p'){
                    int x=findSet(in1);
                    int y=findSet(in2);
                    
                    if (x != y){
                        if (rank[x]>rank[y]) p[y] =x;
                        else p[x]=y;
                    }
                }else{
                    if(findSet(in1)==findSet(in2))System.out.println("connected");
                    else System.out.println("not connected");
                }
            }
        }
    }
    static int findSet(int a){
        while(p[a]!=a){
            a=p[a];
        }
        return a;
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
