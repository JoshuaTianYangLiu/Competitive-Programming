/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package aceisbase;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ACEIsBase {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        long a=readLong();
        for(long i=0; i<a; i++){
         
                    
            String b = Long.toHexString(i);
            if(!(b.contains("0")||b.contains("1")||b.contains("2")||b.contains("3")||b.contains("4")||b.contains("5")||b.contains("6")||b.contains("7")||b.contains("8")||b.contains("9")||b.contains("b")||b.contains("d")||b.contains("f"))){
                System.out.print(i+",");
            }
        }
    }
    
    int getHexBits(long value)
    {
        int hexBits=0;
        while (value != 0)
        {
            value = value>>4;
            hexBits++;
        }
        return hexBits;
    }

    static boolean isACE(long value){
    
        while ((value&0x0f)==10 || (value&0x0f) == 12 || (value&0x0f)==14)
        {
            value=value>>4;
            if (value == 0)
                return true;
            
        }
        return false;
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
