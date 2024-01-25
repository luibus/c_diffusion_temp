
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*#define NR 40   //tamaño de la malla
#define NRHO 20
#define NZ 80*/
int NZ=50;
int NR=10;//antes 4
int NRHO=9;//tiene que ser impar

void write (double temp[NZ][NR][NRHO],double gradcuad[NZ][NR][NRHO], int n);
void write2 (double temp[NZ], int n);
void write3 (double temp[NZ], int n);
void write4 (double temp, int n);
int main (int argc, char* argv[]) {
	double k=1;
	//double k=0.0000196;
	//double k=1.96;
    // the three-dimensional temperature array
    double temp[NZ][NR][NRHO];
    double tempnew[NZ][NR][NRHO];
    double gradcuad[NZ][NR][NRHO];
    double lineal[NZ];
    double linealtemp[NZ];
    double entrototal=0;
    int steps = 50000;
    int contador=0;
    double deltaT;
    double deltaR;
    double deltaRHO;
    double deltaZ;
    double T2=100;
    double tmount=1.00;
    //deltaT=(T2-tmount)/steps;

    FILE* fout;

    // first, we delete the output file because later we will always append
    fout = fopen("output1_animation_temp_cylinder_extra2.txt", "w");
    fclose(fout);
    FILE* fout2;
        // first, we delete the output file because later we will always append
        fout2 = fopen("output1_animation_entro_lineal_cylinder_extra2.txt", "w");
        fclose(fout2);
        FILE* fout3;
                // first, we delete the output file because later we will always append
                fout3 = fopen("output1_animation_temp_lineal_cylinder_extra2.txt", "w");
                fclose(fout3);
                FILE* fout4;
                         // first, we delete the output file because later we will always append
                         fout4 = fopen("output1_animation_entro_total_cylinder_extra2.txt", "w");
                         fclose(fout4);

    // parse parameter (steps can be given)
    printf("Usage: <program> [steps=500]\n");
    if (argc > 1) steps = atof(argv[1]);
    printf("Using steps=%d\n", steps);



    // TODO:
    // Implement the solution to exercise 12 (the heat equation) here.
    // You can use the write function to write every time step in a file.
    // Later, you can use the python plotting script to check your results.
//Boundary conditions
    double tempfueradcha[NZ][NR],tempfueraizda[NZ][NR];


    //discretitation pongo todo en forma de los 40 y 20 puntos de matriz
    double extremR=0.5; //extremo del radio
    deltaR=extremR/NR; // punto de paso del radio en la malla
    double n;


    double extremz=1;
    deltaZ=extremz/NZ; // punto de paso en altura en el cilindro
    double extremRHO=2*3.1416; //extremo del angulo luego tendré que hacer condiciones de dirichlecht al acabar
    deltaRHO=extremRHO/NRHO; // punto de paso en altura en el cilindro

    deltaT=0.0001;//////////////////////////////////////////////////////////////////                        AQUI
    n=(k*deltaT);
    printf("n=%.9f\n", n);
    printf("delT=%.9f\n", deltaT);

for (int i=0;i<NZ;i++){ //aqui le doy el valor de temperatura a mi matriz
	 for (int j=0;j<NR;j++){
		 for (int g=0;g<NRHO;g++){
	    	temp[i][j][g]=tmount;
	    	//printf("\n resta: %8.4f", temp[i][j][g]);
	    	//printf("\n antes de iterar\n");
	    }}}
for (int g=0;g<NRHO;g++){ //ahora si las tapas
	for (int j=0;j<NR;j++){
		if (j<(NR/2)){
		temp[0][j][g]=T2;//
		}
		else{
		temp[0][j][g]=tmount+4;
		}
	}}
temp[NZ-1][NR-1][NRHO-1]=T2;//ojoooooooooooooooooooooooooooooooooooooooo

for (int i=0;i<NZ;i++){
	for (int j=0;j<NR;j++){//continuidad de T en rho entre 0 y 2pi A CONSEGUIDO BAJARLO DE 63 A 59 el ampliar radio quiza funciona mal a radio fino
	tempfueradcha[i][j]=temp[i][j][0];
	tempfueraizda[i][j]=temp[i][j][NRHO-1];
	printf("\n antes de iterar");
}}
printf("\n antes de iterar");
																										//EMPIESA LA ITERACION
for (int s=0;s<25000;s++){//tiempo
//	printf("\n s: %8.4d", s);
for (int i=0;i<NZ;i++){//quizá son -2
	 for (int j=0;j<NR;j++){
		 for (int g=0;g<NRHO;g++){
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g>0&&g<NRHO-1){
tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j+1][g]+temp[i][j-1][g]-2*temp[i][j][g])/pow(deltaR,2))+((1/pow((j*extremR/(NR-1)),2))*(temp[i][j][g+1]+temp[i][j][g-1]-2*temp[i][j][g])/pow(deltaRHO,2))+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
			 }

			 if(i==(NZ-1)&&j>=0&&j<=NR-1&&g>=0&&g<=NRHO-1){
				 	 	 	 	 	if (j<(NR/2)){
									tempnew[NZ-1][j][g]=tmount+4;//
						 			} else{
									tempnew[NZ-1][j][g]=T2;
								 	}

			 				}
			 if(i==0&&j>=0&&j<=NR-1&&g>=0&&g<=NRHO-1){//aqui estoy editando
				 //tempnew[0][j][g]=T2;

				 if (j<(NR/2)){
					tempnew[0][j][g]=tmount+4;//
		 			} else{
					tempnew[0][j][g]=T2;
				 	}
			 		}

			 if(i>0&&i<NZ-1&&j==0&&g>=0&&g<NRHO){
			 			tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j+1][(((NRHO)/2)*3/4)-1]+temp[i][j-1][(((NRHO)/2)*7/4)-1]-2*temp[i][j][g])/pow(deltaR,2))+((temp[i][j-1][(((NRHO)/2)/4)-1]+temp[i][j+1][(5*((NRHO)/2)/4)-1]-2*temp[i][j][g])/pow(deltaR,2)));
			 	}
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g==0){
			 	tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j+1][g]+temp[i][j-1][g]-2*temp[i][j][g])/pow(deltaR,2))+(1/pow((j*extremR/(NR-1)),2))*((temp[i][j][g+1]+tempfueraizda[i][j]-2*temp[i][j][g])/pow(deltaRHO,2))+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
			 	}
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g==(NRHO-1)){//probar si funciona con parentesis
			 	tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j+1][g]+temp[i][j-1][g]-2*temp[i][j][g])/pow(deltaR,2))+(1/pow((j*extremR/(NR-1)),2))*((tempfueradcha[i][j]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaRHO,2))+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
			 	}
			 if(i>0&&i<NZ-1&&j==NR-1&&g>0&&g<NRHO-1){//                                                                       j-1             j
			 	tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j-2][g]-temp[i][j-1][g])/pow(deltaR,2))+(1/pow((j*extremR/(NR-1)),2))*((temp[i][j][g+1]+temp[i][j][g-1]-2*temp[i][j][g])/pow(deltaRHO,2)));
			 	}
			 if(i>0&&i<NZ-1&&j==NR-1&&g==NRHO-1){
			 	tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j-2][g]-temp[i][j-1][g])/pow(deltaR,2))+(1/pow((j*extremR/(NR-1)),2))*((tempfueradcha[i][j]+temp[i][j][g-1]-2*temp[i][j][g])/pow(deltaRHO,2)));//+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
				}
			 if(i>0&&i<NZ-1&&j==NR-1&&g==0){
				tempnew[i][j][g]=temp[i][j][g]+n*(((temp[i+1][j][g]+temp[i-1][j][g]-2*temp[i][j][g])/pow(deltaZ,2))+((temp[i][j-2][g]-temp[i][j-1][g])/pow(deltaR,2))+(1/pow((j*extremR/(NR-1)),2))*((temp[i][j][g+1]+tempfueraizda[i][j]-2*temp[i][j][g])/pow(deltaRHO,2)));//+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
		 		}
			if(i>0&&i<NZ-1&&j>=0&&j<NR&&g==0){
				tempfueradcha[i][j]=tempnew[i][j][0];
				}
			if(i>0&&i<NZ-1&&j>=0&&j<NR&&g==NRHO-1){
				tempfueraizda[i][j]=tempnew[i][j][NRHO-1];
				}
			if(i==(NZ-1)&&j>=0&&j<=NR-1&&g>=0&&g<=NRHO-1){
				if (j<(NR/2)){
				tempnew[NZ-1][j][g]=tmount+4;//
				} else{
				tempnew[NZ-1][j][g]=T2;
				}
				//tempnew[NZ-1][j][g]=tmount;
				}
			if(i==0&&j>=0&&j<=NR-1&&g>=0&&g<=NRHO-1){
				//tempnew[0][j][g]=T2;

				if (j<(NR/2)){
				tempnew[0][j][g]=tmount+4;
				}
				else{
				tempnew[0][j][g]=T2;
				}
				}
   }/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}}			//aquí tengo ya mi primera matriz temp para el primer s
if ((contador==5||contador==2)&&s<5500){//escribo una linea de temp en fila en un archivo lineal de temperatura en el tiempo
	for (int i=1;i<NZ-1;i++){
		int j=2;
		int g=2;
	 	linealtemp[i]=tempnew[i][j][g];
	 //ejecuta la funcion para el nuevo archivo
		}
	write3 (linealtemp,0);
	}
for (int i=0;i<NZ;i++){//quizá son -2 el del instante actual ya lo actualizo tras todas las iteraciones
	 for (int j=0;j<NR;j++){
		 for (int g=0;g<NRHO;g++){
				 temp[i][j][g]=tempnew[i][j][g];
			 }}}

//ENTROPÍA en principio funciona SIGUIENTE PASO guardar una línea de producción local de entropía para varios momentos del t y plotear su evolucion
//una sola linea
//ahora queda hacer esto para la linea 2 2 de temperatura y ver su evolucion y hacer la entropía total luego habrá que jugar con las temperaturas del foco
if (contador==5){
	for (int i=1;i<NZ-1;i++){
		int j=2;
		int g=2;
		lineal[i]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][((NRHO-1)/2)]-temp[i][j][((NRHO-1)/2)])/pow(deltaZ,1)),2)+pow(((temp[i][j+1][(((NRHO-1)/2)*3/4)]-temp[i][j][(((NRHO-1)/2)*7/4)])/pow(deltaR,1)),2)+pow(((temp[i][j-1][(((NRHO-1)/2)/4)]-temp[i][j+1][(5*((NRHO-1)/2)/4)])/pow(deltaR,1)),2));
		entrototal=entrototal+lineal[i];//suma de todas las Z a un tiempo
	}
write2 (lineal,0);//ejecuta la funcion para el nuevo archivo
entrototal=deltaZ*entrototal;//multiplico por el paso en Z la suma
write4 (entrototal,0);
entrototal=0;
contador =0;
}

contador =contador+1;
//el caso de la entropia total lo haremos solo para el caso lineal, si no ver como se hace integral al volumen numerica
if(s==621){
	printf("\n se esta haciendo");
for (int i=0;i<NZ;i++){//quizá son -2
	 for (int j=0;j<NR;j++){
		 for (int g=0;g<NRHO;g++){
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g>0&&g<NRHO-1){
gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+pow(((temp[i][j+1][g]-temp[i][j][g])/pow(deltaR,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((temp[i][j][g+1]-temp[i][j][g])/pow(deltaRHO,1)),2));
			 }
			 if(i>0&&i<NZ-1&&j==0&&g>=0&&g<NRHO){
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][((NRHO-1)/2)]-temp[i][j][((NRHO-1)/2)])/pow(deltaZ,1)),2)+pow(((temp[i][j+1][(((NRHO-1)/2)*3/4)]-temp[i][j][(((NRHO-1)/2)*7/4)])/pow(deltaR,1)),2)+pow(((temp[i][j-1][(((NRHO-1)/2)/4)]-temp[i][j+1][(5*((NRHO-1)/2)/4)])/pow(deltaR,1)),2));
			 	}
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g==0){
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+pow(((temp[i][j+1][g]-temp[i][j][g])/pow(deltaR,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((temp[i][j][g+1]-temp[i][j][g])/pow(deltaRHO,1)),2));
			 	}
			 if(i>0&&i<NZ-1&&j>0&&j<NR-1&&g==(NRHO-1)){//probar si funciona con parentesis
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+pow(((temp[i][j+1][g]-temp[i][j][g])/pow(deltaR,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((tempfueradcha[i][j]-temp[i][j][g])/pow(deltaRHO,1)),2));
			 	}
			 if(i>0&&i<NZ-1&&j==NR-1&&g>0&&g<NRHO-1){//                                                                       j-1             j
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((temp[i][j][g+1]-temp[i][j][g])/pow(deltaRHO,1)),2));
			 	}
			 if(i>0&&i<NZ-1&&j==NR-1&&g==NRHO-1){
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((tempfueradcha[i][j]-temp[i][j][g])/pow(deltaRHO,1)),2));//+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
				}
			 if(i>0&&i<NZ-1&&j==NR-1&&g==0){
				 gradcuad[i][j][g]=(k/pow(temp[i][j][g],2))*(pow(((temp[i+1][j][g]-temp[i][j][g])/pow(deltaZ,1)),2)+(1/pow((j*extremR/(NR-1)),2))*pow(((temp[i][j][g+1]-temp[i][j][g])/pow(deltaRHO,1)),2));//+((1/pow((j*extremR/(NR-1)),1))*((temp[i][j+1][g]-temp[i][j][g])/deltaR)));
		 		}
		 }}}
}
}
printf("\n se acabo jajaja");
write (temp, gradcuad,0);
    return 0;
}

void write (double temp[NZ][NR][NRHO], double gradcuad[NZ][NR][NRHO],int n) {
    int i, j, g;
    FILE* fout;
    fout = fopen("output1_animation_temp_cylinder_extra2.txt", "a");
    for (i=0; i<NZ; i++) {
    	for (g=0; g<NRHO; g++) {//escribira una linea con todos los angulos seguidos
        for (j=0; j<NR; j++) {
        	//for (g=0; g<NRHO; g++) {
            fprintf(fout, "%.16f\t", temp[i][j][g]);
        }}
        fprintf(fout, "\n");
    }
    for (i=0; i<NZ; i++) {//segunda matriz
       	for (g=0; g<NRHO; g++) {//escribira una linea con todos los angulos seguidos
           for (j=0; j<NR; j++) {
           	//for (g=0; g<NRHO; g++) {
               fprintf(fout, "%.16f\t", gradcuad[i][j][g]);
           }}
           fprintf(fout, "\n");
       }
    fclose(fout);
}//mas o menos bien lo que pasa es que en los distintos angulos en el radio fluctua la temperatura SOLUCION hacerlo todo en un mismo bucle y definir los limites de lo que se usa ya que lo que estoy viendo son los vestigios de las dos líneas y del centro

void write2 (double temp[NZ], int n) {
    int i;
    FILE* fout2;
    fout2 = fopen("output1_animation_entro_lineal_cylinder_extra2.txt", "a");
    for (i=1; i<NZ-1; i++) {
        	//for (g=0; g<NRHO; g++) {
            fprintf(fout2, "%.16f\t", temp[i]); //estarán en linea todas las i y en la sguiente linea las del siguiente instante
    }
 fprintf(fout2, "\n");
    fclose(fout2);
}

void write3 (double temp[NZ], int n) {
    int i;
    FILE* fout3;
    fout3 = fopen("output1_animation_temp_lineal_cylinder_extra2.txt", "a");
    for (i=1; i<NZ-1; i++) {
        	//for (g=0; g<NRHO; g++) {
            fprintf(fout3, "%.16f\t", temp[i]); //estarán en linea todas las i y en la sguiente linea las del siguiente instante
    }
 fprintf(fout3, "\n");
    fclose(fout3);
}
void write4 (double temp, int n) {

    FILE* fout4;
    fout4 = fopen("output1_animation_entro_total_cylinder_extra2.txt", "a");

            fprintf(fout4, "%.16f\t", temp); //estarán en linea todas las i y en la sguiente linea las del siguiente instante


    fclose(fout4);
}
