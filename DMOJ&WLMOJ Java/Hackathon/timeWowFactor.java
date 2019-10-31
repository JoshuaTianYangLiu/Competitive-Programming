/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hackathon;

/**
 *
 * @author Joshua
 */
public class timeWowFactor implements Comparable<timeWowFactor>{
    public int time;
    public int factor;
    public timeWowFactor(int _time, int w){
        time = _time;
        factor = w;
    }
    
    @Override
    public int compareTo(timeWowFactor o) {
        if(o.factor==-1){
            return Integer.compare(this.time,o.time);
        }
        return Integer.compare(this.factor,o.factor);
    }
}
