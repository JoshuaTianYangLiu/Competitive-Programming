import java.io.*;
import java.util.*;
class Statement{
    boolean isPositive;
    String negative;
    String subject;
    String predicate;
    String object="";
    boolean isInf=false;
    boolean isEverybody=false;;
    boolean isNobody=false;
    boolean hasObject=false;
    Statement(String a){
        StringTokenizer st=new StringTokenizer(a);
        String temp=st.nextToken();
        subject=temp;
        temp=st.nextToken();
        if(temp.contains("don't")){
            isPositive=false;
            negative="don't";
            temp=st.nextToken();
        }else if(temp.contains("doesn't")){
            isPositive=false;
            negative="doesn't";
            temp=st.nextToken();
        }else isPositive=true;
        if(temp.charAt(temp.length()-1)=='s'&&isPositive&&!isInfSubject(subject)){
            predicate=temp.substring(0,temp.length()-1);
            isInf=true;
        }
        else predicate=temp;

        if(st.hasMoreTokens()){
            temp="";
            while(st.hasMoreTokens()){
                temp+=st.nextToken()+" ";
            }
            temp=temp.trim();
            if(temp.length()>1)object=temp.substring(0,temp.length()-1);
            hasObject=true;
        }else{
            if(predicate.charAt(predicate.length()-2)=='s'){
                predicate=predicate.substring(0,predicate.length()-2);
            }else{
                predicate=predicate.substring(0,predicate.length()-1);
            }
            hasObject=false;
        }
        if(subject.equals("everybody"))isEverybody=true;
        if(subject.equals("nobody"))isNobody=true;
        if(isNobody)isPositive=false;
    }
    boolean isInfSubject(String sub){
        return sub.equals("I")||sub.equals("you");
    }
    void print(){
        /*System.out.printf("::%s %s %s\n",subject,predicate,object);*/
    }
    boolean isSubject(String sub){
        return sub.equals(subject)||isEverybody||isNobody||sub.equals("everybody")||sub.equals("nobody");
    }
    boolean isPositive(){
        return isPositive;
    }
    boolean isPredicate(String pred){
        return pred.equals(predicate);
    }
    boolean isObject(String obj){
        return obj.equals(object);
    }
    boolean isEverybody(){
        return isEverybody;
    }
    boolean isNobody(){
        return isNobody;
    }
    boolean isSubject(){
        return !isEverybody&&!isNobody;
    }
    boolean isSubOrEvery(String sub){
        return subject.equals(sub)||isEverybody;
    }
}