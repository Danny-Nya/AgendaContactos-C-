//librerias
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include<string.h>

using namespace std;

//Declaracion de estructuras

struct Telefonos{
    int numeroTelefono;
    string informacionTelefono;
};

struct Contacto{
    int cantidadTelefonos;
    string nombreContacto;
    Telefonos* telefonoContacto;
};

struct Directorio{
    int cantidadContactos;
    string nombreCliente;
    int telefonoCliente;
    Contacto* contactosClientes;
};

//Declaracion de funciones
//Funcion llenar informacion del cliente
void infoCliente(Directorio* miDirectorio);
//Funcion menu
void menu(Directorio* miDirectorio);
//Funcion adicionar
void adicionar(Directorio* miDirectorio);
//Funcion llenar informacion del contacto
Contacto infoContacto();
//Funcion llenar informacion del telefono
Telefonos infoTelefono();
//Funcion menu de consulta
void menuConsulta(Directorio* miDirectorio);
//Funcion imprimir directorio
void imprimirLista(Directorio* miDirectorio);
//Funcion buscar en directorio
void buscar(Directorio* miDirectorio);
//Funcion eliminar
void eliminar(Directorio* miDirectorio);

//Funcion menu
void menu(Directorio* miDirectorio){
    int op;
    cout<<"Bienvenido "<<miDirectorio->nombreCliente<<endl;
    cout<<"Elija una opcion:  "<<endl;
    cout<<"1. Adicionar contacto"<<endl;
    cout<<"2. Eliminar contacto"<<endl;
    cout<<"3. Consultar contactos"<<endl;
	cout<<"4. Salir"<<endl<<endl;
    cin>>op;
    switch (op){
        case 1:
            adicionar(miDirectorio);
            menu(miDirectorio);
            break;
        case 2:
            eliminar(miDirectorio);
            menu(miDirectorio);
            break;
        case 3:
            menuConsulta(miDirectorio);
            menu(miDirectorio);
            break;
        case 4:
			return;
            break;
        default:
            cout<<"                                               ERROR"<< endl;
            cout<<"                        (El numero ingresado no corresponde a las opciones dadas)"<< endl;
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            menu(miDirectorio);
            break;
    }
}

//Funcion llenar informacion del cliente
void infoCliente(Directorio* miDirectorio){
    char op;
    cout<<"Ingrese su nombre:  "<<endl;
    cin>>miDirectorio->nombreCliente;
    cout<<"Ingrese su telefono:  "<<endl;
    cin>>miDirectorio->telefonoCliente;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
    cout<<"Nombre: "<<miDirectorio->nombreCliente<< endl;
    cout<<"Telefono: "<<miDirectorio->telefonoCliente<< endl;
    cout<<"Es la informacion correcta? (S/N)"<< endl;
    cin>>op;
    switch (op){
        case 'N':
            system("cls");
            infoCliente(miDirectorio);
            break;
        case 'S':
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            break;
        default:
            cout<<"                                               ERROR"<< endl;
            cout<<"                      (El caracter ingresado no corresponde a las opciones dadas)"<< endl;
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            infoCliente(miDirectorio);
            break;
    }
}

//Funcion adicionar
void adicionar(Directorio* miDirectorio){
   miDirectorio -> cantidadContactos++;
   if(miDirectorio -> cantidadContactos==1){
     miDirectorio ->contactosClientes=new Contacto[miDirectorio -> cantidadContactos];
     *((miDirectorio ->contactosClientes)+(( miDirectorio -> cantidadContactos)-1))= infoContacto();
   }
   else{
     Contacto* aux= new Contacto[miDirectorio -> cantidadContactos];
     for (int i=0; i<(miDirectorio -> cantidadContactos)-1;i++){
       *(aux+i) = *((miDirectorio ->contactosClientes)+i);
     }
     *(aux+((miDirectorio -> cantidadContactos)-1))= infoContacto();
     delete [] miDirectorio ->contactosClientes;
     miDirectorio ->contactosClientes=aux;
   }
}

//Funcion llenar informacion del contacto
Contacto infoContacto(){
  Contacto contactos;
  system("cls");
  cout << endl;
  cout << "Digite el nombre del contacto:"<<endl;
  cin >> contactos.nombreContacto;
  cout << "Digite la cantidad de telefnonos que posee "<<contactos.nombreContacto<<":"<<endl;
  cin >> contactos.cantidadTelefonos;
  contactos.telefonoContacto=new Telefonos[contactos.cantidadTelefonos];
  for(int i=0;i<contactos.cantidadTelefonos;i++)
  	contactos.telefonoContacto[i]=infoTelefono();
  system("cls");
  return contactos;
}

//Funcion llenar informacion del telefono
Telefonos infoTelefono(){
  Telefonos telefono;
  system("cls");
  cout << endl;
  cout << "Digite el telefono:"<<endl;
  cin >> telefono.numeroTelefono;
  cout << "Digite al informacion:"<<endl;
  cin >> telefono.informacionTelefono;
  return telefono;
}

//Funcion menu de consulta
void menuConsulta(Directorio* miDirectorio){
    int op;
    system("cls");
    cout<<"Elija una opcion:  "<<endl;
    cout<<"1. Buscar contacto"<<endl;
    cout<<"2. Lista de contactos"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>op;
    switch (op){
        case 1:
            system("cls");
            buscar(miDirectorio);
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            menuConsulta(miDirectorio);
            break;
        case 2:
            system("cls");
			imprimirLista(miDirectorio);
			cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            menuConsulta(miDirectorio);
            break;
        case 3:
            system("cls");
			return;
            break;
        default:
            system("cls");
            cout<<"                                               ERROR"<< endl;
            cout<<"                        (El numero ingresado no corresponde a las opciones dadas)"<< endl;
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            menuConsulta(miDirectorio);
            break;
    	}
}

//Funcion imprimir directorio
void imprimirLista(Directorio* miDirectorio){
	for(int i=0;i<miDirectorio->cantidadContactos;i++){
    cout << ((miDirectorio->contactosClientes)+i)->nombreContacto <<endl<<endl;
    cout <<"Telefono/s"<<endl;
    for(int j=0;j<((miDirectorio->contactosClientes)+i)->cantidadTelefonos;j++){
       cout <<endl<< ((((miDirectorio->contactosClientes)+i)->telefonoContacto)+j)->numeroTelefono <<endl;
       cout << ((((miDirectorio->contactosClientes)+i)->telefonoContacto)+j)->informacionTelefono <<endl;
       cout <<"_________________________________________________________________________";
    }
    cout<<endl<<endl;
    cout<<"*************************************************************************************"<<endl;
  }
}

//Funcion buscar en directorio
void buscar(Directorio* miDirectorio){
	int op=0;
	string buscar;
	cout<<"Ingrese a quien quiere buscar: "<<endl;
	cin>>buscar;
	for(int i=0;i<miDirectorio->cantidadContactos;i++){
		string base=((miDirectorio->contactosClientes)+i)->nombreContacto;
		if(buscar==base){
			cout <<((miDirectorio->contactosClientes)+i)->nombreContacto<<endl<<endl;
			cout <<"Telefono/s"<<endl;
			for(int j=0;j<((miDirectorio->contactosClientes)+i)->cantidadTelefonos;j++){
				cout <<endl<< ((((miDirectorio->contactosClientes)+i)->telefonoContacto)+j)->numeroTelefono <<endl;
				cout << ((((miDirectorio->contactosClientes)+i)->telefonoContacto)+j)->informacionTelefono <<endl;
				cout <<"_________________________________________________________________________";
				cout<<endl<<endl;
			}
			cout<<"*************************************************************************************"<<endl;
			op++;
		}
	}
	if (op==0){
		cout<<"No existe ese contacto"<<endl;
	}
}

//Funcion eliminar
void eliminar(Directorio* miDirectorio){
    int op=0,j=-1;
    char opi;
	string buscar;
	cout<<"Ingrese a quien quiere eliminar: "<<endl;
	cin>>buscar;
	cout<<"Esta seguro de eliminar a "<<buscar<<" ? (S/N)"<< endl;
    cin>>opi;
    switch (opi){
        case 'N':
            system("cls");
            return;
            break;
        case 'S':
			Contacto* aux= new Contacto[miDirectorio -> cantidadContactos];
			for(int i=0;i<miDirectorio->cantidadContactos;i++){
				string base=((miDirectorio->contactosClientes)+i)->nombreContacto;
				if(buscar==base){
				op++;
				
				}
				else{
					j++;
					*(aux+j) = *((miDirectorio ->contactosClientes)+i);
				}
				
			}
			miDirectorio -> cantidadContactos=miDirectorio -> cantidadContactos-op;
			if (op==0){
				cout<<"No existe ese contacto"<<endl;
			}
			delete [] miDirectorio ->contactosClientes;
			for(int k=0;k<miDirectorio->cantidadContactos;k++){
                *((miDirectorio ->contactosClientes)+k)=*(aux+k);
			}
            cout<<"                                          Presione ENTER"<< endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            break;
    }
	
}

//main
int main(){
    Directorio* miDirectorio;
    miDirectorio=new Directorio[1];
    miDirectorio->cantidadContactos=0;
    infoCliente(miDirectorio);
    menu(miDirectorio);
    delete[]miDirectorio;
}

