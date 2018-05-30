import java.util.Scanner;

public class Bankers {
    

    int allocate[][]= new int[10][10];
    int max[][]=new int[10][10];
    int avail[]=new int [10];
    int need[][]=new int[10][10];
    int np,nr;

 void input(){
         Scanner in = new Scanner(System.in);
         System.out.print("Enter no. of processes and resources: ");
         np=in.nextInt(); 
         nr=in.nextInt();  

       System.out.println("Enter allocation matrix: ");
         for(int i=0;i<np;i++)
              for(int j=0;j<nr;j++)
             allocate[i][j]=in.nextInt(); 

         System.out.println("Enter max. matrix: ");
         for(int i=0;i<np;i++)
              for(int j=0;j<nr;j++)
             max[i][j]=in.nextInt();  

            System.out.println("Enter available matrix: ");
            for(int j=0;j<nr;j++)
                avail[j]=in.nextInt(); 

            in.close();
    }

    
void calc_need(){
        for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){ 
                need[i][j]=max[i][j]-allocate[i][j];
            }
        }
    }

    
boolean check(int row){
       
      for(int j=0;j<nr;j++) {
        if(avail[j]<need[row][j]) {
          return false;
        }
      }
      return true;
    }


    
public void isSafe(){
       input();r
       calc_need(); 
       boolean done[]=new boolean[np];
       int j=0;

       while(j<np){  
       boolean allocated=false;



       for(int i=0;i<np;i++){
          if(!done[i] && check(i)){  
              for(int k=0;k<nr;k++){
                  avail[k]+=allocate[i][k];
                  System.out.print(avail[k]);
                }
             System.out.println(" Allocated process : "+i);
             allocated=done[i]=true;
               j++;
             }
       }



       if(!allocated) break;  
                              


       }


       if(j==np)  
        System.out.println("\nSafely allocated!");
       else
        System.out.println("\nAll proceess can't be allocated safely!");
    }

  public static void main(String[] args) {
      Bankers b =  new Bankers();
        b.isSafe();
    }
}
