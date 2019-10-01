/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package afimilarproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class AFimilarProblem {

    /**
     * @param args the command line arguments
     */
        // TODO code application logic here
        //To be done
        //Input is long
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        long max=readLong();
        Queue<Long> a = new LinkedList<Long>();
        long curMax=0;
        int cnt=0;
        int out=0;
        for(int i=0; i<size; i++){
            long b=readLong();
            a.add(b);
            curMax+=b;
            cnt++;
            while(curMax>=max){
                long c=a.remove();
                curMax-=c;
                cnt--;
            }
            out=Math.max(cnt,out);
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
