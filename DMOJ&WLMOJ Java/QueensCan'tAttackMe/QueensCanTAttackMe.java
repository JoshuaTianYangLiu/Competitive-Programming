/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package queenscan.tattackme;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class QueensCanTAttackMe {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int d = readInt();
        int q = readInt();
        boolean isQueenFree[][] = new boolean[d][d];
        for(int i=0; i<q; i++){
            int y=readInt()-1;
            int x=readInt()-1;
            //diagonals
            isQueenFree[y][x]=true;
            for(int j=1;j<=Math.min(x, y); j++){
                isQueenFree[y-j][x-j]=true;
            }
            for(int j=1; j<=Math.min(y,d-x-1); j++){
                isQueenFree[y-j][x+j]=true;
            }
            for(int j=1;j<=Math.min(d-y-1,d-x-1);j++){
                isQueenFree[y+j][x+j]=true;
            }
            for(int j=1;j<=Math.min(d-y-1,x);j++){
                isQueenFree[y+j][x-j]=true;
            }
            //horizontals
            for(int j=1;j<=x;j++){
                isQueenFree[y][x-j]=true;
            }
            for(int j=1;j<=y;j++){
                isQueenFree[y-j][x]=true;
            }
            for(int j=1;j<=d-x-1;j++){
                isQueenFree[y][x+j]=true;
            }
            for(int j=1;j<=d-y-1;j++){
                isQueenFree[y+j][x]=true;
            }
        }
        int num =0;
        for(int i=0; i<d;i++){
            for(int j=0;j<d; j++){
                if(!isQueenFree[i][j]){
                    num++;
                }
            }
        }
        System.out.println(num);
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
