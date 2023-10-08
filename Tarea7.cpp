#include <iostream>
using namespace std;

const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombre[50];
	char apellidos[50];
	int telefono;
};


void Leer();
void Crear();
void Actualizar();
void Borrar();


main(){
	Leer();
	Crear();
	Borrar();
	Actualizar();
	
	
	system("pause");
}





void Leer(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}

Estudiante estudiante;
int id=0;
fread(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"_____________________________________________"<<endl;
cout<<"ID"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;


do{
	cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
	fread(&estudiante,sizeof(Estudiante),1,archivo);

	id+=1;
	}while(feof(archivo)==0);


	fclose(archivo);
}

void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	
	char res;
	Estudiante estudiante;
	do{
		
		fflush(stdin);
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombre: ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese Apellido: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese telefono: ";
		cin>>estudiante.telefono;
	
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar otro estudiante(s/n): ";
		cin>>res;
		
	}while(res=='s' || res=='S');
	fclose(archivo);
	Leer();
}

void Actualizar(){
	
		FILE* archivo = fopen(nombre_archivo,"r +b");
	
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante), SEEK_SET); 

		
		fflush(stdin);
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombre: ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese Apellido: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese telefono: ";
		cin>>estudiante.telefono;
	
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	fclose(archivo);
	Leer();	
}

void Borrar(){
	
	const char *nombre_archivo_temp = "archivo_temp-dat";
	 FILE* archivo = fopen(nombre_archivo,"rb");
	 FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	 
	 Estudiante estudiante;
	 int id=0, id_n=0;
	 cout<<"Ingrese el ID a eliminar: ";
	 cin>>id;
	 
	 while(	fread(&estudiante,sizeof(Estudiante),1,archivo)){
	 	
	 	 if(id_n!=id){
	 	 	
	 	fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);

		  }
	 	 id_n++;
	 }
	 fclose(archivo);
	 fclose(archivo_temp);
	

	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	
	 while(	fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
	 	
	 		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	 	
	 }
	
		 fclose(archivo);
	 fclose(archivo_temp);
	 Leer(); 
	
}
