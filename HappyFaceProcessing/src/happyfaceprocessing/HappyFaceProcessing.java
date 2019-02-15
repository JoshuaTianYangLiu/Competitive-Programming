/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package happyfaceprocessing;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class HappyFaceProcessing {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        List<int[]> s = new ArrayList<int[]>();
        s.add(new int[] {20,10,20});
        s.add(new int[] {16,4,10,4,16});
        s.add(new int[] {14,2,18,2,14});
        s.add(new int[] {12,2,22,2,12});
        s.add(new int[] {11,1,26,1,11});
        s.add(new int[] {9,2,28,2,9});
        s.add(new int[] {8,1,32,1,8});
        s.add(new int[] {7,1,34,1,7});
        s.add(new int[] {6,1,36,1,6});
        s.add(new int[] {5,1,38,1,5});
        s.add(new int[] {5,1,38,1,5});
        s.add(new int[] {4,1,40,1,4});
        s.add(new int[] {3,1,42,1,3});
        s.add(new int[] {2,2,8,4,18,4,8,2,2});
        s.add(new int[] {2,1,7,2,4,2,14,2,4,2,7,1,2});
        s.add(new int[] {2,2,6,1,6,1,14,1,6,1,6,2,2});
        s.add(new int[] {1,1,2,1,4,1,8,1,12,1,8,1,4,1,2,1,1});
        s.add(new int[] {1,1,3,5,3,2,3,14,3,2,3,5,3,1,1});
        s.add(new int[] {1,1,7,1,3,2,3,1,12,1,3,2,3,1,7,1,1});
        s.add(new int[] {1,1,7,1,8,1,12,1,8,1,7,1,1});
        s.add(new int[] {0,1,9,1,6,1,14,1,6,1,9,1});
        s.add(new int[] {0,1,9,2,4,2,14,2,4,2,9,1});
        s.add(new int[] {0,1,11,4,18,4,11,1,0});
        s.add(new int[] {0,1,48,1,0});
        s.add(new int[] {0,1,24,1,23,1,0});
        s.add(new int[] {0,1,24,1,23,1,0});
        s.add(new int[] {0,1,24,1,23,1,0});
        s.add(new int[] {0,1,23,1,24,1,0});
        s.add(new int[] {0,1,22,1,25,1,0});
        s.add(new int[] {1,1,46,1,1});
        s.add(new int[] {1,1,46,1,1});
        s.add(new int[] {1,1,46,1,1});
        s.add(new int[] {1,1,46,1,1});
        s.add(new int[] {2,1,44,1,2});
        s.add(new int[] {2,1,44,1,2});
        s.add(new int[] {3,1,9,2,20,2,9,1,3});
        s.add(new int[] {3,1,9,4,16,4,9,1,3});
        s.add(new int[] {4,1,9,5,12,5,9,1,4});
        s.add(new int[] {5,1,9,6,8,6,9,1,5});
        s.add(new int[] {5,1,10,18,10,1,5});
        s.add(new int[] {6,1,11,14,11,1,6});
        s.add(new int[] {7,1,12,10,12,1,7});
        s.add(new int[] {8,1,32,1,8});
        s.add(new int[] {9,2,28,2,9});
        s.add(new int[] {11,1,26,1,11});
        s.add(new int[] {12,2,22,2,12});
        s.add(new int[] {14,2,18,2,14});
        s.add(new int[] {16,4,10,4,16});
        s.add(new int[] {20,10,20});
        for(int i=0; i<49; i++){
            String a = "";
            boolean b = true;
            for(int j=0; j<s.get(i).length; j++){
                for(int k=0; k<s.get(i)[j]; k++){
                    if(b){
                        a+=" ";
                    }else{
                        a+="*";
                    }
                }
                b=!b;
            }
            System.out.println("println(\""+a+"\")" );
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
