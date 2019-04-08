/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package maximumdistance;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class MaximumDistance {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int h = readInt();
        for(int i=0; i<h;i++){
            int size =readInt();
            int temp=0;
            List<Integer> aI = new ArrayList<Integer>();
            List<Integer> aX = new ArrayList<Integer>();
            for(int j =0;j<size; j++){
                int k = readInt();
                
                if(temp!=k || j==0){
                    aI.add(j);
                    aX.add(k);
                    temp=k;
                }
            }
            List<Integer> bI = new ArrayList<Integer>();
            List<Integer> bX = new ArrayList<Integer>();
            //int l =0;
            for(int j=0;j<size; j++){
                int k = readInt();
                if (j==0)
                {
                    temp = k;
                }
                else
                {
                    if (k !=temp)
                    {
                        bX.add(temp);
                        bI.add(j-1);
                        temp=k;
                 
                    }
                }
            }
            bX.add(temp);
            bI.add(size-1);
            
            int max =0;
            for(int k =bI.size()-1; k>=0; k--){
                for(int j=0; j<aI.size(); j++){
                    if(bX.get(k)>=aX.get(j)){
                        if (bI.get(k)-aI.get(j)>max){
                            if(k>=j){
                                max = bI.get(k)-aI.get(j);
                                break;
                            }
                        }
                    }
                    //else
                    //    break;
                }                
            }
            if(max<0){
                max=0;
            }
            System.out.println(max);

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
