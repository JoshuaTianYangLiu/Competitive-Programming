/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package searchingforbreak;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SearchingForBreak {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int numBake = readInt();
        int branches = readInt();
        ArrayList<Integer>[] tree = new ArrayList[numBake+1];
        for(int i=0; i<numBake+1; i++){
            tree[i]= new ArrayList<Integer>();
        }
        for(int i=0; i<branches; i++){
            int node =readInt();
            int to = readInt();
            tree[node].add(to);
            tree[to].add(node);
        }
        Queue<Integer> q = new LinkedList<Integer>();
        boolean visited[] = new boolean[numBake+1];
        visited[1]=true;
        int distance[] = new int[numBake+1];
        q.add(Integer.valueOf("1"));
        while(q.size()!=0){
            int node = q.remove();
            for(int i=0; i<tree[node].size(); i++){
                int pointing = tree[node].get(i);
                if(!visited[pointing]){
                    q.add(pointing);
                    distance[pointing]=distance[node]+1;
                    visited[pointing]=true;
                 }
            }
            
        }
        int max =0;
        for(int i=0; i<numBake+1; i++){
            if(distance[i]>max){
                max=distance[i];
            }
        }
        System.out.println(max);
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
