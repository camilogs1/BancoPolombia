#include <iostream>
#include <cstdlib>

using namespace std;

//Cola
struct transc
{
	int consecu, dia_tra,mes_tra,anio_tra,valortra,numero_cuen;
	string tra;
	struct transc *sig;
};

typedef struct transc *regi;
regi primero,ultimo,h;

//Lista doblemente ligada cliente
struct cliente
{
	int ced_cliente,dia_nacimiento,mes_nacimiento,anio_nacimiento;
	string nom_cliente, genero_cliente;
	struct cliente * liga_der;
	struct cliente * liga_izq;
};	

typedef struct cliente * registro;
registro cab, ant, p, q;

//Lista ligada simple cuenta
struct cuenta
{
	int num_cuenta,sal_cuenta,cedu_cliente;
	struct cuenta * sig;	
};

typedef struct cuenta * regis;
regis cabe, ante, t,y;

//Lista circular operaciones
struct operaciones
{
	int consecutivo, dia_trans,mes_trans,anio_trans,valor,nume_cuenta;
	string tip_trans;
	struct operaciones * liga_der;
	struct operaciones * liga_izq;	
};


typedef struct operaciones * regist;
regist cam, amt, m, n;

//Pilas
struct pilas_may
{
	int cedul,dia_n,mes_n,anio_n,sald,num_cuent;
	string nombr, gener;
	struct pilas_may *sig;
};

typedef struct pilas_may *registr;

struct pilas_hombres
{
	int cedula,dia,mes,anio,saldo,num_cuenta;
	string nombre, genero;
	
	struct pilas_hombres *sig;
};

typedef struct pilas_hombres *registroo;

//registros variables main
int sw=0,st=0,sr=0,resp_menprinci,resp_menclien,ced_busc,ced_elim,ced_consul,resp_mencuent,num_cuenta_consul,cuenta_elim,cuenta_busc,resp_menopereac,num_cuentaa,num_cuenta;
int resp_menconsul;
string resp_verif;
int con=0;
int dinero;
int kilo=666;
string tip;
//funcion menu principal
void menu_principal()
{
	cout<<"\t\t \t\t \t \t   ...Bancopolombia...\n\n";
	cout<<"\t \t ...Menu Principal...";
	cout<<"\n Clientes --- 1";
	cout<<"\n Cuentas --- 2";
	cout<<"\n Operaciones --- 3";
	cout<<"\n Consultas --- 4";
	cout<<"\n Salir --- 5";
	cout<<"\n Ingrese una opcion: ";
}
//funcion menu clientes
void menu_clientes()
{
	cout<<"\t \t ...Menu clientes...";
	cout<<"\n Adicionar nuevo cliente --- 1";
	cout<<"\n Modificar cliente registrado --- 2";
	cout<<"\n Anular cliente registrado --- 3";
	cout<<"\n Consultar cliente registrado --- 4";
	cout<<"\n regresar al menu principal --- 5";
	cout<<"\n Ingrese una opcion: ";
}
//funcion menu cuentas
void menu_cuentas()
{
	cout<<"\t \t ...Menu cuenta...";
	cout<<"\n Adicionar cuenta nueva --- 1";
	cout<<"\n Modificar cuenta registrada --- 2";
	cout<<"\n Anular cuenta registrada --- 3";
	cout<<"\n Consultar cuenta registrada --- 4";
	cout<<"\n regresar al menu principal --- 5";
	cout<<"\n Ingrese una opcion: ";	
}
//funcion menu operaciones
void menu_operaciones()
{
	cout<<"\t \t ...Menu operaciones...";
	cout<<"\n Consignar a una cuenta registrada --- 1";
	cout<<"\n Retirar de una cuenta registrada --- 2";
	cout<<"\n regresar al menu principal --- 3";
	cout<<"\n Ingrese una opcion: ";	
}
//funcion menu consultas
//Menu consultas
void menu_consultas()
{	
	cout<<"\t \t ...Menu consultas...";
	cout<<"\n Consultar clientes registrados --- 1";
	cout<<"\n Consultar clientes hombres registrados --- 2";
	cout<<"\n Consultar clientes con un saldo mayor a 5.000.000 de pesos --- 3";
	cout<<"\n Consultar operaciones realizadas --- 4";
	cout<<"\n regresar al menu principal --- 5";
	cout<<"\n Ingrese una opcion: ";
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//funcion crear nuevo cliente
registro reg_cliente_new()
{
	registro reg = new(struct cliente);
	cout <<"\n Ingrese nombre del cliente: ";
	cin >> reg->nom_cliente;
										
	cout <<"\n Ingrese cedula del cliente: ";
	cin >> reg->ced_cliente;
										
	cout <<"\n Ingrese genero del cliente: masculino / femenino : ";
	cin >> reg->genero_cliente;
										
	cout <<"\n Ingrese fecha de nacimiento del cliente:\n ";
	cout<<"Ingrese dia de nacimiento: ";
	cin >> reg->dia_nacimiento;
	cout<<"Ingrese mes de nacimiento: ";
	cin>>reg->mes_nacimiento;
	cout<<"Ingrese anio de nacimiento: ";
	cin>>reg->anio_nacimiento;
	return reg;
}

//funcion modificar cliente creado
void reg_modi_cliente()
{
	cout<<"¿\n A que cliente quieres modificar? digitar cedula del cliente \n";
	cin>>ced_busc;
	p=cab->liga_der;
	sw=0;
	while(p != NULL && sw==0)
	{
		if(p->ced_cliente == ced_busc )
		{
			cout <<"\n Ingrese nuevo nombre del cliente: ";								
			cin >> p->nom_cliente;
											
			cout <<"\n Ingrese nuevo cedula del cliente: ";
			cin >> p->ced_cliente;
											
			cout <<"\n Ingrese nuevo genero del cliente: masculino / femenino : ";
			cin >> p->genero_cliente;
											
			cout <<"\n Ingrese fecha de nacimiento del cliente:\n ";
			cout<<"Ingrese dia de nacimiento: ";
			cin >> p->dia_nacimiento;
			cout<<"Ingrese mes de nacimiento: ";
			cin>>p->mes_nacimiento;									
			cout<<"Ingrese anio de nacimiento: ";
			cin>>p->anio_nacimiento;	
			sw++;
		}	
		p=p->liga_der;
	}
	if(sw==0)
	{
		cout<<"\n El cliente no existe en la base de datos \n";
	}
}

//funcion eliminar cliente creado
void reg_elim_cliente()
{
	cout<<"\n ¿Cual es el cliente que desea eliminar?: Digite numero de cedula \n";
	cin>>ced_elim;
	sw=0;
	ant=cab;
	p=cab->liga_der;
	while(p != NULL && sw==0)
	{
		if(ced_elim == p->ced_cliente)
		{
			sw++;
		}
		else
		{
			ant=p;
			p=p->liga_der;
		}
	}
	if(sw==1)
	{
		ant->liga_der = p->liga_der;
		q=p->liga_der;
		if(q != NULL) //si solamente es un registro, para que no se dañe
		{
			q->liga_izq=ant;
		}
		cout<<"\n El cliente fue eliminado exitosamente \n";
	}
	else
	{
		cout<<"\n El cliente no existe en la base del banco \n";	
	}
}
//funcion consultar cliente creado
void reg_consul_cliente()
{
	cout<<"\n ¿Cual es el cliente que desea consultar?: Digite numero de cedula \n";
	cin>>ced_consul;
	p=cab->liga_der;
	sw=0;
	while(p != NULL && sw==0)
	{
		if(p->ced_cliente == ced_consul)
		{
			cout<<"\n El nombre del cliente es: "<< p->nom_cliente;
			cout<<"\n La cedula del cliente es: "<<p->ced_cliente;
			cout<<"\n El genero del cliente es: "<<p->genero_cliente;
			cout<<"\n La fecha del nacimiento del cliente es: "<<p->dia_nacimiento<<"/"<<p->mes_nacimiento<<"/"<<p->anio_nacimiento<<"\n \n";
			sw++;
		}
		p=p->liga_der;
		}
		if(sw==0)
		{
			cout<<"\n El cliente no existe en la base de datos \n";
		}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//funcion adicionar cuenta
regis reg_cuenta_new()
{
	cout <<"\n Ingrese cedula del cliente: ";
	cin >>ced_consul;
	p=cab->liga_der;
	sw=0;
	while(p != NULL && sw==0)
	{
		if(ced_consul == p->ced_cliente)
		{
			regis regc = new(struct cuenta);
			regc->cedu_cliente=ced_consul;
			cout <<"\n Ingrese numero de cuenta: ";
			cin >> regc->num_cuenta;
			cout <<"\n Ingrese saldo disponible: ";
			cin >> regc->sal_cuenta;
			cout <<"\n **Cuenta registrada correctamente** \n";				
			return regc;
			sw++;
		}
		else
		{
			p=p->liga_der;
		}
	}	
	if(sw==0)
	{
		cout<<"\n **La cuenta no esta registrada en el banco** \n";
	}
}
//funcion modificar cuenta creada
void reg_modi_cuenta()
{
	cout<<"¿\n Que cuenta quieres modificar? digitar numero de cuenta del cliente \n";
	cin>>cuenta_busc;
	t=cabe->sig;
	sw=0;
	while(t != NULL && sw==0)
	{
		if(t->num_cuenta == cuenta_busc )
		{
			cout <<"\n Ingrese nuevo numero de cuenta: ";								
			cin >> t->num_cuenta;	
			cout <<"\n Ingrese nuevo numero de cedula: ";
			cin>>t->cedu_cliente;
			sw++;
			
		}	
		t=t->sig;
	}
	if(sw==0)
	{
		cout<<"\n La cuenta no esta registrada en la base de datos del cambio \n\n";
	}
}
//funcion elimiar cuenta creada
void reg_elim_cuenta()
{
	cout<<"\n ¿Cual es la cuenta que desea eliminar?: Digite numero de cuenta \n";
	cin>>cuenta_elim;
	sw=0;
	ante=cabe;
	t=cabe->sig;
	while(t != NULL && sw==0)
	{
		if(t->num_cuenta == cuenta_elim)
		{
			ante->sig = t->sig;
			y=t->sig;
			cout<<"\n la cuenta fue eliminado exitosamente \n\n";
			sw++;
		}
		ante=t;
		t=t->sig;
	}
	if(sw==0)
	{
		cout<<"\n La cuenta no esta registrada en la base del banco \n\n";
	}
}
//funcion consultar cuenta creada
void reg_consul_cuenta()
{
	cout<<"\n ¿Cual es el numero de cuenta que sea consultar?: Digite numero de cuenta \n";
	cin>>num_cuenta_consul;
	t=cabe->sig;
	p=cab->liga_der;
	sw=0;
	st=0;
	while(t != NULL && sw==0)
	{
		if(t->num_cuenta == num_cuenta_consul)
		{
			while(p != NULL && st==0)
			{
				if(t->cedu_cliente == p->ced_cliente)
				{
					cout<<"\n El nombre del cliente es: "<< p->nom_cliente;
					cout<<"\n La cedula del cliente es: "<<p->ced_cliente;
					st++;
				}
				p=p->liga_der;
			}
			cout<<"\n El numero de cuenta es: "<<t->num_cuenta;
			cout<<"\n El saldo de la cuenta es: "<<t->sal_cuenta<<"\n\n";
			sw++;
		}
		t=t->sig;
	}
	if(sw==0)
	{
		cout<<"\n La cuenta no existe en la base de datos \n\n";
	}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//funcion consignacion cuenta
regist consignacion_cuen()
{
	cout<<"\n Ingrese numero de cuenta a la que desea hacer la consignacion: \n";
	cin>>num_cuenta;
	t=cabe->sig;
	sw=0;
	while(t != NULL && sw==0)
	{
		if(num_cuenta == t->num_cuenta)
		{
			regist regb = new(struct operaciones);
			cout<<"\n Ingrese dia: \n";
			cin>>regb->dia_trans;
			cout<<"\n Ingrese mes: \n";
			cin>>regb->mes_trans;
			cout<<"\n Ingrese anio: \n";
			cin>>regb->anio_trans;
			regb->consecutivo=kilo;
			kilo+=111;
			cout<<"\n Ingrese la cantidad a consignar: \n";
			cin>>dinero;
			t->sal_cuenta=dinero + t->sal_cuenta;
			regb->valor=dinero;
			regb->nume_cuenta=t->num_cuenta;
			regb->tip_trans="**Consignacion**";
			sw++;
			cout<<"\n Dinero consignado a la cuenta "<<t->num_cuenta<<" Correctamente \n";
			return regb;
		}
		else
			t=t->sig;
	}
	if(sw==0)
	{
		cout<<"\n La cuenta no esta registrada en el sistema \n";
	}
}
//funcion retiro cuenta
regist retiro_cuen()
{
	cout<<"\n Ingrese numero de cuenta a la que desea hacer el retiro: ";
	cin>>num_cuentaa;
	t=cabe->sig;
	sw=0;
	while(t != NULL && sw==0)
	{
		if(num_cuentaa == t->num_cuenta)
		{
			regist regb = new(struct operaciones);
			regb->nume_cuenta=t->num_cuenta;
			sw++;
			cout<<"\n Ingrese dia: \n";
			cin>>regb->dia_trans;
			cout<<"\n Ingrese mes: \n";
			cin>>regb->mes_trans;
			cout<<"\n Ingrese anio: \n";
			cin>>regb->anio_trans;
			regb->consecutivo=kilo;
			kilo+=111;
			cout<<"\n Ingrese la cantidad a retirar: \n";
			cin>>dinero;
			if(t->sal_cuenta >= dinero)
			{
				t->sal_cuenta=t->sal_cuenta - dinero;
				regb->valor=dinero;
				regb->tip_trans="**Retiro**";
				cout<<"\n Dinero retirado de la cuenta "<<t->num_cuenta<<" Exitosamente \n";
			}
			else
			{
				regb->consecutivo=con;
				regb->valor=dinero;
				regb->tip_trans="**Saldo insuficiente**";
				cout<<"\n **Saldo insuficiente**\n";
			}
			return regb;
		}
		t->sig;
	}
	if(sw==0)
	{
		cout<<"\n la cuenta no esta registrada en el sistema \n";
	}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//consulta clientes
void client_consultas()
{
	cout<<"\n Ingrese numero de cedula a buscar en la base de datos del banco: \n";
	cin>>ced_busc;
	p=cab->liga_der;
	t=cabe->sig;
	m=cam->liga_der;
	
	sw=0;
	st=0;
	sr=0;
	while(p != NULL && sw==0)
	{
		if(ced_busc == p->ced_cliente)
		{
			cout<<"\n El nombre del cliente es: "<< p->nom_cliente;
			cout<<"\n La cedula del cliente es: "<<p->ced_cliente;
			cout<<"\n El genero del cliente es: "<<p->genero_cliente;
			cout<<"\n La fecha del nacimiento del cliente es: "<<p->dia_nacimiento<<"/"<<p->mes_nacimiento<<"/"<<p->anio_nacimiento;
			while(t != NULL && st==0)
			{
				if(p->ced_cliente == t->cedu_cliente)
				{
					cout<<"\n El numero de cuenta es: "<<t->num_cuenta;
					cout<<"\n El saldo de la cuenta es: "<<t->sal_cuenta<<"\n";
					st++;
				}
				t=t->sig;
			}
			/*cout<<"\n \t \t ...Operaciones realizadas...";
			while(m != cam )///&& sr==0)
			{
				if(m->nume_cuenta == t->num_cuenta)
				{
					cout<<"\n El tipo de movimiento realizado fue: "<<m->tip_trans;
					cout<<"\n Numero del consecutivo es: "<<m->consecutivo;
					cout<<"\n La fecha del movimiento es: "<<m->dia_trans<<"/"<<m->mes_trans<<"/"<<m->anio_trans;
					cout<<"\n El valor de la transferencia fue de: "<<m->valor<<"\n \n";
					//sr++;
				}
				m=m->liga_der;
			}*/
			sw++;
		}
		p=p->liga_der;
	}
		if(sw==0)
		{
			cout<<"\n El cliente no existe en la base de datos \n";
		}
}
//Apilar registros hombres
void apilar_hombres(registroo tope)
{
	cout << "\n\n Registros guardados que son hombres:\n \n";
	registroo k;
	k=tope;
	sw=0;
	while (k != NULL)
	{
		sw++;
		cout <<"\n El registro numero "<<sw<<" Es: \n";
		cout<<"Nombre del cliente: "<<k->nombre<<"  Cedula: "<<k->cedula<<"  Genero: "<<k->genero<<"  Fecha de nacimiento: "<<k->dia<<"/"<<k->mes<<"/"<<k->anio<<"  ";
		cout<<"\n Datos de la cuenta: Numero de cuenta: "<<k->num_cuenta<<"  Salario cuenta: "<<k->saldo<<"\n";
		k=k->sig;
	}
}
//Apilar registros cuyo salario sea mayor a cinco millones
void apilar_may(registr topee)
{
	cout<< "\n\n Registros guardados cuyo saldo es mayor a cinco millones: \n \n";
	registr l;
	l=topee;
	sw=0;
	while(l != NULL)
	{
		sw++;
		cout <<"\n El registro numero "<<sw<<" Es: \n";
		cout<<"Nombre del cliente: "<<l->nombr<<"  Cedula: "<<l->cedul<<"  Genero: "<<l->gener<<"  Fecha de nacimiento: "<<l->dia_n<<"/"<<l->mes_n<<"/"<<l->anio_n<<"  ";
		cout<<"\n Datos de la cuenta: Numero de cuenta: "<<l->num_cuent<<"  Salario cuenta: "<<l->sald<<"\n";
		l=l->sig;
	}
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
int main()
{
	//inicializacion estructuras
	regist regb = new(struct operaciones);
	cam=regb;
	amt=regb;
	cam->liga_der=regb;
	cam->liga_izq=regb;
	regis regc = new(struct cuenta);
	cabe=regc;
	ante=regc;
	cabe->sig=NULL;
	registro reg = new(struct cliente);					
	cab=reg;
	ant=reg;
	cab->liga_der=NULL;
	cab->liga_izq=ant;
	//pilas
	registroo tope;
	tope=NULL;
	registr topee;
	topee=NULL;
	//cola
	primero=NULL;
	ultimo=NULL;
//MENU PRINCIPAL
	menu_principal();
	cin >>resp_menprinci;
	while(resp_menprinci != 5)
	{
		switch(resp_menprinci)
		{
//MENU CLIENTES
			case 1: menu_clientes();
					cin>>resp_menclien;
					switch(resp_menclien)
					{
						case 1:
						{	
							registro reg = new(struct cliente);
							reg=reg_cliente_new();
							reg->liga_der=NULL;
							reg->liga_izq=ant;
							ant->liga_der=reg;										
							ant=reg;
						}
						break;
						case 2: reg_modi_cliente();
						break;
						case 3: reg_elim_cliente();
						break;
						case 4: reg_consul_cliente();
						break;
					}
			break;
//MENU CUENTA
			case 2: menu_cuentas();
					cin>>resp_mencuent;
					switch(resp_mencuent)
					{
						case 1: 
						{
							regis regc = new(struct cuenta);
							regc=reg_cuenta_new();
							regc->sig=NULL;
							ante->sig=regc;
							ante=regc;
						}
						break;
						case 2: reg_modi_cuenta();
						break;
						case 3: reg_elim_cuenta();
						break;
						case 4: reg_consul_cuenta();
						break;
					}
			break;
//MENU OPERACIONES
			case 3: menu_operaciones();
			cin>>resp_menopereac;
			switch(resp_menopereac)
			{
				case 1: 
				{
					regist regb = new(struct operaciones);
					regb=consignacion_cuen();
					regb->liga_der=cam;
					regb->liga_izq=amt;
					//cam->liga_der=regb;
					amt->liga_der=regb;								
					amt=regb;
				}
				break;
				case 2: 
				{	
					regist regb = new(struct operaciones);
					regb=retiro_cuen();
					regb->liga_der=cam;
					regb->liga_izq=amt;
					//cam->liga_der=regb;
					amt->liga_der=regb;					
					amt=regb;
				}
				break;
			}
//MENU CONSULTAS
			break;
			case 4: menu_consultas();
			cin>>resp_menconsul;
			switch(resp_menconsul)
			{
				case 1: client_consultas();
				break;
				case 2: 
				{
					p=cab->liga_der;
					t=cabe->sig;
					while(p != NULL)
					{
						if(p->genero_cliente == "masculino")
						{
							registroo regv = new(struct pilas_hombres);  
							regv->nombre=p->nom_cliente;
							regv->cedula=p->ced_cliente;
							regv->genero=p->genero_cliente;
							regv->dia=p->dia_nacimiento;
							regv->mes=p->mes_nacimiento;
							regv->anio=p->anio_nacimiento;
							sw=0;
							while(sw==0)
							{
								if(p->ced_cliente == t->cedu_cliente)
								{
									regv->num_cuenta=t->num_cuenta;
									regv->saldo=t->sal_cuenta;
									sw++;
								}
								t=t->sig;
							}
							regv->sig=tope;
							tope=regv;
						}
						p=p->liga_der;
					}
				apilar_hombres(tope);
				}
				break;
				case 3:
				{
					p=cab->liga_der;
					t=cabe->sig;
					while(p != NULL)
					{
						if(t->sal_cuenta >= 5000000)
						{
							registr regx = new(struct pilas_may);  
							regx->nombr=p->nom_cliente;
							regx->cedul=p->ced_cliente;
							regx->gener=p->genero_cliente;
							regx->dia_n=p->dia_nacimiento;
							regx->mes_n=p->mes_nacimiento;
							regx->anio_n=p->anio_nacimiento;
							sw=0;
							while(sw==0)
							{
								if(p->ced_cliente == t->cedu_cliente)
								{
									regx->num_cuent=t->num_cuenta;
									regx->sald=t->sal_cuenta;
									sw++;
								}
								t=t->sig;
							}
							regx->sig=topee;
							topee=regx;
						}
						p=p->liga_der;
					}
					apilar_may(topee);
					}
				break;
				case 4:
					{
						m=cam->liga_der;
						while(m != cam)
						{
							regi regm=new(struct transc);
							regm->consecu=m->consecutivo;
							regm->numero_cuen=m->nume_cuenta;
							
							regm->dia_tra=m->dia_trans;
							regm->mes_tra=m->mes_trans;
							regm->anio_tra=m->anio_trans;
							
							regm->tra=m->tip_trans;
							regm->valortra=m->valor;
							if (primero==NULL)
							{
								primero=regm;
								ultimo=regm;
								primero->sig=NULL;
							}
							else
							{
								ultimo->sig=regm;
								regm->sig=NULL;
								ultimo=regm;
							}
							m=m->liga_der;
						}
						cout<<"\n\n Registros guardados de transacciones son: \n \n";
						h=primero;
						sw=0;
						while(h != NULL)
						{
							sw++;
							cout<<"\n la transaccion numero "<<sw<<" Realizada es: \n";
							cout<<"Numero consecutivo es: "<<h->consecu<<"\n Numero de cuenta es "<<h->numero_cuen;
							cout<<"\n Fecha de transaccion es: "<<h->dia_tra<<"/"<<h->mes_tra<<"/"<<h->anio_tra<<" ";
							cout<<"\n El tipo de transaccion fue "<<h->tra<<"\n El valor de la transaccion fue de: "<<h->valortra<<"\n";
							h=h->sig; 
						}
					}
				break;
			}
			break;
			case 5: return 0;
			break;
		}
	menu_principal();
	cin >>resp_menprinci;
	}
	
	
}
