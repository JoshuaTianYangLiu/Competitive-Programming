/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package aclassicproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class AClassicProblem {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        //Figure how this works
        int size = readInt();
        int k = readInt();
        Deque<Integer> max = new LinkedList<Integer>();
        Deque<Integer> min = new LinkedList<Integer>();
        long answer =0;
        int l =0;
        int x[] = new int[size+1];
        for(int i=0; i<size; i++){
            x[i] = readInt();
            while(!max.isEmpty()&&max.peekLast()<x[i])max.removeLast();
            while(!min.isEmpty()&&min.peekLast()>x[i])min.removeLast();
            max.addLast(x[i]); min.addLast(x[i]);
            while(max.peekFirst()-min.peekFirst()>k){
                if(max.peekFirst() == x[l]) max.removeFirst();
                if(min.peekFirst() == x[l]) min.removeFirst();
                l++;
            } 
            answer+=i-l+1;
        }
        System.out.println(answer);
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
