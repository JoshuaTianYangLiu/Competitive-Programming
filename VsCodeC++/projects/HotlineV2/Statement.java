import java.io.*;
import java.util.*;
class Statement{
    //Statement
    //Clearly parses statement
    String subject="",predicate="";
    String object="";
    boolean isNull=false;
    boolean isPositive=true;
    Statement(String buf){
        StringTokenizer st=new StringTokenizer(buf," ");
        subject=st.nextToken(); //Assigns subject
        if(subject.equals("nobody")){   //flips only negative
            isPositive=false;
            subject="everybody";
        }
        String buffer=st.nextToken();       //These two v ^ if statements wont both run
        buffer=tossPeriod(buffer);      //Drops . if there is any
        if(buffer.equals("don't")||buffer.equals("doesn't")){//Contains contradiction
            isPositive=false;
            buffer=st.nextToken();
            predicate=tossPeriod(buffer);
        }else if(subject.equals("you")||subject.equals("I")){ //Case where predicate ends with "s"
            predicate=buffer;
        }else{
            predicate=buffer.substring(0,buffer.length()-1);
        }
        
        while(st.hasMoreTokens()){ //Optional adds object
            object+=st.nextToken()+" ";
        }
        object=tossPeriod(object.trim());   //Drops trailing space and .
    }
    String tossPeriod(String a){
        if(a.isEmpty())return "";
        if(a.charAt(a.length()-1)=='.')return a.substring(0,a.length()-1);
        return a;
    }
    boolean equalSubject(String subject){
        return this.subject.equals(subject);
    }
    boolean equalPredicate(String predicate){
        return this.predicate.equals(predicate);
    }
    boolean equalObject(String object){
        return this.object.equals(object);
    }
    boolean eqlSP(Statement a){
        return equalSubject(a.subject)&&equalPredicate(a.predicate);
    }
    boolean eqlSO(Statement a){
        return equalSubject(a.subject)&&equalObject(a.object);
    }
    boolean eqlPO(Statement a){
        return equalPredicate(a.predicate)&&equalObject(a.object);
    }
    boolean eqlPO(String a,String b){
        return equalPredicate(a)&&equalObject(b);
    }
}