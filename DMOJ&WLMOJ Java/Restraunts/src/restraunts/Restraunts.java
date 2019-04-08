/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package restraunts;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Restraunts {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        boolean isRestr[] = new boolean[size];
        int t = readInt();
        int k = readInt();
        int v = readInt();
        for(int i=0; i<v; i++)isRestr[readInt()-1]=true;
        int count=0;
        int total=0;
        Queue<Boolean> q = new LinkedList<Boolean>();
        for(int i=0; i<t; i++){
            if(k-count>=t-i){
                q.add(true);
                count++;
                if(!isRestr[i])total++;
            }else{
                q.add(isRestr[i]);
                if(isRestr[i])count++;
            }
        }
        for(int i=t; i<size; i++){
            if(q.peek())count--;
            if(isRestr[i])count++;
            if(count<k){
                count++;
                total++;
                q.add(true);
            }else{
                q.add(isRestr[i]);
            }
            q.remove();
        }
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
