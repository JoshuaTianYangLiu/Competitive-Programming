/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rockpaperscissors;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class RockPaperScissors {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a = readInt();
        char player[][] = new char[2][a];
        for(int i=0; i<2; i++){
            for(int j=0; j<a; j++){
                String b = next();
                player[i][j] = b.charAt(0);
            }
        }
        int p1 =0;
        int p2 =0;
        for(int i=0; i<a; i++){
            if(p1Win(player[0][i],player[1][i])){
                p1++;
            }else if(player[0][i]!=player[1][i]){
                p2++;
            }
        }
        System.out.println(p1+" "+p2);
    }

    static boolean p1Win(char p1, char p2){
        if(p1=='r'&&p2=='s'){
            return true;
        }else if(p1=='p'&&p2=='r'){
            return true;
        }else if(p1=='s'&&p2=='p'){
            return true;
        }
        return false;
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
