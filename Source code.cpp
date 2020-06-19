#include<iostream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

class persoana
{
protected:
	string nume,prenume,CNP,str;
public:
		persoana()
		{
			nume="";
			prenume="";
			CNP="";
			str="";
		}
		persoana(string nume,string prenume,string CNP,string str)
		{
			this->nume=nume;
			this->prenume=prenume;
			this->CNP=CNP;
			this->str=str;
		}
		persoana& operator=(const persoana &obj)
		{
			nume=obj.nume;
			prenume=obj.prenume;
			CNP=obj.CNP;
			str=obj.str;
		}
		~persoana()
		{
			nume.erase();
			prenume.erase();
			CNP.erase();
			str.erase();
		}
		string get_nume()
		{
			return nume;
		}
		string get_prenume()
		{
			return prenume;
		}
		string get_cnp()
		{
			return CNP;
		}
		string get_str()
		{
			return str;
		}
		virtual void afisare()
		{
	
				cout<<"Persoana "<<endl;
				cout<<"Nume: "<<nume<<endl;
				cout<<"Prenume: "<<prenume<<endl;
				cout<<"CNP: "<<CNP<<endl;
				cout<<"Strada: "<<str<<endl;
		}
		virtual int get_venit()
		{
			return 0;
		}
};

class angajat:public persoana
{
	int salariu;
	public:
		angajat()
		{
			salariu=0;
		}
		angajat(string nume,string prenume,string CNP,string str,int salariu):persoana(nume,prenume,CNP,str)
		{
			this->salariu=salariu;
		}
		angajat& operator=(const angajat &obj)
		{
			persoana::operator=(obj);
			salariu=obj.salariu;
		}
		void afisare()
		{
			persoana::afisare();
			cout<<"Salariu: "<<salariu<<endl;
			cout<<" "<<endl;
		}
		int get_venit()
		{
			return salariu;
		}
		
};

class pensionar:public persoana
{
	int pensie;
	public:
		pensionar()
		{
			pensie=0;
		}
	pensionar(string nume,string prenume,string CNP,string str,int pensie):persoana(nume,prenume,CNP,str)
		{
			this->pensie=pensie;
		}
		pensionar& operator=(const pensionar &obj)
		{
			persoana::operator=(obj);
			pensie=obj.pensie;
		}
		void afisare()
		{
			persoana::afisare();
			cout<<"Pensie: "<<pensie<<endl;
			cout<<" "<<endl;
		}
		int get_venit()
		{
			return pensie;
		}
};

void sortare(persoana **v,int n) {

    persoana *aux;

    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            {
				if (v[i]->get_nume() > v[j]->get_nume()) 
					{
                		aux = v[i];
                		v[i] = v[j];
                		v[j] = aux;
            		}
            	if(v[i]->get_nume()==v[j]->get_nume())
            		{
            			if(v[i]->get_prenume() > v[j]->get_prenume())
            				{
            					aux = v[i];
                				v[i] = v[j];
                				v[j] = aux;
							}
					}
        	}
}

int main()
{
	ifstream f1,f2;
	ofstream f3,f4;
	f1.open("A.txt");
	if(!f1)
	cout<<"Eroare la deschiderea fisierului A"<<endl;
	f2.open("B.txt");
	if(!f1)
	cout<<"Eroare la deschiderea fisierului B"<<endl;
	char num[20],pren[25],cnp[20],str[30];
	int nr1,nr2,sal;
	f1>>nr1;
	f2>>nr2;
	int n=nr1+nr2;
	persoana **vector;
	vector=new persoana*[n];
	for(int i=0;i<nr1;i++)
	{
		f1>>num;
		f1>>pren;
		f1>>cnp;
		f1>>str;
		f1>>sal;
		vector[i]=new angajat(num,pren,cnp,str,sal);
	}
	for(int i=nr1;i<(n);i++)
	{
		f2>>num;
		f2>>pren;
		f2>>cnp;
		f2>>str;
		f2>>sal;
		vector[i]=new pensionar(num,pren,cnp,str,sal);
	}
	sortare(vector,n);
	for(int i=0;i<nr1;i++)
	{
		vector[i]->afisare();
	}
	for(int i=nr1;i<n;i++)
		vector[i]->afisare();
	f3.open("C.txt");
	if(!f3)
	cout<<"Eroare la deschiderea fisierului C";
	for(int i=0;i<n;i++)
		f3<<vector[i]->get_nume()<<" "<<vector[i]->get_prenume()<<" "<<vector[i]->get_cnp()<<" "<<vector[i]->get_str()<<" "<<vector[i]->get_venit()<<"\n";
	
	f4.open("D.txt");
	if(!f4)
	cout<<"Eroare la deschiderea fisierului D";
	string strada("Veteranilor");
	for(int i=0;i<n;i++)
	{
		if((vector[i]->get_cnp()[0]=='2' || vector[i]->get_cnp()[0]=='4' || vector[i]->get_cnp()[0]=='6' || vector[i]->get_cnp()[0]=='8')\
		 && (vector[i]->get_cnp()[1]=='8' && vector[i]->get_cnp()[2]=='0') && vector[i]->get_str().compare(strada)==0)
		{
			f4<<vector[i]->get_nume()<<" "<<vector[i]->get_prenume()<<"\n";
		
		}
	}
	f1.close();
	f2.close();
	f3.close();
	f4.close();
	return 0;
}
