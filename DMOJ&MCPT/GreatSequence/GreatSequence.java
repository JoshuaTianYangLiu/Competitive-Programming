/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package greatsequence;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */
public class GreatSequence {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int K = readInt();
        int q = readInt();
        long preSum[] = new long[size+1];
        ArrayList<Integer> elem[] = new ArrayList[2001];
        List<Integer> con = new ArrayList<Integer>();
        long total=0;
        for(int i=0; i<2001; i++)elem[i]=new ArrayList<Integer>();
        for(int i=0; i<size; i++){
            int a = readInt();
            elem[a+1000].add(i);
            total+=a;
            preSum[i+1]=total;
        }
        for(int i=0; i<q; i++){
            int a=readInt();
            int b=readInt();
            int x= readInt();
            int y=readInt();
            if(preSum[y]-preSum[x-1]>K&&elem[a+1000].size()>0&&elem[b+1000].size()>0){
                int l=0;
                int r=elem[a+1000].size()-1;
                int m=(l+r)/2;
                while(l<=r){
                    m = l + (r - l) / 2; 
                    if(elem[a+1000].get(m)>=x-1&&elem[a+1000].get(m)<=y-1)break;
                    if(elem[a+1000].get(m)<x-1)l=m+1;
                    else r=m-1;
                }
                if(elem[a+1000].get(m)>=x-1&&elem[a+1000].get(m)<=y-1){
                    l=0;
                    r=elem[b+1000].size()-1;
                    m=(l+r)/2;
                    while(l<=r){
                        m = l + (r - l) / 2; 
                        if(elem[b+1000].get(m)>=x-1&&elem[b+1000].get(m)<=y-1)break;
                        if(elem[b+1000].get(m)<x-1)l=m+1;
                        else r=m-1;
                    }
                    if(elem[b+1000].get(m)>=x-1&&elem[b+1000].get(m)<=y-1){
                        System.out.println("Yes");
                    }else System.out.println("No");
                }else System.out.println("No");
            }else System.out.println("No");
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
