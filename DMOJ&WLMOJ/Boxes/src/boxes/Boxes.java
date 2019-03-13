/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package boxes;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Boxes {
    public static class Box implements Comparable<Box>{
        int length;
        int width;
        int height;
        public Box(int l, int w, int h){
            length=l;
            width=w;
            height=h;
        }
        
        public int compareTo(Box a){
            return Integer.compare(length*width*height,a.length*a.width*a.height);
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size =  readInt();
        Box box[] = new Box[size];
        
        for(int i=0; i<size; i++){
            int a[] = {readInt(),readInt(),readInt()};
            Arrays.sort(a);
            box[i]=new Box(a[0],a[1],a[2]);
        }
        int items = readInt();
        Arrays.sort(box);
        for(int i=0; i<items; i++){
            int a[] = {readInt(),readInt(),readInt()};
            Arrays.sort(a);
            b(box,a,size);
        }
    }
    static boolean b(Box box[],int a[],int size){
        for(int j=0; j<size; j++){
            if(canFit(box[j],a[0],a[1],a[2])){
                System.out.println(box[j].length*box[j].width*box[j].height);
                return true;
            }
        }
        System.out.println("Item does not fit.");
        return false;
    }
    static boolean canFit(Box a, int l, int w, int h){
        if(l<=a.length&&w<=a.width&&h<=a.height){
            return true;
        }else{
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
