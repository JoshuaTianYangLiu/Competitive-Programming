import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class TravelConflict {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a=readInt(),b=readInt(),c=readInt(),d=readInt(),e=readInt(),f=readInt(),g=readInt(),h=readInt();
        Date x= new Date(a,b,c);
        Date y = new Date(e,f,g);
        Date x1= new Date(a,b,c+d-1);
        Date y1 = new Date(e,f,g+h-1);
        if(x.after(y1)||y.after(x1)){
            System.out.println("NO");
        }else{
            System.out.println("YES");
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
