import edu.duke.*;
import java.io.*;

/**
 * Write a description of StringsFirstAssignments here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class StringsFirstAssignments {
    public class Part1{
    public String findSimpleGene(String dna){
    String result="";
    int startIndex= dna.indexOf("ATG");
    if(startIndex==-1){return "";}
    int stopIndex=dna.indexOf("TAA",startIndex+3);
    if(stopIndex==-1){return "";}
    if((stopIndex-startIndex)%3!=0){
    result= dna.substring(startIndex,stopIndex+3);
    return "";
}   return result;
    }
    void testSimpleGene(){
    String dna="TAGCCATGCAGTTGGCATAAATTGCC";
    String gene=findSimpleGene(dna);
    System.out.println("DNA Strand is "+gene);
    }
    }
    void main(String[] args){
    Part1 dna= new Part1();
    dna.testSimpleGene();
    }
}
