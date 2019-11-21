
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;
struct nod {
  char nume [20];
  char tip [20];

            int pret;
            int rating;
            bool mana;
            bool gen;
    struct
        {
            int zi;
            int an;
            int luna;
        }apar;
  nod*urm;
} *prim;
void creare(nod*&prim)
{
    char s[60],*p,mana[2],gen[2] ;
        nod *nou,*ultim;
        ifstream g ("lista.in");
  prim=new nod;
ultim=prim;
        while(g.get(s,60))
        {
            nou=new nod;

p=strtok(s," ");
            strcpy(nou->nume,p);

p=strtok(NULL," ");
            strcpy(nou->tip,p);
p=strtok(NULL," ");
            strcpy(gen,p);
             if(gen[1]=='m')


                    prim->gen=true;
                else if(gen[1]=='f')
                    prim->gen=false;
p=strtok(NULL," ");
            strcpy(mana,p);
            if(mana[1]=='y')
                    prim->mana=true;
                else if(mana[1]=='n')
                    prim->mana=false;


p=strtok(NULL," ");

            nou->rating=atoi(p);

p=strtok(NULL," ");

            nou->pret=atoi(p);


    p=strtok(NULL," ");
            nou->apar.zi=atoi(p);

    p=strtok(NULL," ");
            nou->apar.luna=atoi(p);
p=strtok(NULL," ");
            nou->apar.an=atoi(p);


            g.get();

            ultim->urm=nou;
            nou->urm=NULL;
            ultim=nou;

        }
        prim=prim->urm;
}
void parcurgere(nod*p)
{  while(p!=NULL){
      cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;

     p=p->urm;}

 }
void ADD(nod*&p1,int x)
{
    int i;
    nod*ajut,*p;
    ajut=new nod;
    p=p1;
    char ajuto [2];

           cout<<"Rating = ";
            cin>>ajut->rating;

            cout<<"Introduceti gen erou (m/f)";
            cin>>ajuto;
                if(ajuto[1]=='m')
                    ajut->gen=true;
                else if(ajuto[1]=='f')
                    ajut->gen=false;

            cout<<"Introduceti daca eroul are sau nu mana erou (y/n)";
            cin>>ajuto;
                if(ajuto[1]=='y')
                    ajut->gen=true;
                else if(ajuto[1]=='n')
                    ajut->gen=false;

            cout<<"introduceti ziua";
            cin>>ajut->apar.zi;

            cout<<"introduceti luna";
            cin>>ajut->apar.luna;

            cout<<"introduceti an";
            cin>>ajut->apar.an;

    if (x==1)
    {

        ajut->urm=p;
        p1=ajut;

    }
    else
    {

        for(i=1;i<=x-1;i++)
        {
            p=p->urm;
        }

        ajut->urm=p->urm;
        p->urm=ajut;


    }
}
void ordonare()
{
      nod *c;int ord,an1,zi1,luna1;float aux;bool aux1,aux2; char nume1[20],tip[20];
     do
     {c=prim;
      ord=1;
      while(c->urm)
             {if(strcmp(c->urm->nume,c->nume)<=0)
                        {   aux=c->rating;
                            strcpy(nume1,c->nume);
                            strcpy(tip,c->nume);
                            aux1=c->mana;
                            aux2=c->gen;
                            zi1=c->apar.zi;
                            luna1=c->apar.luna;
                            an1=c->apar.an;

                            c->rating=c->urm->rating;
                            strcpy(c->nume,c->urm->nume);
                            strcpy(c->tip,c->urm->tip);
                            c->mana=c->urm->mana;
                            c->gen=c->urm->gen;
                            c->apar.luna=c->urm->apar.luna;
                            c->apar.an=c->urm->apar.an;
                            c->apar.zi=c->urm->apar.zi;

                            c->urm->rating=aux;
                            strcpy(c->urm->nume,nume1);
                            strcpy(c->urm->tip,tip);
                            c->urm->mana=aux1;
                            c->urm->gen=aux2;
                            c->urm->apar.luna=luna1;
                            c->urm->apar.an=an1;
                            c->urm->apar.zi=zi1;
                            ord=0;
                        }
              c=c->urm;}
      }
    while(ord==0);
}
void ordonare1()
{
      nod *c;int ord,an1,zi1,luna1;float aux;bool aux1,aux2; char nume1[20],tip[20];
     do
     {c=prim;
      ord=1;
      while(c->urm)
             {if(c->rating>c->urm->rating)
                        {   aux=c->rating;
                            strcpy(nume1,c->nume);
                            strcpy(tip,c->nume);
                            aux1=c->mana;
                            aux2=c->gen;
                            zi1=c->apar.zi;
                            luna1=c->apar.luna;
                            an1=c->apar.an;

                            c->rating=c->urm->rating;
                            strcpy(c->nume,c->urm->nume);
                            strcpy(c->tip,c->urm->tip);
                            c->mana=c->urm->mana;
                            c->gen=c->urm->gen;
                            c->apar.luna=c->urm->apar.luna;
                            c->apar.an=c->urm->apar.an;
                            c->apar.zi=c->urm->apar.zi;

                            c->urm->rating=aux;
                            strcpy(c->urm->nume,nume1);
                            strcpy(c->urm->tip,tip);
                            c->urm->mana=aux1;
                            c->urm->gen=aux2;
                            c->urm->apar.luna=luna1;
                            c->urm->apar.an=an1;
                            c->urm->apar.zi=zi1;
                            ord=0;
                        }
              c=c->urm;}
      }
    while(ord==0);
}
void cautarerating(nod*p,int z)
{
    while(p!=NULL)
    {
      if(p->rating<=z)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

 }
 void cautarenume(nod*p,char num[20])
{
    while(p!=NULL)
    {
      if(strncmp(num,p->nume,3)==0)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

}
void cautarepret(nod*p,int z)
{
    while(p!=NULL)
    {
      if(p->pret<=z)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

 }
 void cautaremana(nod*p)
{
    while(p!=NULL)
    {
      if(p->mana!=true)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

 }
 void cautarenumana(nod*p)
{
    while(p!=NULL)
    {
      if(p->mana==true)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

 }
 void cautaregenm(nod*p)
{
    while(p!=NULL)
    {
      if(p->gen!=true)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }}}
void cautaregenf(nod*p)
{
    while(p!=NULL)
    {
      if(p->gen==true)
      {
cout<<"Nume       :";
      cout<<p->nume<<endl;
      cout<<"tip       :";
      cout<<p->tip<<endl;
     cout<<"Data aparitiei= "<<p->apar.zi<<"/"<<p->apar.luna<<"/"<<p->apar.an<<endl;
     cout<<"rating        = "<<p->rating<<endl;
     cout<<"pret          = "<<p->pret<<endl;

     if(p->gen!=true)
        cout<<"Gen masculin"<<endl;
   else cout<<"gen feminin"<<endl;
      if(p->mana!=true)
        cout<<"are mana"<<endl<<endl;
   else cout<<"nu are mana"<<endl<<endl;



      }
     p=p->urm;
     }

 }

 int main ()
{
creare (prim);
int k,i;
char nume1[20];

    int choice;
bool gameOn = true;
while (gameOn != false){



cout << " 1  =Afisare lista campioni .\n";
cout << " 2  =Eliminati  campioni.\n";
cout << " 3  =Adaugare din campioni .\n";
cout << " 4  =Ordonare nume .\n";
cout << " 5  =Ordonare rating .\n";
cout << " 6  =Cautare campioni dupa pret .\n";
cout << " 7  =Cautare campioni dupa nume .\n";
cout << " 8  =Cautare campioni dupa rating .\n";
cout << " 9  =Cautarea avansata .\n";

cout << " 10 -  Iesiti din program .\n";

cout << " Introduceti  tasta dorita apoi apasati Enter: ";

cin >> choice;

switch (choice)
{




    case 1:
        parcurgere(prim);
    break;

    case 2:
        cout<<"Introdeceti pe tastatura al cate-lea  element doriti sa il eliminati";
        cin >>k;
    //    eliminare(prim,k);
        cout<<"Elementul a fost eliminat";
    break;

    case 3:
        cout<<"Introdeceti pe tastatura dupa cal catelea element doriti sa inserati";
        cin >>k;
        ADD(prim,k);
        cout<<"Elementul a fost adaugat";
    break;

    case 4:
        ordonare();
    break;
    case 5:
        ordonare1();
    break;

    case 6:
        cout<<"Introdeceti pretul maxim ";
        cin >>k;
        cautarepret(prim,k);

    break;

     case 7:
        cout<<"Introdeceti numele ";
        cin >>nume1;
        cautarenume(prim,nume1);

    break;
    case 8:
        cout<<"Introdeceti rating ";
        cin >>k;
        cautarerating(prim,k);

    break;

    case 9:
        system("CLS");cout<<"Cautare avansata";cout<<"Pentru cautare eroi cu mana apasa 1\n Pentru cautare eroi fara mana apasa 2\n\nPentru cautare eroi masculini apasa 3\nPentru cautare eroi feminini apasa 4\n";
       cin>>i;
        switch (i)
        {

            case 1:
cautaremana(prim);
            break;
            case 2:
cautarenumana(prim);
            break;
            case 3:
cautaregenm(prim);
            break;
            case 4:
cautaregenf(prim);
            break;
        }



    break;

    case 10:
        cout << "Sfarsitul programului.\n";
        gameOn = false;
    break;

    default:system("CLS");

    break;
}

}
return 0;



}



