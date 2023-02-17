#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void amontonamientoMin(vector<int> *vec,int tam){
	int r,aux;
	r=tam/2;
	if(vec->at(tam)<vec->at(r)){
		aux=vec->at(tam/2);
		vec->at(tam/2)=vec->at(tam);
		vec->at(tam)=aux;
		tam=tam/2;
		amontonamientoMin(vec,tam);
	}else{
		if(tam>1){
			return;
		}

	}
}

void amontonamientoMax(vector<int> *vec,int tam){
	int r,aux;
	r=tam/2;
	if(r==0){
		return;
	}else{
		if(vec->at(tam)>=vec->at(r)){
			aux=vec->at(tam/2);
			vec->at(tam/2)=vec->at(tam);
			vec->at(tam)=aux;
			tam=tam/2;
			amontonamientoMax(vec,tam);
		}
	}
}

void ingresarNodo(vector<int> *vec, int num){
	vector<int>::iterator ite;
	int opc;
	if(vec->size()==0){
		vec->push_back(NULL);
	}
	vec->push_back(num);
	cout<<"\n\nNODO AGREGADO EXITOSAMENTE\n\n";
	if(vec->size()>1){
		cout<<"Elige cualquiera de las opciones: \n\t1. Monticulo Minimo\n\t2.Monticulo Maximo\n\n\tOpcion: ";
		cin>>opc;
		if(opc==1){
			amontonamientoMin(vec,vec->size()-1);
			cout<<"\n\n\tMonticulo MIN hecho! :)\n\n\t";
		}else{
			amontonamientoMax(vec,vec->size()-1);
			cout<<"\n\n\tMonticulo MAX hecho! :)\n\n\t";
		}
	}

}

void mostrarArbol(vector<int> *vec){
	vector<int>::iterator ite;
	int i,nivel=1,potencia=pow(2,nivel);
	if(vec->size()==0){
		cout<<"\n\n\tARBOL VACIO\n\n";
	}else{
		cout<<"Nivel "<<nivel<<"\n\n";
		for(ite=vec->begin()+1,i=1;ite!=vec->end(); ite++,i++){
			cout<<"Nodo "<<i<<": "<<(*ite)<<endl;
			if(i==potencia-1){
				nivel++;
			cout<<"\n\nNivel "<<nivel<<"\n\n";
			potencia=pow(2,nivel);
			}
		}
	}

}

void amontonaArriba(vector<int> *vec,int raiz){
	int r,conR,conI,conD,p,aux;
	r=raiz;
	if(r>((vec->size()-1)/2)||vec->size()-1<=2){
		return;
	}else{
		conR=vec->at(r);
		conI=vec->at(2*r);
		conD=vec->at(2*r+1);
		p=r;
		if(conI<conR&&conI<conD){
			aux=vec->at(2*r);
			vec->at(2*r)=vec->at(r);
			vec->at(r)=aux;
			r=2*p;
		}else if(conD<conR&&conD<conI){
			aux=vec->at(2*r+1);
			vec->at(2*r+1)=vec->at(r);
			vec->at(r)=aux;
			r=(2*p)+1;
		}
		amontonaArriba(vec,r);
	}
}

void amontonaArriba2(vector<int> *vec,int raiz){
	int r,conR,conI,conD,p,aux;
	r=raiz;
	if(r>((vec->size()-1)/2)||vec->size()-1<=2){
		return;
	}else{
		conR=vec->at(r);
		conI=vec->at(2*r);
		conD=vec->at(2*r+1);
		p=r;
		if(conI>conR&&conI>conD){
			aux=vec->at(2*r);
			vec->at(2*r)=vec->at(r);
			vec->at(r)=aux;
			r=2*p;
		}else if(conD>conR&&conD>conI){
			aux=vec->at(2*r+1);
			vec->at(2*r+1)=vec->at(r);
			vec->at(r)=aux;
			r=(2*p)+1;
		}
		amontonaArriba2(vec,r);
	}
}

void eliminar(vector<int> *vec){
	int i=1,aux,t,opc;
	vec->erase(vec->begin()+1);
	vec->insert(vec->begin()+1,vec->back());
	vec->pop_back();

	cout<<"\n\n\tPROCESO DE ELIMINADO REALIZADO\n\t";
	cout<<"Elige cualquiera de las opciones: \n\t1. Monticulo Minimo\n\t2.Monticulo Maximo\n\tOpcion: ";
		cin>>opc;
		if(opc==1){
			amontonaArriba(vec,i);
			cout<<"\n\n\tMonticulo MIN acomodado\n\n\t";
		}else{
			amontonaArriba2(vec,i);
			cout<<"\n\n\tMonticulo MAX acomodado\n\n\t";
		}
}



int main(){
	int opc,n,opc2;
	vector<int>arbol;

    do{
		cout<<"\n\nElige cualquiera de las siguientes opciones:\n\n\t1. Agregar valor\n\t2. Mostrar arbol\n\t";
		cout<<"3. Ordenar arbol como monticulo MIN\n\t4. Ordenar arbol como monticulo MAX\n\t5. Eliminar valor";
		cout<<"\n\t6. Salir\n\n\tOpcion: ";
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
				cout<<"\n\nDe las siguientes opciones elije el modo de crear un nodo de enteros: \n\t1. Numero aleatorio\n\t";
				cout<<"2. Numero a ingresar\n\tOpcion: ";
				cin>>opc2;
				cout<<endl<<endl;
				if(opc2==1){
					srand(time(NULL));
					n=1+rand()%(101-1);
					ingresarNodo(&arbol,n);
				}else if(opc2==2){
					cout<<"\n\nAgrega un numero entero: ";
					cin>>n;
					ingresarNodo(&arbol,n);
				}
				system("pause");
				system("cls");
			break;

			case 2:
				mostrarArbol(&arbol);
				cout<<endl<<endl;
				system("pause");
				system("cls");

			break;

			case 3:
				amontonamientoMin(&arbol,arbol.size()-1);
				cout<<"\n\n\tMonticulo MIN hecho! :)\n\n\t";
				system("pause");
				system("cls");
			break;

			case 4:
				amontonamientoMax(&arbol,arbol.size()-1);
				cout<<"\n\n\tMonticulo MAX hecho! :)\n\n\t";
				system("pause");
				system("cls");
			break;

			case 5:
				eliminar(&arbol);
				system("pause");
				system("cls");
			break;

			case 6:
				system("cls");
			break;
		}
    }while(opc!=6);

    return 0;
}
