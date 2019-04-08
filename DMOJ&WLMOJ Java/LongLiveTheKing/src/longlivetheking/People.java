/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package longlivetheking;

/**
 *
 * @author Joshua
 */
public class People{
    String name;
    char gender;
    boolean isDead;
    int age;

    People(String a, char b, String c, int d){
        name=a;
        gender=b;
        if(c.equals("dead")){
            isDead=true;
        }else{
            isDead=false;
        }
        age=d;
    }
    
}
