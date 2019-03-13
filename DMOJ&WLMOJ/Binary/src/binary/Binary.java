/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package binary;

import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

/**
 *
 * @author liuti
 */


public class Binary {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i =0; i<size; i++){
            String a = Integer.toBinaryString(readInt());
            System.out.println(AddSpaceEvery4Characters(a));
        }
    }
        
    static String AddSpaceEvery4Characters(String s)
    {
        String sWithSpaces = "";
        while (s.length()>0)
        {
            if (s.length()>=4)
            {
                if (sWithSpaces =="")
                    sWithSpaces = s.substring(s.length()-4);
                else
                    sWithSpaces = s.substring(s.length()-4) + " " + sWithSpaces;
                s = s.substring(0, s.length()-4);
            }
            else
            {
                int addingZeros= 4-s.length();
                
                if (sWithSpaces =="")
                    sWithSpaces = s.substring(0);
                else
                    sWithSpaces = s.substring(0) + " " + sWithSpaces;
                for (int i=0;i<addingZeros; i++)
                {
                    sWithSpaces = "0"+sWithSpaces;
                }
                break;
            }
        }
        return sWithSpaces;
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
