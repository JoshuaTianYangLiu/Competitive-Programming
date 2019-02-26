/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package weakpasswords;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class WeakPasswords {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        for(int a = 0; a<5; a++){
            int in = readInt();
            for(int i = 65; i<91; i++){
                for(int j = 65; j<91; j++){
                    for(int k = 65; k<91; k++){
                        for(int l = 65; l<91; l++){
                            if((Integer.parseInt(Integer.toString(i)+Integer.toString(j)+Integer.toString(k)+Integer.toString(l)))%(i*11+j*101+k*1009+l*10007)==in){
                                System.out.println(((char)i)+""+((char)j)+""+((char)k)+""+((char)l));
                            }
                        }
                    }
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
