#include <stdio.h>
#include <stdlib.h>



FILE* make_file(){
     FILE *file = fopen("diffusion.dat","w");//udela soubor .dat we "write modu"
    if (file==NULL){
        printf("error creating file\n");
        return NULL;
   }
        else{
        printf("file created!\n");
        return file;
    }
}    
    

void fresh_field(int step, int pocatek, double t0[],double t1[]) {
    
    //vynuluju pole
    for (int k = 0; k < step; k++) {
        t0[k] = 0;
        t1[k] = 0;
    }
    
    t0[pocatek] = 1;//pocatecni teplota
}

void diffuze(int timestep,int step,double t0[],double t1[], FILE *file, double a){
  

    for(int n = 0; n < timestep; n++){
        for(int i = 0; i < step; i++) {
        if(i == 0) {
            t1[i] = t0[i] + a * (t0[i+1] - t0[i]);//levy kraj -  i jde do prava
        } 
        else if(i == step - 1) {
            t1[i] = t0[i] + a * (t0[i-1] - t0[i]);//pravy kraj - i jde do leva
        } 
        else {
            t1[i] = t0[i] + a * (t0[i+1] - 2*t0[i] + t0[i-1]);//vnitrni body 
        }
        printf("%.2f ", t1[i]);
        fprintf(file, "%d\t%.4f\n", i, t1[i]);//ulozi time step a diffuzi pro kazdou iteraci
        
        }
   
        fprintf(file, "# Iteration %d\n", n);

        for(int k = 0; k < step; k++){
        t0[k]=t1[k];//nahradim puvodni stav novym stavem pro dalsi iteraci 
        }
        printf("\n");
        fprintf(file,"\n");

    }

}




int main(){
    int step = 10;//velikost pole
    int timestep = 15;//pocet iteraci
    int pocatek = 10;//pocatecni misto v poli - da se pridat viz dale
    double a = 0.1;//korekcni faktor
    
    
    printf("field size(int):");
    scanf("%d", &step);
    printf("number of itterations(int):");
    scanf("%d", &timestep);
    printf("correction factor (double - suggesting 0.1 ):");
    scanf("%lf", &a);
    printf("start position:");
    scanf("%d",&pocatek);

    while(pocatek >= step || pocatek < 0) {
    printf("Out of field range! Enter valid value: ");
    scanf("%d", &pocatek);
   }//abychom vzdy fitnuli field range
  
   double t0[step];
   double t1[step];

FILE* file = make_file();


fresh_field(step, pocatek,t0,t1);


diffuze(timestep, step, t0, t1, file, a);

    fclose(file);
    printf("Data saved to diffusion.dat\n");
    
    return 0;
}

