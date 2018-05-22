import java.util.Scanner;

public class Bankers {
    //np = no. of processes \ nr = no. of resources

    int allocate[][]= new int[10][10];
    int max[][]=new int[10][10];
    int avail[]=new int [10];
    int need[][]=new int[10][10];
    int np,nr;

 void input(){
         Scanner in = new Scanner(System.in);
         System.out.print("Enter no. of processes and resources: ");
         np=in.nextInt();  //no. of processes
         nr=in.nextInt();  //no. of resources

       System.out.println("Enter allocation matrix: ");
         for(int i=0;i<np;i++)
              for(int j=0;j<nr;j++)
             allocate[i][j]=in.nextInt();  //allocation matrix

         System.out.println("Enter max. matrix: ");
         for(int i=0;i<np;i++)
              for(int j=0;j<nr;j++)
             max[i][j]=in.nextInt();  //max matrix

            System.out.println("Enter available matrix: ");
            for(int j=0;j<nr;j++)
                avail[j]=in.nextInt();  //available matrix

            in.close();
    }

    //calculate the need matrix
void calc_need(){
        for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){  //calculating need matrix
                need[i][j]=max[i][j]-allocate[i][j];
            }
        }
    }

    //Check if the requested resource is available or not
boolean check(int row){
       //checking if all resources for it^(h) process can be allocated
      for(int j=0;j<nr;j++) {
        if(avail[j]<need[row][j]) {
          return false;
        }
      }
      return true;
    }


    // Check if by fulfilling the resource request the system remains in safe state
public void isSafe(){
       input(); //collecting data from the user
       calc_need(); //mathmagics here :DD
       boolean done[]=new boolean[np];
       int j=0;

       while(j<np){  //loop until all process allocated
       boolean allocated=false;



       for(int i=0;i<np;i++){
          if(!done[i] && check(i)){  //trying to allocate
              for(int k=0;k<nr;k++){
                  avail[k]+=allocate[i][k];
                  System.out.print(avail[k]);
                }
             System.out.println(" Allocated process : "+i);
             allocated=done[i]=true;
               j++;
             }
       }



       if(!allocated) break;  // if the above loop iterated over all
                              // processes and there was no process then break


       }


       if(j==np)  //if all processes are allocated
        System.out.println("\nSafely allocated!");
       else
        System.out.println("\nAll proceess can't be allocated safely!");
    }

  public static void main(String[] args) {
      Bankers b =  new Bankers();
        b.isSafe();
    }
}
