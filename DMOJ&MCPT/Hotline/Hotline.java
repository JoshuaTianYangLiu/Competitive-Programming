import java.io.*;
import java.util.*;

public class Hotline {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static Statement state[];
    public static void main(String[] args) throws Exception{
        int t=readInt();
        for(int i=1; i<=t; i++){
            boolean hasContradictions=false;
            state = new Statement[105];
            int statementLen=0;
            System.out.printf("Dialogue #%d:\n",i);
            String input = readLine();
            while(!input.contains("!")){
                if(input.charAt(input.length()-1)=='?'){
                    System.out.println(input);
                    if(hasContradictions){
                        System.out.println("I am abroad.");
                    }else{
                        Question q = new Question(input);
                        q.print();
                        q.answerQuestion(state, statementLen);
                    }
                    System.out.println();
                }else{
                    state[statementLen]=new Statement(input);
                    state[statementLen].print();
                    for(int j=0; j<statementLen; j++){
                        if(state[j].isSubject(state[statementLen].subject)&&state[j].isPredicate(state[statementLen].predicate)){
                            if(state[j].isPositive^state[statementLen].isPositive){
                                if(state[j].hasObject&&state[statementLen].hasObject){
                                    if(state[j].isObject(state[statementLen].object)){
                                        hasContradictions=true;
                                    }
                                }else if(!state[j].hasObject&&!state[statementLen].hasObject){
                                    hasContradictions=true;
                                }
                            }
                            
                        }
                    }
                    /*
                    Contradictions:
                    Subject: nobody
                    Everybody: subject
                    Nobody: Subject

                    Subject predicate
                    subject doesnt predicate

                    everybody predicate object
                    nobody predicate object

                    everybody predicate
                    nobody predicate

                    subject predicate
                    */
                    statementLen++;
                }
                input = readLine();
            }
            System.out.println(input+"\n");
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