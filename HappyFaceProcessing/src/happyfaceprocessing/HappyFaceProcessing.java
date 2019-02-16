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
        s.add(new int[] {50});
        s.add(new int[] {11,4,35});
        s.add(new int[] {10,1,4,4,31});
        s.add(new int[] {10,1,8,4,27});
        s.add(new int[] {10,1,12,4,23});
        s.add(new int[] {10,1,15,5,19});
        s.add(new int[] {9,1,16,1,3,5,15});
        s.add(new int[] {9,1,16,1,3,1,4,4,11});
        s.add(new int[] {9,1,16,1,3,1,8,4,7});
        s.add(new int[] {9,1,15,1,4,1,12,4,3});
        s.add(new int[] {8,1,7,2,7,1,3,1,17,1,2});
        s.add(new int[] {8,1,6,1,2,1,6,1,3,1,17,1,2});
        s.add(new int[] {8,1,6,1,3,1,6,3,18,1,2});
        s.add(new int[] {8,1,7,1,2,1,27,1,2});
        s.add(new int[] {7,1,9,2,27,1,3});
        s.add(new int[] {7,1,38,1,3});
        s.add(new int[] {7,5,24,2,8,1,3});
        s.add(new int[] {7,1,4,4,19,1,2,1,7,1,3});
        s.add(new int[] {6,1,9,4,15,1,3,1,5,1,4});
        s.add(new int[] {6,1,13,4,12,1,2,1,5,1,4});
        s.add(new int[] {6,1,17,4,9,2,6,1,4});
        s.add(new int[] {6,1,21,4,13,1,4});
        s.add(new int[] {5,1,6,2,18,4,8,1,5});
        s.add(new int[] {5,1,5,1,2,1,21,4,4,1,5});
        s.add(new int[] {5,1,5,1,3,1,24,5,5});
        s.add(new int[] {5,1,6,1,2,1,6,2,20,1,5});
        s.add(new int[] {4,1,8,2,6,1,2,1,18,1,6});
        s.add(new int[] {4,1,16,1,3,1,7,2,8,1,6});
        s.add(new int[] {4,1,17,1,2,1,6,1,2,1,7,1,6});
        s.add(new int[] {4,1,18,2,7,1,3,1,6,1,6});
        s.add(new int[] {5,4,24,1,2,1,5,1,7});
        s.add(new int[] {9,4,21,2,6,1,7});
        s.add(new int[] {13,4,25,1,7});
        s.add(new int[] {16,5,21,1,7});
        s.add(new int[] {16,1,4,4,16,1,8});
        s.add(new int[] {14,1,1,1,8,4,12,1,8});
        s.add(new int[] {15,1,4,2,4,1,2,4,8,1,8});
        s.add(new int[] {15,1,3,1,2,1,3,1,6,4,4,1,8});
        s.add(new int[] {16,1,2,1,3,1,2,2,9,4,9});
        s.add(new int[] {5,1,10,1,3,1,2,1,2,1,23});
        s.add(new int[] {5,1,11,1,3,2,2,1,24});
        s.add(new int[] {4,1,3,1,8,1,6,1,25});
        s.add(new int[] {7,1,10,1,4,1,26});
        s.add(new int[] {0,3,3,1,11,1,3,1,27});
        s.add(new int[] {3,1,5,1,8,1,2,1,28});
        s.add(new int[] {4,1,3,1,10,2,29});
        s.add(new int[] {5,1,13,1,30});
        s.add(new int[] {6,1,43});
        s.add(new int[] {6,1,43});
        s.add(new int[] {6,1,43});
        
        
        for(int i=0; i<50; i++){
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
            System.out.println("println(\""+a+"\");" );
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
