import java.io.*;
import java.security.SecureRandom;
import java.util.*;

public class CSPRING {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int csprng[] = new int[25011];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        BufferedReader brr = new BufferedReader(new FileReader(new File("D:\\Contest-Practice\\Contest-Practice\\VsCodeC++\\projects\\CSPRNG\\csprng.txt")));
        int len=0;
        long seed=0;
        for(int i=0; i<25000; i++){
            csprng[i]=Integer.parseInt(brr.readLine());
        }
        SecureRandom sr = new SecureRandom();
        for(long i=0; i<Integer.MAX_VALUE; i++){
            sr.setSeed(i);
            for(int j=0; j<25000; j++){
                int v=(1000000007+(sr.nextInt()%1000000007))%1000000007;
                // System.out.println(v);
                if(v!=csprng[j]){
                    if(j>len){
                        System.out.println(i+" "+j);
                        seed=i;
                        len=j;
                    }
                    break;
                }
            }
            sr=new SecureRandom();
        }
        System.out.println(seed+" "+len);
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