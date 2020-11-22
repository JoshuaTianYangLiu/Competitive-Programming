import java.io.*;
import java.util.*;

public class ECOOP2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static String notes[] = new String[]{"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C"};
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        
    }
    
    static int find(String a){
        for(int i=0; i<13; i++){
            if(a.equals(notes[i]))return i;
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