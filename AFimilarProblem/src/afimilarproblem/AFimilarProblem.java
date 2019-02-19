/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package afimilarproblem;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

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
        long size = readLong();
        long max = readLong();
        List<Long> a= new ArrayList<Long>();
        for(int i =0; i<size; i++){
            a.add(readLong());
        }
        long finnum=0;
        long num =0;
        int pos =0;
        BigInteger total = new BigInteger("0");
        for(int i=0; i<size; i++){
            pos =i;
            while(total.compareTo(BigInteger.valueOf(max))<0&&pos<size){
                total.add(BigInteger.valueOf(a.get(pos)));
                num++;
                pos++;
            }
            total=BigInteger.ZERO;
            if(num-1>finnum){
                finnum=num-1;
            }
            num=0;
        }
        System.out.println(finnum);
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
