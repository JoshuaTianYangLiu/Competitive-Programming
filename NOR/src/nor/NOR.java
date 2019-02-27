/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package nor;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class NOR {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        List<Integer> a = new ArrayList<Integer>();
        for(int i=0;i<size; i++){
            if(readInt()==1){
                a.add(i+1);
            }
        }
        int size1 = readInt();
        for(int i =0;i<size1; i++){
            int start = readInt();
            int end = readInt();
            System.out.println(findNor(a,start,end));
        }
        
    }
    static int findNor(List a, int start,int end){
        int posOne = FindSmallPosition(a, end);
        if(posOne==end)return 0;
        if(posOne<start)return (end-start)%2==0?0:1;
        if(posOne==start) return (end-start)%2==0?1:0;
        if(posOne>start) return (end-posOne)%2==0?0:1;
        return -1;
    }
    static int FindSmallPosition(List a, int val)
    {
        if(a.size()==0)return 0;
        int begin = 0;
        int end = a.size()-1;
        int mid;
        if (val>=(int)a.get(end))
            return (int)a.get(end);
        if (val<(int)a.get(begin))
            return 0;
         while (end>begin)
        {
            mid = (begin+end)/2;
            if (val==(int)a.get(mid))
                    return (int)a.get(mid);
            if (val>(int)a.get(mid))
            {
                begin=mid;
            }
            else
            {
                end=mid;
            }
            if (begin+1 == end)
                return (int)a.get(begin);
        }
        return -1;
    
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
