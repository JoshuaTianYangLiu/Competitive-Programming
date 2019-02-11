/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package winningatsports;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

/**
 *
 * @author liuti
 */


public class WinningAtSports {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     * @throws java.lang.Exception
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic 
        BigInteger a[][] = new BigInteger[2001][2001];
        for(int c=0;c<2001; c++){
            for(int b=0;b<2001;b++){
                a[c][b]= BigInteger.ZERO;
                
            }
        }
        for(int i = 1; i<2001; i++){
            a[0][i]=BigInteger.ONE;
        }
        for(int i =2; i<2001; i++){
            for(int j=i;j<2001; j++){
                a[i-1][j]=a[i-1][j].add(a[i-2][j]);
                a[i-1][j]=a[i-1][j].add(a[i-1][j-1]);
            }
        }
        int size = readInt();
        for(int i=0; i<size; i++){
            String b = next();
            String[] xStr;
            xStr = b.split("-");
            int coord[] = new int[2];
            coord[0]= Integer.parseInt(xStr[0]);
            coord[1]= Integer.parseInt(xStr[1]);
            BigInteger s;
            s = BigInteger.ONE;
            for(int j =2; j<=coord[1]; j++){
                s=s.multiply(BigInteger.valueOf((long)4*j-2));
                s=s.divide(BigInteger.valueOf(j+1));
                
            }
            System.out.println("Case #" + (i+1) +": "+ a[coord[1]][coord[0]].remainder(BigInteger.valueOf(1000000007))+" "+s.remainder(BigInteger.valueOf(1000000007)));
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
