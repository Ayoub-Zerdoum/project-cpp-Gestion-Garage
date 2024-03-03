#include "header10.h"
#include"algorithm"
#include<algorithm>
#include<stack>
#include<vector>
#include<list>


// -------------- class date -------------------//
date::date(int j,int m,int a)
{
    this->jour=j;
    this->mois=m;
    this->annee=a;
}

ostream& operator<<(ostream& o,date& d)
{
    o<<d.jour<<"/"<<d.mois<<"/"<<d.annee;
    return o;
}

istream& operator>>(istream& i,date& d)
{
    string msg;
    string msg1="ERREUR - le jour doit etre superieur a 0";
    string msg2="ERREUR - le jour doit etre inferieur a 31";
    string msg3="ERREUR - le mois doit etre superieur a 0";
    string msg4="ERREUR - le mois doit etre inferieur a 12";
    string msg5="ERREUR - l'annee doit etre superieur a 0";
    while(true)
    {
        try
        {
            cout<<"saisir le jour   ";
            i>>d.jour;
            if(d.jour<=0) throw msg1;
            if(d.jour>31) throw msg2;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }
    while(true)
    {
        try
        {
            cout<<"saisir le mois    ";
            i>>d.mois;
            if(d.mois<=0) throw msg3;
            if(d.mois>12) throw msg4;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }
    while(true)
    {
        try
        {
            cout<<"saisir l'annee";
            i>>d.annee;
            if(d.annee<=0) throw msg5;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }
    return i;
}

ostream& operator<<(ostream& o,date* d)
{
     o<<setw(5)<<d->jour<<"  "<<setw(5)<<d->mois<<"  "<<setw(5)<<d->annee;
     return o;
}

istream& operator>>(istream& i,date* d)
{
    i>>d->jour;
    i>>d->mois;
    i>>d->annee;
    return i;
}

// -------------- class personne -------------------//
personne::personne(int id,int age,string nom ,string prenom,int tel)
{
    this->id=id;
    this->age=age;
    this->nom=nom;
    this->prenom=prenom;
    this->telephone=tel;
}

personne::personne(const personne& p)
{
    this->id=p.id;
    this->age=p.age;
    this->nom=p.nom;
    this->prenom=p.prenom;
    this->telephone=p.telephone;
}

void personne::afficher()
{
    cout<<"l'id est : "<<id<<endl;
    cout<<"l'age est : "<<age<<endl;
    cout<<"le nom est : "<<nom<<endl;
    cout<<"le prenom est : "<<prenom<<endl;
    cout<<"le numero du telephone est : "<<telephone<<endl;
}

ostream& operator<<(ostream& o,personne& p)
{
    o<<"l'id est : "<<p.id<<endl;
    o<<"l'age est : "<<p.age<<endl;
    o<<"le nom est : "<<p.nom<<endl;
    o<<"le prenom est : "<<p.prenom<<endl;
    o<<"le numero du telephone est : "<<p.telephone<<endl;
    return o;
}

ostream& operator<<(ostream& o,personne* p)
{
    o<<setw(5)<<p->id<<"   ";
    o<<setw(5)<<p->age<<"   ";
    o<<setw(5)<<p->nom<<"   ";
    o<<setw(5)<<p->prenom<<"   ";
    o<<setw(5)<<p->telephone<<endl;
    return o;
}

istream& operator>>(istream& i,personne* p)
{
    i>>p->id;
    i>>p->age;
    i>>p->nom;
    i>>p->prenom;
    i>>p->telephone;
    return i;
}
// -------------- class  client -------------------//
client::client(int id,int age,string nom ,string prenom,int tel,int num,date d,string ville):personne(id,age,nom,prenom,tel)
{
    this->num_permis=num;
    this->date_obtention=d;
    this->ville=ville;
}

void client::afficher()
{
    cout<<"l'id est : "<<id<<endl;
    cout<<"l'age est : "<<age<<endl;
    cout<<"le nom est : "<<nom<<endl;
    cout<<"le prenom est : "<<prenom<<endl;
    cout<<"le numero du telephone est : "<<telephone<<endl;

    cout<<"le numero du permis est : "<<num_permis<<endl;
    cout<<"la date est : "<<date_obtention<<endl;
    cout<<"la ville est : "<<ville<<endl;
}


ostream& operator<<(ostream& o,client& c)
{
    o<<"l'id est : "<<c.id<<endl;
    o<<"l'age est : "<<c.age<<endl;
    o<<"le nom est : "<<c.nom<<endl;
    o<<"le prenom est : "<<c.prenom<<endl;
    o<<"le numero du telephone est : "<<c.telephone<<endl;

    o<<"le numero du permis est : "<<c.num_permis<<endl;
    o<<"la date est : "<<c.date_obtention<<endl;
    o<<"la ville est : "<<c.ville<<endl;
    return o;
}

istream& operator>>(istream& i,client& c)
{
    string msg;
    string msg1="ERREUR - le client existe deja";
    string msg2="ERREUR - l'id doit etre un entier";
    string msg3="ERREUR - l'id doit etre positive";
    string msg4="ERREUR - l'age doit etre positive";
    string msg5="ERREUR - l'age doit etre superieur a 18";
    string msg6="ERREUR - l'age doit etre un entier";
    string msg7="ERREUR - telephone non valide";
    string msg8="ERREUR - le telephone est conposé de 8 caractére";
    string msg9="ERREUR - le numero de permis doit etre positive";
    string msg10="ERREUR - le numero non valide";
    while(true)
    {
        try
        {
            cout<<"saisir l'id                      ";
            i>>c.id;
            if(cin.fail()) throw 1;
            if(c.id<=0)    throw msg3;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg2<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir l'age                     ";
            i>>c.age;
            if(cin.fail()) throw 1;
            else if(c.age<0)     throw msg4;
            else if(c.age<18)     throw msg5;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg6<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le nom                    ";
            i>>c.nom;
            cout<<"saisir le prenom                 ";
            i>>c.prenom;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le numero du telephone    ";
            i>>c.telephone;
            if(cin.fail()) throw 1;
            else if(c.telephone<10000000 || c.telephone>99999999)     throw msg8;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg7<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le numero du permis       ";
            i>>c.num_permis;
            if(cin.fail()) throw 1;
            else if(c.num_permis<0)     throw msg9;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg10<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout<<"saisir la date d'obtention du permis"<<endl;
    i>>c.date_obtention;
    cout<<"saisir la ville                  ";
    i>>c.ville;
    return i;
}

ostream& operator<<(ostream& o,client* c)
{
    o<<setw(5)<<c->id<<"   ";
    o<<setw(5)<<c->age<<"   ";
    o<<setw(5)<<c->nom<<"   ";
    o<<setw(5)<<c->prenom<<"   ";
    o<<setw(5)<<c->telephone<<"   ";
    o<<setw(5)<<c->num_permis<<"   ";
    o<<setw(10)<<&c->date_obtention<<"   ";
    o<<setw(5)<<c->ville<<endl;
    return o;
}

istream& operator>>(istream& i,client* c)
{
    i>>c->id;
    i>>c->age;
    i>>c->nom;
    i>>c->prenom;
    i>>c->telephone;

    i>>c->num_permis;
    i>>&c->date_obtention;
    i>>c->ville;
    return i;
}
// -------------- class employee -------------------//
employee::employee(int id,int age,string nom ,string prenom,int tel,float salaire,string specialite,string address):personne(id,age,nom,prenom,tel)
{
    this->salaire=salaire;
    this->specialite=specialite;
    this->address= address;
}

void employee::afficher()
{
    cout<<"l'id est : "<<id<<endl;
    cout<<"l'age est : "<<age<<endl;
    cout<<"le nom est : "<<nom<<endl;
    cout<<"le prenom est : "<<prenom<<endl;
    cout<<"le numero du telephone est : "<<telephone<<endl;

    cout<<"la salaire est : "<<salaire<<endl;
    cout<<"la specialité est : "<<specialite<<endl;
    cout<<"l'address est : "<<address<<endl;
}

ostream& operator<<(ostream& o,employee& e)
{
    o<<"l'id est : "<<e.id<<endl;
    o<<"l'age est : "<<e.age<<endl;
    o<<"le nom est : "<<e.nom<<endl;
    o<<"le prenom est : "<<e.prenom<<endl;
    o<<"le numero du telephone est : "<<e.telephone<<endl;

    o<<"la salaire est : "<<e.salaire<<endl;
    o<<"la specialité est : "<<e.specialite<<endl;
    o<<"l'address est : "<<e.address<<endl;
    return o;
}

istream& operator>>(istream& i,employee& e)
{
    string msg;
    string msg1="ERREUR - l'employee existe deja";
    string msg2="ERREUR - l'id doit etre un entier";
    string msg3="ERREUR - l'id doit etre positive";
    string msg4="ERREUR - l'age doit etre positive";
    string msg5="ERREUR - l'age doit etre superieur a 18";
    string msg6="ERREUR - l'age doit etre un entier";
    string msg7="ERREUR - telephone non valide";
    string msg8="ERREUR - le telephone est conposé de 8 caractére";
    string msg9="ERREUR - la salaire doit etre positive";
    string msg10="ERREUR - salaire non valide";
    string msg11="ERREUR - specialite n'existe pas";

    while(true)
    {
        try
        {
            cout<<"saisir l'id                      ";
            i>>e.id;
            if(cin.fail()) throw 1;
 //           if(employee_existe(e.id)) throw msg1;
            if(e.id<=0)    throw msg3;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg2<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir l'age                     ";
            i>>e.age;
            if(cin.fail()) throw 1;
            else if(e.age<0)     throw msg4;
            else if(e.age<18)     throw msg5;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg6<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le nom                    ";
            i>>e.nom;
            cout<<"saisir le prenom                 ";
            i>>e.prenom;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le numero du telephone    ";
            i>>e.telephone;
            if(cin.fail()) throw 1;
            else if(e.telephone<10000000 || e.telephone>99999999)     throw msg8;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg7<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir la salaire                ";
            i>>e.salaire;
            if(cin.fail()) throw 1;
            else if(e.salaire<=0)     throw msg9;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg10<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir la specialité             ";
            i>>e.specialite;
            if(e.specialite!="mec" && e.specialite!="elec" && e.specialite!="tol") throw msg11;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }

    cout<<"saisir l'address                 ";
    i>>e.address;
    return i;
}

ostream& operator<<(ostream& o,employee* e)
{
    o<<setw(5)<<e->id<<"   ";
    o<<setw(5)<<e->age<<"   ";
    o<<setw(5)<<e->nom<<"   ";
    o<<setw(5)<<e->prenom<<"   ";
    o<<setw(5)<<e->telephone<<"   ";
    o<<setw(5)<<e->salaire<<"   ";
    o<<setw(5)<<e->specialite<<"   ";
    o<<setw(5)<<e->address<<endl;
    return o;
}

istream& operator>>(istream& i,employee* e)
{
    i>>e->id;
    i>>e->age;
    i>>e->nom;
    i>>e->prenom;
    i>>e->telephone;

    i>>e->salaire;
    i>>e->specialite;
    i>>e->address;
    return i;
}
// -------------- class facture -------------------//
facture::facture(int num,date d,float montant,string etat)
{
    this->num_facture=num;
    this->date_payement=d;
    this->montant=montant;
    this->etat=etat;
}

ostream& operator<<(ostream& o,facture& f)
{
    o<<"le numero du facture est : "<<f.num_facture<<endl;
    o<<"le montant est : "<<f.montant<<endl;
    if(f.etat=="payee")
    {
        o<<"la date du payement est : "<<f.date_payement<<endl;
        o<<"la facture est payée"<<endl;
    }
    else if(f.etat=="non_payee")
        o<<"la facture n'est payée"<<endl;

    return o;
}

istream& operator>>(istream& i,facture& f)
{
    string reponse;

    string msg1="ERREUR - le numero de facture existe deja";
    string msg2="ERREUR - numero de facture non valide";
    string msg3="ERREUR - le numero de facture doit etre positive";
    string msg5="ERREUR - montant de facture non valide";
    string msg4="ERREUR - le montant de facture doit etre positive";
    string msg6="ERREUR - reponse non valide";
    while(true)
    {
        try
        {
            cout<<"saisir le numero du facture     ";
            i>>f.num_facture;
            if(cin.fail()) throw 1;
            if(f.num_facture<0)    throw msg3;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg2<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"saisir le montant du facture    ";
            i>>f.montant;
            if(cin.fail()) throw 1;
            if(f.montant<0)    throw msg4;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg5<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"la facture est payée ? Y/N         ";
            i>>reponse;
            if(reponse != "Y" && reponse != "N")    throw msg6;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
    }

    if(reponse=="Y")
    {
        cout<<"saisir la date :"<<endl;
        i>>f.date_payement;
        f.etat="payee";
    }
    else if(reponse=="N")
    {
        date d(0,0,0);
        f.etat="non_payee";
        f.date_payement =d;
    }


    return i;
}

ostream& operator<<(ostream& o,facture* f)
{
    o<<f->num_facture<<"   ";
    o<<setw(10)<<f->montant<<"   ";
    o<<setw(10)<<f->etat<<"   ";
    o<<setw(10)<<&f->date_payement<<endl;
    return o;
}

istream& operator>>(istream& i,facture* f)
{
    i>>f->num_facture;
    i>>f->montant;
    i>>f->etat;
    i>>&f->date_payement;
    return i;
}


// -------------- class garage -------------------//
garage::~garage()
{
    for(int i=0;i<personnes.size();i++)
        delete personnes[i];
    this->personnes.clear();

    for(int i=0;i<factures.size();i++)
        delete factures[i];
    this->factures.clear();

    for (auto itr = pieces.begin(); itr != pieces.end(); itr++)
        delete *itr;
    this->pieces.clear();

    for(int i=0;i<reparations.size();i++)
        delete reparations[i];
    this->reparations.clear();
}

garage::garage(const garage& g)
{
    int i;
    personne *p;
    for(i=0;i<g.personnes.size();i++)
    {
        if(typeid(*g.personnes[i])==typeid(client))
            p = new client(static_cast<const client&>(*g.personnes[i]));
        if(typeid(*g.personnes[i])==typeid(employee))
            p = new employee(static_cast<const employee&>(*g.personnes[i]));
        personnes.push_back(p);
    }

    facture *f;
    for(i=0;i<g.factures.size();i++)
    {
        f = new facture(*g.factures[i]);
        factures.push_back(f);
    }

    for (auto itr = pieces.begin(); itr != pieces.end(); itr++)
        this->pieces.push_back(*itr);

    reparation *r;
    for(i=0;i<g.reparations.size();i++)
    {
        r = new reparation(*g.reparations[i]);
        reparations.push_back(r);
    }

}

void garage::creer_fichier_personne(fstream & f)
{
    f.open("d:\\fichierPersonne.text", ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit;
}

void garage::creer_fichier_factures(fstream & f)
{
    f.open("d:\\fichierFacture.text", ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit;
}

void garage::creer_fichier_piece(fstream & f)
{
    f.open("d:\\fichierPiece.text", ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit;
}

void garage::creer_fichier_reparations(fstream & f)
{
    f.open("d:\\fichierReparation.text", ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit;
}

void garage::creer_fichier_vc(fstream & f)
{
    f.open("d:\\fichierVC.text", ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit;
}


void garage::enregistrer()
{
    fstream f1,f2,f3,f4,f5;

    creer_fichier_personne(f1);

    for(int i=0; i<personnes.size();i++)
    {
        if(typeid(*personnes[i]) == typeid(client))
            f1<<"2 "<<&static_cast<client&>(*personnes[i])<<endl;
        else if(typeid(*personnes[i]) == typeid(employee))
            f1<<"3 "<<&static_cast<employee&>(*personnes[i])<<endl;
    }
    f1.close();

    creer_fichier_factures(f2);
    for(int i=0; i<factures.size();i++)
    {
        f2<<i<<"   ";
        f2<<&*factures[i]<<endl;
    }
    f2.close();

    creer_fichier_piece(f3);
    for(auto pi :pieces)
        f3<<"1  "<<&*pi<<endl;
    f3.close();

    creer_fichier_reparations(f4);
    for(int i=0; i<reparations.size();i++)
    {
        reparations[i]->enregistrer(i);
        pair<int,string> c(reparations[i]->Get_num(),"d:\\fichierReparation" + to_string(reparations[i]->Get_num()) +".text");
        fichier_reparation.insert(c);
    }
    map<int,string>::iterator it;
    for(it=fichier_reparation.begin() ; it!=fichier_reparation.end() ; ++it)
    {
        f4<<"0  "<<it->first<<"   "<<it->second<<endl;
    }
    f4.close();

    creer_fichier_vc(f5);
    f5<<&voiture_client;
    f5.close();
}

void garage::recuperer()
{
    fstream f1,f2,f3,f4,f5;
    int val;
    int k = 0;

    f1.open("d:\\fichierPersonne.text", ios::in);
    if(!f1.is_open()) exit(-1);
    while(1)
    {
        f1>>val;
        if(f1.eof())
            break;
        if(val == 2)
        {
            client* c =new client;
            f1>>&*c;
            personnes.push_back(c);
        }
        else if(val == 3)
        {
            employee* e =new employee;
            f1>>&*e;
            personnes.push_back(e);
        }
    }
    f1.close();

    f2.open("d:\\fichierFacture.text", ios::in);
    if(!f2.is_open()) exit(-1);
    while(1)
    {
        f2>>val;
        if(f2.fail())
            break;
        facture* f = new facture;
        f2>>&*f;
        factures.push_back(f);
    }
    f2.close();

    f3.open("d:\\fichierPiece.text", ios::in);
    if(!f3.is_open()) exit(-1);
    while(1)
    {
        f3>>val;
        if(f3.fail())
            break;
        piece* p = new piece;
        f3>>&*p;
        pieces.push_back(p);
    }
    f3.close();


    pair<int,string> p;
    f4.open("d:\\fichierReparation.text", ios::in);
    while(1)
    {
        f4>>val;
        if(f4.fail())
            break;
        f4>>p.first;
        f4>>p.second;
        fichier_reparation.insert(p);
    }
    f4.close();

    reparation r;
    map<int,string>::iterator it;
    for(it=fichier_reparation.begin() ; it!=fichier_reparation.end() ; ++it)
    {
            r.recuperer(it->first);
            reparation *x =new reparation(r);
            reparations.push_back(x);
    }

    int v,c;
    f5.open("d:\\fichierVC.text", ios::in);
    while(1)
    {
        f5>>val;
        if(f5.fail())
            break;
        f5>>v;
        f5>>c;
        voiture_client.ajoutermap(v,c);
    }
    f5.close();

}

void garage::ajouter_personne(personne& p)
{
    personne *x;
    if(typeid(p)==typeid(client))
            x=new client(static_cast<const client&>(p));
    else if(typeid(p)==typeid(employee))
            x=new employee(static_cast<const employee&>(p));
        personnes.push_back(x);
}



void garage::supprimer_personne(int num)
{
    for(int i=0;i<personnes.size();i++)
        if(personnes[i]->Get_id()==num)
            personnes.erase(personnes.begin()+i);
}

void garage::supprimer_reparation(int num)
{
    for(int i=0;i<reparations.size();i++)
        if(reparations[i]->Get_num()==num)
            reparations.erase(reparations.begin()+i);
}

void garage::supprimer_facture(int num)
{
    for(int i=0;i<factures.size();i++)
        if(factures[i]->Get_num()==num)
            factures.erase(factures.begin()+i);
}




void garage::afficher_clients(int num)
{
    if(num == 0)
    {
        for(int i=0;i<personnes.size();i++)
        {
            if(typeid(*personnes[i])== typeid(client))
            {
                cout<<"----------- Client ----------------"<<endl;
                cout<<static_cast<client&>(*personnes[i])<<endl;
                cout<<endl;
           }
        }
    }
    else
    {
        for(int i=0;i<personnes.size();i++)
        {
            if(typeid(*personnes[i])== typeid(client) && personnes[i]->Get_id() == num)
            {
                cout<<"----------- Client ----------------"<<endl;
                cout<<static_cast<client&>(*personnes[i])<<endl;
                cout<<endl;
            }
        }
    }
}

void garage::afficher_clients2()
{
    for(int i=0;i<personnes.size();i++)
    {
        if(typeid(*personnes[i])== typeid(client))
            personnes[i]->afficher2();
    }
}

void garage::afficher_employees(int num)
{
    if(num == 0)
    {
        for(int i=0;i<personnes.size();i++)
        {
            if(typeid(*personnes[i])== typeid(employee))
            {
                cout<<"----------- Employee ----------------"<<endl;
 //               personnes[i]->afficher();
                cout<<static_cast<employee&>(*personnes[i])<<endl;
                cout<<endl;
           }
        }
    }
    else
    {
        for(int i=0;i<personnes.size();i++)
        {
            if(typeid(*personnes[i])== typeid(employee) && personnes[i]->Get_id() == num)
            {
                cout<<"----------- Employee ----------------"<<endl;
                cout<<static_cast<employee&>(*personnes[i])<<endl;
                cout<<endl;
            }
        }
    }
}

void garage::afficher_employees2()
{
    for(int i=0;i<personnes.size();i++)
    {
        if(typeid(*personnes[i])== typeid(employee))
            personnes[i]->afficher2();
    }
}

void garage::ajouter_facture(facture &f)
{
    facture *x = new facture(f);
    factures.push_back(x);
}

void garage::afficher_facture(int num)
{
    if(num == 0)
    {
        for(int i=0;i<factures.size();i++)
        {
                cout<<"----------- Facture ----------------"<<endl;
                cout<<*factures[i]<<endl;
                cout<<endl;
        }
    }
    else
    {
        for(int i=0;i<factures.size();i++)
        {
            if(factures[i]->Get_num() == num)
            {
                cout<<"----------- Facture ----------------"<<endl;
                cout<<*factures[i]<<endl;
                cout<<endl;
            }
        }
    }
}

void garage::afficher_factures2()
{
    for(int i=0;i<factures.size();i++)
            factures[i]->afficher2();
}

void garage::afficher_factures2_non_payee()
{
    for(int i=0;i<factures.size();i++)
    {
        if(factures[i]->Get_etat() == "non_payee")
            factures[i]->afficher2();
    }
}


void garage::ajouter_piece(piece &p)
{
    piece *x = new piece(p);
    pieces.push_back(x);
}

void garage::afficher_piece(int num)
{
    if(num == 0)
    {
        for(auto p :pieces)
        {
                cout<<"----------- Piece ----------------"<<endl;
                cout<<*p<<endl;
                cout<<endl;
        }
    }
    else
    {
        for(auto p :pieces)
        {
            if(p->Get_num() == num)
            {
                cout<<"----------- Piece ----------------"<<endl;
                cout<<*p<<endl;
                cout<<endl;
            }
        }
    }
}

void garage::afficher_pieces2()
{
    for(auto p :pieces)
            p->afficher2();
}

void garage::ajouter_reparation(reparation &r)
{
    reparation *x = new reparation(r);
    reparations.push_back(x);
}

void garage::afficher_reparation(int num)
{
    if(num == 0)
    {
        for(int i=0;i<reparations.size();i++)
        {
                cout<<"----------- Reparation ----------------"<<endl;
                cout<<*reparations[i]<<endl;
                cout<<endl;
        }
    }
    else
    {
        for(int i=0;i<reparations.size();i++)
        {
            if(reparations[i]->Get_num() == num)
            {
                cout<<"----------- Reparation ----------------"<<endl;
                cout<<*reparations[i]<<endl;
                cout<<endl;
            }
        }
    }
}

void garage::supprimer_piece(int n)
{
    for (auto it = pieces.begin(); it != pieces.end(); ++it)
    {
        if ((*it)->Get_num() == n)
        {
            pieces.erase(it);
            break;
        }
    }
}


void garage::afficher_reparation2()
{
    for(int i=0;i<reparations.size();i++)
            reparations[i]->afficher2();
}

void garage::afficher_reparation2_active()
{
    for(int i=0;i<reparations.size();i++)
    {
        if(reparations[i]->Get_etat()=="active")
                reparations[i]->afficher2();
    }
}

void garage::afficher_file()
{
    voiture *x ;
    Queue<voiture*> q;
    q.copy(file_attente,q);
    while(!q.empty())
    {
        cout<<" --------- affichage file --------"<<endl;
        q.front()->afficher();
        file_attente.push(q.front());
        q.pop();
    }
}

void garage::afficher_file2()
{
    voiture *x ;
    Queue<voiture*> q;
    q.copy(file_attente,q);
    while(!q.empty())
    {
        q.front()->afficher2();
        file_attente.push(q.front());
        q.pop();
    }
}
void garage::ajouter_voiture()
{
    string reponse;
    VElectrique ve;
    VMecanique vm;
    while(1)
    {
        try
        {
            cout<<"donner le type de voiture E:elecrique / M:mecanique"<<endl;
            cin>>reponse;
            if(reponse != "E" && reponse != "M") throw 1;
            break;
        }
        catch(int i)
        {
            cout<<"ERREUR - reponse non validee, les type sont E:elecrique / M:mecanique"<<endl;
        }
    }
    if(reponse == "E")
    {
        cin>>ve;
        VElectrique *x = new VElectrique(ve);
        file_attente.push(x);
    }
    if(reponse == "M")
    {
        cin>>vm;
        VMecanique *x = new VMecanique(vm);
        file_attente.push(x);
    }
    afficher_clients2();
    int id_client;
    cout<<"donner l'id du client propritaire de cette voiture"<<endl;
    cin>>id_client;
    voiture_client.ajoutermap(file_attente.front()->getvoiture(),id_client);
};

void garage::afficher_voitures()
{
    for(int i=0;i<reparations.size();i++)
    {
        reparations[i]->afficher_v2();
    }
};



//--------- voiture -----------------------
void voiture::afficher()
{
    cout<<"\nid de voiture est  "<<id;
    cout<<"\nsa matricule :"<<immatricule;
    cout<<"\nnombre de place :"<<nb_place;
    cout<<"\nsa puissance "<<puissance;
    cout<<"\nkilometre :"<<kilometrage;
    cout<<"\nmarque:"<<marque;
    cout<<"\ndate_mise_en_service :"<<d;
    cout<<"\ncouleur est "<<couleur;

}
ostream& operator<<(ostream&o,voiture*v)
{
    o<<v->id<<"   ";
    o<<setw(10)<<v->immatricule<<"   ";
    o<<setw(10)<<v->nb_place<<"   ";
    o<<setw(10)<<v->puissance<<"   ";
    o<<setw(10)<<v->kilometrage<<"   ";
    o<<setw(10)<<v->marque<<"   ";
    o<<setw(10)<<&v->d<<"   ";
    o<<setw(10)<<v->couleur<<"   ";
    return o;
}
ostream& operator<<(ostream&o,voiture&v)
{
    cout<<"\nid de voiture est  ";
    o<<v.id;
    cout<<"\nsa matricule :";
    o<<v.immatricule;
    cout<<"\nnombre de place :";
    o<<v.nb_place;
    cout<<"\nsa puissance ";
    o<<v.puissance;
    cout<<"\nkilometre :";
    o<<v.kilometrage;
    cout<<"\nmarque:";
    o<<v.marque;
    cout<<"\ndate_mise_en_service :";
    o<<v.d;
    cout<<"\ncouleur est ";
    o<<v.couleur;
    return o;
}
voiture::voiture(int id,string im,int nb,int p,int k ,string m,date d,string c)
    {
        this->id=id;
        immatricule =im;
        nb_place=nb;
        puissance=p;
        kilometrage=k;
        marque=m;
        this->d=d;
        couleur=c;
    }

voiture::voiture(const voiture&v)
{
        this->id=v.id;
        this->immatricule =v.immatricule;
        this->nb_place=v.nb_place;
        this->puissance=v.puissance;
        this->kilometrage=v.kilometrage;
        this->marque=v.marque;
        this->d=v.d;
        this->couleur=v.couleur;
    }

istream&operator>>(istream&i,voiture&v)
{
    cout<<"\nid de voiture est  ";
    i>>v.id;
    cout<<"\nsa matricule :";
    i>>v.immatricule;
    cout<<"\nnombre de place :";
    i>>v.nb_place;
    cout<<"\nsa puissance ";
    i>>v.puissance;
    cout<<"\nkilometre :";
    i>>v.kilometrage;
    cout<<"\nmarque:";
    i>>v.marque;
    cout<<"\ndate_mise_en_service :";
    i>>v.d;
    cout<<"\ncouleur est ";
    i>>v.couleur;
    return i;
}

istream&operator>>(istream&i,voiture*v)
{
    i>>v->id;
    i>>v->immatricule;
    i>>v->nb_place;
    i>>v->puissance;
    i>>v->kilometrage;
    i>>v->marque;
    i>>&v->d;
    i>>v->couleur;
    return i;
};
// -------------- class VMecanique -------------------//

VMecanique::VMecanique(int id,string im,int nb,int p,int k ,string m,date d,string c,string type_carburant):voiture( id, im, nb, p, k , m, d, c)
{
    this->type_carburant=type_carburant;
}

istream&operator>>(istream&i,VMecanique&v)
{
    string msg;
    string msg1="ERREUR - la voiture existe deja";
    string msg2="ERREUR - l'id doit etre positive";
    string msg3="ERREUR - id non valide";
    string msg4="ERREUR - le nombre de place doit etre positive";
    string msg5="ERREUR - nombre de place non valide";
    string msg6="ERREUR - la puissance doit etre positive";
    string msg7="ERREUR - puissance non valide";
    string msg8="ERREUR - le kilometrage doit etre positive";
    string msg9="ERREUR - kilometrage non valide";

    while(true)
    {
        try
        {
            cout<<"\nid de Voiture Mecanique est  ";
            i>>v.id;
            if(cin.fail()) throw 1;
            else if(v.id<0)    throw msg2;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg3<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout<<"\nsa matricule :";
    i>>v.immatricule;

    while(true)
    {
        try
        {
            cout<<"\nnombre de place :";
            i>>v.nb_place;
            if(cin.fail()) throw 1;
            else if(v.nb_place<0)    throw msg4;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg5<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\nsa puissance ";
            i>>v.puissance;
            if(cin.fail()) throw 1;
            else if(v.puissance<0)    throw msg6;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg7<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\nkilometre :";
            i>>v.kilometrage;
            if(cin.fail()) throw 1;
            else if(v.kilometrage<0)    throw msg8;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg9<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout<<"\nmarque:";
    i>>v.marque;
    cout<<"\ndate_mise_en_service :";
    i>>v.d;
    cout<<"\ncouleur est ";
    i>>v.couleur;
    cout<<"le type de carburant";
    i>>v.type_carburant;
    return i;
}
istream&operator>>(istream&i,VMecanique*v)
{
    i>>v->id;
    i>>v->immatricule;
    i>>v->nb_place;
    i>>v->puissance;
    i>>v->kilometrage;
    i>>v->marque;
    i>>&v->d;
    i>>v->couleur;
    i>>v->type_carburant;
    return i;
};
void VMecanique::afficher()
{
    voiture::afficher();
    cout<<"\ntype de carburant"<<type_carburant<<endl;

}

ostream& operator<<(ostream& o,VMecanique& v)
{
    cout<<"\nid de voiture mecnique est  ";
    o<<v.id;
    cout<<"\nsa matricule :";
    o<<v.immatricule;
    cout<<"\nnombre de place :";
    o<<v.nb_place;
    cout<<"\nsa puissance ";
    o<<v.puissance;
    cout<<"\nkilometre :";
    o<<v.kilometrage;
    cout<<"\nmarque:";
    o<<v.marque;
    cout<<"\ndate_mise_en_service :";
    o<<v.d;
    cout<<"\ncouleur est ";
    o<<v.couleur;
    cout<<"\ntype de carburant";
    o<<v.type_carburant;
    return o;
}
ostream& operator<<(ostream&o,VMecanique*v)
{
    o<<v->id<<"   ";
    o<<setw(10)<<v->immatricule<<"   ";
    o<<setw(10)<<v->nb_place<<"   ";
    o<<setw(10)<<v->puissance<<"   ";
    o<<setw(10)<<v->kilometrage<<"   ";
    o<<setw(10)<<v->marque<<"   ";
    o<<setw(10)<<&v->d<<"   ";
    o<<setw(10)<<v->couleur<<"   ";
    o<<setw(10)<<v->type_carburant<<"   ";
    return o;
}

// -------------- class VElectrique -------------------//


istream&operator>>(istream&i,VElectrique&v)
{
    string msg;
    string msg1="ERREUR - la voiture existe deja";
    string msg2="ERREUR - l'id doit etre positive";
    string msg3="ERREUR - id non valide";
    string msg4="ERREUR - le nombre de place doit etre positive";
    string msg5="ERREUR - nombre de place non valide";
    string msg6="ERREUR - la puissance doit etre positive";
    string msg7="ERREUR - puissance non valide";
    string msg8="ERREUR - le kilometrage doit etre positive";
    string msg9="ERREUR - kilometrage non valide";
    string msg10="ERREUR - le temps de recharge doit etre positive";
    string msg11="ERREUR - temps de recharge non valide";

    while(true)
    {
        try
        {
            cout<<"\nid de Voiture Electrique est  ";
            i>>v.id;
            if(cin.fail()) throw 1;
            else if(v.id<0)    throw msg2;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg3<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout<<"\nsa matricule :";
    i>>v.immatricule;

    while(true)
    {
        try
        {
            cout<<"\nnombre de place :";
            i>>v.nb_place;
            if(cin.fail()) throw 1;
            else if(v.nb_place<0)    throw msg4;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg5<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\nsa puissance ";
            i>>v.puissance;
            if(cin.fail()) throw 1;
            else if(v.puissance<0)    throw msg6;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg7<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\nkilometre :";
            i>>v.kilometrage;
            if(cin.fail()) throw 1;
            else if(v.kilometrage<0)    throw msg8;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg9<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    cout<<"\nmarque:";
    i>>v.marque;
    cout<<"\ndate_mise_en_service :";
    i>>v.d;
    cout<<"\ncouleur est ";
    i>>v.couleur;
    cout<<"\nle type de batterie";
    i>>v.batterie;
    while(true)
    {
        try
        {
            cout<<"\ntemp de charge";
            i>>v.temps_charge;
            if(cin.fail()) throw 1;
            else if(v.temps_charge<0)    throw msg10;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg11<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    return i;
}

istream& operator>>(istream&i,VElectrique*v)
{
    i>>v->id;
    i>>v->immatricule;
    i>>v->nb_place;
    i>>v->puissance;
    i>>v->kilometrage;
    i>>v->marque;
    i>>&v->d;
    i>>v->couleur;
    i>>v->batterie;
    i>>v->temps_charge;
    return i;
};

void VElectrique::afficher()
{
    voiture::afficher();
    cout<<"\nle type de batterie"<<batterie;
    cout<<"\ntemp de charge"<<temps_charge<<endl;

}
ostream& operator<<(ostream&o,VElectrique&v)
{
    cout<<"\nid de voiture electrique est  ";
    o<<v.id;
    cout<<"\nsa matricule :";
    o<<v.immatricule;
    cout<<"\nnombre de place :";
    o<<v.nb_place;
    cout<<"\nsa puissance ";
    o<<v.puissance;
    cout<<"\nkilometre :";
    o<<v.kilometrage;
    cout<<"\nmarque:";
    o<<v.marque;
    cout<<"\ndate_mise_en_service :";
    o<<v.d;
    cout<<"\ncouleur est ";
    o<<v.couleur;
    cout<<"\nla type de batterie";
    o<<v.batterie;
    cout<<"\ntemp de charge";
    o<<v.temps_charge;
    return o;
}
ostream& operator<<(ostream&o,VElectrique*v)
{
    o<<v->id<<"   ";
    o<<setw(10)<<v->immatricule<<"   ";
    o<<setw(10)<<v->nb_place<<"   ";
    o<<setw(10)<<v->puissance<<"   ";
    o<<setw(10)<<v->kilometrage<<"   ";
    o<<setw(10)<<v->marque<<"   ";
    o<<setw(10)<<&v->d<<"   ";
    o<<setw(10)<<v->couleur<<"   ";
    o<<setw(10)<<v->batterie<<"   ";
    o<<setw(10)<<v->temps_charge<<"   ";
    return o;
}

void voiture::ecrire(fstream& f)
{
    f<<id<<"   ";
    f<<setw(10)<<immatricule<<"   ";
    f<<setw(10)<<nb_place<<"   ";
    f<<setw(10)<<puissance<<"   ";
    f<<setw(10)<<kilometrage<<"   ";
    f<<setw(10)<<marque<<"   ";
    f<<setw(10)<<&d<<"   ";
    f<<setw(10)<<couleur<<"   "<<endl;
}

void VElectrique::ecrire(fstream& f)
{
    f<<id<<"   ";
    f<<setw(10)<<immatricule<<"   ";
    f<<setw(10)<<nb_place<<"   ";
    f<<setw(10)<<puissance<<"   ";
    f<<setw(10)<<kilometrage<<"   ";
    f<<setw(10)<<marque<<"   ";
    f<<setw(10)<<&d<<"   ";
    f<<setw(10)<<couleur<<"   "<<endl;
    f<<setw(10)<<batterie<<"   ";
    f<<setw(10)<<temps_charge<<"   "<<endl;
}
VElectrique::VElectrique(int id,string im,int nb,int p,int k ,string m,date d,string c,string batterie,int temps):voiture( id, im, nb, p, k , m, d, c)
{
    this->batterie=batterie;
    temps_charge=temps;
}

// ----------- piece -----------//
piece::piece(int reference_piece,string designation,int quantiter_stock,float prix,int critique,int quantiter)
{
    this->reference_piece=reference_piece;
    this->designation=designation;
    this->quantiter_stock=quantiter_stock;
    this->prix=prix;
    this->critique=critique;
    this->quantiter=quantiter;
}


void piece::afficher()
{
    cout<<"\nreference de piece : "<<reference_piece;
    cout<<"\nsa designation  "<<designation;
    cout<<"\nquantiter en stock  "<<quantiter_stock;
    cout<<"\nsa prix  "<<prix;
    cout<<"\nsa critique stock  "<<critique;
    cout<<"\nquantiter "<<quantiter;

}
istream& operator>>(istream&i,piece*p)
{
    i>>p->reference_piece;
    i>>p->designation;
    i>>p->quantiter_stock;
    i>>p->prix;
    i>>p->critique;
    i>>p->quantiter;
    return i;
}

istream& operator>>(istream&i,piece&p)
{
    string msg;
    string msg1="ERREUR - la piece existe deja";
    string msg2="ERREUR - la reference doit etre positive";
    string msg3="ERREUR - reference non valide";
    string msg4="ERREUR - la quantite en stock doit etre positive";
    string msg5="ERREUR - quantite en stock non valide";
    string msg6="ERREUR - le prix doit etre positive";
    string msg7="ERREUR - prix non valide";
    string msg8="ERREUR - le seuil critique doit etre positive";
    string msg9="ERREUR - seuil critique non valide";


    while(true)
    {
        try
        {
            cout<<"\nreference de piece est :";
            i>>p.reference_piece;
            if(cin.fail()) throw 1;
            else if(p.reference_piece<0)    throw msg2;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg3<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    cout<<"\ndesignation :";i>>p.designation;
    while(true)
    {
        try
        {
            cout<<"\nquatiter dans les stock :";i>>p.quantiter_stock;
            if(cin.fail()) throw 1;
            else if(p.quantiter_stock<0)    throw msg4;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg5<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\nprix de la piece ";i>>p.prix;
            if(cin.fail()) throw 1;
            else if(p.prix<0)    throw msg6;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg7<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    while(true)
    {
        try
        {
            cout<<"\ncritique de stock  ";i>>p.critique;
            if(cin.fail()) throw 1;
            else if(p.critique<0)    throw msg8;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg9<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    p.quantiter = 0;
    return i;
}
ostream& operator<<(ostream&o,piece*p)
{
    o<<setw(5)<<p->reference_piece<<"   ";
    o<<setw(5)<<p->designation<<"   ";
    o<<setw(5)<<p->quantiter_stock<<"   ";
    o<<setw(5)<<p->prix<<"   ";
    o<<setw(5)<<p->critique<<"   ";
    o<<setw(5)<<p->quantiter<<endl;
    return o;
}
ostream& operator<<(ostream&o,piece&p)
{
    o<<"\nreference de piece est :"<<p.reference_piece;
    o<<"\ndesignation :"<<p.designation;
    o<<"\nquatiter dans les stock :"<<p.quantiter_stock;
    o<<"\nprix de la piece "<<p.prix;
    o<<"\ncritique de stock"<<p.critique;
    o<<"\nquantiter qui sera utiliser "<<p.quantiter;
    return o;
}

// ---------------- reparation ----------------//
void reparation::ajouter_piece(piece& p)
{
    piece *q=new piece(p);
    auto foundIterator = find(piec.begin(), piec.end(),q);
    if (foundIterator != piec.end()) {
        cout << "piece existe deja dans la liste! "<< endl;
    } else {
        this->piec.push_back(q);
        cout << "piece ajoutee a la liste "<< endl;
    }


}
void reparation::ajouter_employer(employee&e)
{
    employee *em=new employee(e);

    auto foundIterator = find(employer.begin(), employer.end(), em);
    if (foundIterator != employer.end()) {
        cout << "employer existe deja dans la liste!"<< endl;
    } else {
        this->employer.push_back(em);
        cout << "employer ajoutee a la liste"<< endl;
    }

}

void reparation::Set_vehicule(voiture &ve)
{
    if(typeid(ve)==typeid(VElectrique))
        v=new VElectrique(static_cast<const VElectrique&>(ve));
    else if(typeid(ve)==typeid(VMecanique))
            v=new VMecanique(static_cast<const VMecanique&>(ve));
}

reparation::reparation(int num, date d, string etat)
 {
    this->num_reparation = num;
    this->d = d;
    this->etat = etat;
    this->num_facture = 0;
}
reparation::~reparation()
{
    for (auto itr = employer.begin(); itr != employer.end(); itr++)
        delete *itr;
    employer.clear();

    for (int i = 0; i < piec.size(); i++) {
        delete piec[i];
    }
    piec.clear();
    delete v;
}
float reparation::calcul_montant() {
    float total = 0;
    for (int i = 0; i < piec.size(); i++) {
        total += (float)piec[i]->get_quantiter()*piec[i]->get_prix();
    }

    for (auto const& emp : employer)
        total += emp->Get_salaire();
    return total;
}

void reparation::afficher()
{
    cout << "Numéro de réparation:     " << num_reparation << endl;
    cout << "Date de réparation:       " << d << endl;
    cout << "Etat:                     " << etat << endl;
    if(num_facture==0)
        cout<<"aucune facture"<<endl;
    else
        cout<<"num facture :           "<<num_facture<<endl;
    cout << "La voiture est :       " << endl;
    v->afficher();


    sort(employer.begin(),employer.end(),[](employee* c, employee* b) { return *c < *b; });
    cout << "Liste des employes: ";
    int i = 1;
        for (employee* p : employer) {
        cout << "employe  "<<i<<": " << endl<< *p << endl;i++;
    }
    sort(piec.begin(), piec.end(), [](piece* c, piece* b){return *c < *b;});
    cout << "Liste des piece: ";
    int z = 1;
        for (piece* p : piec) {
            cout << "Piece  "<<z<<": " << endl<< *p << endl;z++;
    }

    cout << "\nMontant total: " << calcul_montant() << endl;
}

istream& operator>>(istream& i, reparation* r)
{
    i >> r->num_reparation;
    i >>&r->d;
    r->etat = "active";
    i>>r->num_facture;
    i >>r->v;
    return i;
}

istream& operator>>(istream&i,reparation &r)
{
    int reponse;
    VElectrique ve;
    VMecanique vm;
    voiture *x;

    cout<<"donner le numero du reparation est : ";
    i>>r.num_reparation;
    cout<<"donner la date de reparation :     ";
    i>>r.d;
    r.etat = "active";
    r.num_facture = 0;
    cout<<"saisir type de voiture , 1/voiture electrique, 2/voiture mecanique : ";
    i>>reponse;
    if(reponse == 1)
    {
        i>>ve;
        x=new VElectrique(ve);
    }
    else if(reponse == 2)
    {
        i>>vm;
        x=new VMecanique(vm);
    }
    r.v = x;
    return i;
}

reparation::reparation(const reparation& r)
{
    int i;
    num_reparation = r.num_reparation;
    d = r.d;
    etat = r.etat;
    num_facture = r.num_facture;

    if (dynamic_cast<VMecanique*>(r.v) != nullptr)
    {
        v = new VMecanique(*(static_cast<VMecanique*>(r.v)));
    }
    else if (dynamic_cast<VElectrique*>(r.v) != nullptr)
    {
        v = new VElectrique(*(static_cast<VElectrique*>(r.v)));
    }

    for (auto itr = r.employer.begin(); itr != r.employer.end(); itr++)
        this->employer.push_back(*itr);

    piece *p;
    for(i=0;i<r.piec.size();i++)
    {
        p = new piece(*r.piec[i]);
        piec.push_back(p);
    }

    this->num_reparation = r.num_reparation;
    this->d = r.d;
    this->etat = r.etat;
}

ostream& operator<<(ostream&o,reparation &r)
{
    cout<<"\n*****************affichage de reparation*************\n";
    o<<"\nle numero du reparation est :"<<r.num_reparation;
    o<<"\nla date de reparation :      "<<r.d<<endl;

    if(r.num_facture==0)
        o<<"aucune facture"<<endl;
    else
        o<<"num facture :           "<<r.num_facture<<endl;

    o<<"la voiture est :  "<<endl;


    if(typeid(*r.v) == typeid(voiture))
        o<<*r.v;
    else if(typeid(*r.v) == typeid(VElectrique))
        o<<static_cast<VElectrique&>(*r.v); // ------------------------------ this actually work HHHHHHH ----------
    else if(typeid(*r.v) == typeid(VMecanique))
        o<<static_cast<VMecanique&>(*r.v);

    sort(r.employer.begin(),r.employer.end(),[](employee* c, employee* b) { return *c < *b; });
    o<<"\nles employees participant a la reparation : "<<endl;
    int i = 1;
        for (employee* p : r.employer)
            o << "employe  "<<i<<": \n\n" << *p << endl;i++;

    sort(r.piec.begin(), r.piec.end(), [](piece* c, piece* b){return *c < *b;});
    o<<"les pieces utulise dans la reparation est :";
    int z = 1;
        for (piece* p : r.piec) {
        o << "Piece  "<<z<<": " << endl<< *p << endl;z++;
    }

    if(r.etat == "active")
        o<<"la reparation est active"<<endl;
    else if(r.etat == "fini")
        o<<"la reparation est termine"<<endl;
    cout<<"\nla montant de reparation  "<<r.calcul_montant();

    return o;
}

void reparation::afficher_employees()
{
    for(auto em :employer)
        cout<<*em<<endl;
}

void reparation::afficher_pieces()
{
    for(int i=0;i<piec.size();i++)
        cout<<*piec[i]<<endl;
}

void reparation::afficher_voiture()
{
    cout<<*v;
}

void reparation::afficher_v2()
{
    v->afficher2();
}


void reparation::enregistrer(int i)
{
    fstream f;
    string ch;
    creer_fichier_reparation(f);
    f<<i<<"   ";
    f<<num_reparation<<"   ";
    f<<setw(10)<<&d<<"   ";
    f<<setw(10)<<etat<<"   "<<endl;
    f<<setw(10)<<num_facture<<"   "<<endl;

    if(typeid(*v) == typeid(voiture))
            f<<"1 "<<&*v<<endl;
    else if(typeid(*v) == typeid(VElectrique))
            f<<"2 "<<&static_cast<VElectrique&>(*v)<<endl;
    else if(typeid(*v) == typeid(VMecanique))
            f<<"3 "<<&static_cast<VMecanique&>(*v)<<endl;

    for(auto em :employer)
        f<<"1  "<<&*em<<endl;
    for(int i=0;i<piec.size();i++)
        f<<"2  "<<&*piec[i]<<endl;
    f.close();

};
void reparation::recuperer(int num)
{
    int val;
    fstream f;
    string ch;
    ch = "d:\\fichierReparation" + to_string(num) +".text";
    f.open(ch, ios::in);
    if(!f.is_open()) exit(-1);
    f>>val;
    f>>num_reparation;
    f>>&d;
    f>>etat;
    f>>num_facture;

    f>>val;
    if(val == 2)
    {
        VElectrique* ve =new VElectrique;
        f>>&*ve;
        v = ve;
    }
    else if(val == 3)
    {

        VMecanique* vm =new VMecanique;
        f>>&*vm;
        v = vm;
    }

    while(1)
    {
        f>>val;
        if(f.fail())
            break;
        if(val == 1)
        {
            employee* e =new employee;
            f>>&*e;
            employer.push_back(e);
        }
        else if(val == 2)
        {
            piece* p =new piece;
            f>>&*p;
            piec.push_back(p);
        }
    }
    f.close();
}

void reparation::modifier_reparation()
{
    int x;
    do{
    cout<<"\n\n\n\nsi tu peut modifier voiture donner tapez 1\nmodifier piece tapez 2 \nmodifier employer tapez 3 :";
    int y,w,a1,i;
    cin>>y;
    if (y==1)
    {
        cout<<"\nquele type de voiture qui sera choisit 1 electrique 2   mecanque   ";
        int a2;
        cin>>a2;

        if(a2==1)
            {VElectrique ve;
            cin>>ve;
            ve.Set_num(v->getvoiture());
            v=new VElectrique(ve);
            }
        if(a2==2)
            {
            VMecanique ve;
            cin>>ve;
            ve.Set_num(v->getvoiture());
            v=new VMecanique(ve);
            }
        }
    if(y==2)
    {
        cout<<"\n saisir une piece      ";
        piece p2;
        cin>>p2;
        piece* p1= new piece(p2);
        replace_if(piec.begin(), piec.end(), [p1](piece* p){ return *p == *p1; }, p1);
        for (piece* p : piec)
            cout << "Piece: " << *p << endl;
    }
    else if(y==3)
        {
        cout<<"\n  saisir un employee";
        employee p2;
        cin>>p2;
        employee* p1= new employee(p2);
        replace_if(employer.begin(), employer.end(), [p1](employee* p){ return *p == *p1; }, p1);
        for (employee* p : employer)
                cout << "employee: " << *p << endl;
        }
    cout<<"\nsi tu peut ajouter autre modification  tapez 1 si non 0   ";
    cin>>x;

    }while (x);

}

void reparation::modifier_reparation_fichier(int aa)
{
     reparation r;
     fstream f;
     string ch;
     ch = "fichierReparation" + to_string(aa) +".text";
     f.open(ch,ios::in);
     r.recuperer(aa);
     f.close();
     f.open(ch,ios::in|ios::trunc) ;
     r.modifier_reparation();
     r.enregistrer(aa);
     f.close();
}

void reparation::creer_fichier_reparation(fstream & f)
 {
     string ch;
     ch = "d:\\fichierReparation" + to_string(num_reparation) +".text";
     f.open(ch, ios::in | ios::out | ios::trunc);
     if(! f.is_open()) exit;
};

//--------------- class cv --------------------//
vc::vc(const vc& other)
{
    for (auto it = other.a.begin(); it != other.a.end(); ++it)
        a[it->first] = it->second;

    it = a.begin();
}

void vc::ajoutermap(int v,int c)
{
    a.insert(make_pair(v,c));
}


void vc::affichermap()
{
    for (it=a.begin();it!=a.end();it++)
        cout<<"id voiture :"<<it->first<<"     "<<"id client :"<<it->second<<endl;
};

void vc::modifiermap(int c,int v)
{
    it = a.find(v);

    if (it != a.end()) {
        a[c] = it->second;
        a.erase(it);
    }
}

void vc::recherchermap(int b)
{
    it=a.find(b);
    if (it!=a.end()) cout<<"cette voiture existe  ";
    else cout<<"cette voiture n'existe pas  ";
};

void vc::suprimmap(int b)
{
    it=a.find(b);
    if (it!=a.end()) a.erase(b);
};
//---------------menu -----------------//

void afficher_menu_principale(garage& g)
{
    int choix;
    cout<<" -------------- Menu ---------------"<<endl;
    cout<<"taper 1 pour gerer les client "<<endl;
    cout<<"taper 2 pour gerer les employee "<<endl;
    cout<<"taper 3 pour gerer les piece "<<endl;
    cout<<"taper 4 pour faire une reparation "<<endl;
    cout<<"taper 5 pour gerer la liste d'attentes de voitures"<<endl;
    cout<<"taper 6 pour gerer les factures "<<endl;


    cin>>choix;
    switch (choix)
    {
        case 1: menu_client(g);
        case 2: menu_employee(g);
        case 3: menu_piece(g);
        case 4: menu_reparation(g);
        case 5: menu_voiture(g);
        case 6: menu_facture(g);
    }

}


void ajouter_client(garage &g)
{
    client c;
    int r = 1;
    bool indicator = false;
    while (r != 0)
    {
        cout<<"------ saisir un client ------"<<endl;
        cin>>c;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==c.Get_id())
            {
                cout<<"!!!!!!! le client existe deja !!!!!!!"<<endl;
                indicator = true;
            }
        }
        if(indicator == false)
        {
            g.ajouter_personne(c);
            g.enregistrer();
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void supprimer_client(garage &g)
{
    int r = 1;
    int id;
    g.afficher_clients2();
    while (r != 0)
    {
        bool indicator = false;

        cout<<"----------------+++----------------"<<endl;
        cout<<"------ saisir l'id de client a supprimer ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(client))
            {
                g.supprimer_personne(id);
                cout<<"supprimée"<<endl;
                g.enregistrer();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! le client n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void modifier_client(garage &g)
{
    int r = 1;
    int id;
    client c;
    bool indicator = false;
    g.afficher_clients2();
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir l'id de client a modifier ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(client))
            {
                g.supprimer_personne(id);
                cin>>c;
                c.Set_id(id);
                g.ajouter_personne(c);
                g.enregistrer();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! le client n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void recherche_client(garage &g)
{
    int r = 1;
    int id;
    bool indicator = false;
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir l'id de client a afficher ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(client))
            {
                g.personnes[i]->afficher();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! le client n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void menu_client(garage& g)
{
    int choix;
    cout<<" -------------- Menu CLIENT---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des client "<<endl;
    cout<<"taper 2 pour afficher la liste complete des client "<<endl;
    cout<<"taper 3 pour ajouter un client "<<endl;
    cout<<"taper 4 pour supprimer un client "<<endl;
    cout<<"taper 5 pour modifier un client "<<endl;
    cout<<"taper 6 pour rechercher un client "<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_clients2() ;break;
            case 2: g.afficher_clients(0);break;
            case 3: ajouter_client(g);break;
            case 4: supprimer_client(g);break;
            case 5: modifier_client(g);break;
            case 6: recherche_client(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}
//------------------- menu employee -----------------------------//
void ajouter_employee(garage &g)
{
    employee e;
    int r = 1;
    bool indicator = false;
    while (r != 0)
    {
        cout<<"------ saisir un employee ------"<<endl;
        cin>>e;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==e.Get_id() && typeid(*g.personnes[i])== typeid(employee))
            {
                cout<<"!!!!!!! le employee existe deja !!!!!!!"<<endl;
                indicator = true;
            }
        }
        if(indicator == false)
        {
            g.ajouter_personne(e);
            g.enregistrer();
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void supprimer_employee(garage &g)
{
    int r = 1;
    int id;
    g.afficher_employees2();
    while (r != 0)
    {
        bool indicator = false;

        cout<<"----------------+++----------------"<<endl;
        cout<<"------ saisir l'id de employee a supprimer ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(employee))
            {
                g.supprimer_personne(id);
                cout<<"supprimée"<<endl;
                g.enregistrer();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! le employee n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void modifier_employee(garage &g)
{
    int r = 1;
    int id;
    employee e;
    bool indicator = false;
    g.afficher_employees2();
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir l'id de employee a modifier ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(employee))
            {
                g.supprimer_personne(id);
                cin>>e;
                e.Set_id(id);
                g.ajouter_personne(e);
                g.enregistrer();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! l'employee n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void recherche_employee(garage &g)
{
    int r = 1;
    int id;
    bool indicator = false;
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir l'id de employee a afficher ------"<<endl;
        cin>>id;
        for(int i=0;i<g.personnes.size();i++)
        {
            if(g.personnes[i]->Get_id()==id && typeid(*g.personnes[i])== typeid(employee))
            {
                g.personnes[i]->afficher();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! l'employee n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void menu_employee(garage& g)
{
    int choix;
    cout<<" -------------- Menu EMPLOYEE---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des employees "<<endl;
    cout<<"taper 2 pour afficher la liste complete des employees "<<endl;
    cout<<"taper 3 pour ajouter un employee "<<endl;
    cout<<"taper 4 pour supprimer un employee "<<endl;
    cout<<"taper 5 pour modifier un employee "<<endl;
    cout<<"taper 6 pour rechercher un employee "<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_employees2() ;break;
            case 2: g.afficher_employees(0);break;
            case 3: ajouter_employee(g);break;
            case 4: supprimer_employee(g);break;
            case 5: modifier_employee(g);break;
            case 6: recherche_employee(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}


//------------------- menu piece -----------------------------//
void ajouter_piece(garage &g)
{
    piece p;
    int r = 1;
    bool indicator = false;
    while (r != 0)
    {
        cout<<"------ saisir une piece ------"<<endl;
        cin>>p;
        for(auto pi :g.pieces)
        {
            if(pi->Get_num()==p.Get_num())
            {
                cout<<"!!!!!!! la piece existe deja !!!!!!!"<<endl;
                indicator = true;
            }
        }
        if(indicator == false)
        {
            g.ajouter_piece(p);
            g.enregistrer();
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void supprimer_piece(garage &g)
{
    int r = 1;
    int i;
    int id;
    g.afficher_pieces2();
    while (r != 0)
    {
        bool indicator = false;

        cout<<"----------------+++----------------"<<endl;
        cout<<"------ saisir la reference du piece a supprimer ------"<<endl;
        cin>>id;
        for(auto pi :g.pieces)
        {
            if(pi->Get_num()==id)
            {
                g.supprimer_piece(id);
                cout<<"supprimée"<<endl;
                g.enregistrer();
                indicator = true;
                break;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la piece n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void modifier_piece(garage &g)
{
    int r = 1;
    int id;
    piece p;
    bool indicator = false;
    g.afficher_pieces2();
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir la reference du piece a modifier ------"<<endl;
        cin>>id;
        for(auto pi :g.pieces)
        {
            if(pi->Get_num()==id)
            {
                g.supprimer_piece(id);
                cin>>p;
                p.Set_reference(id);
                g.ajouter_piece(p);
                g.enregistrer();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la piece n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void recherche_piece(garage &g)
{
    int r = 1;
    int id;
    bool indicator = false;
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir la reference du piece a afficher ------"<<endl;
        cin>>id;
        for(auto pi :g.pieces)
        {
            if(pi->Get_num()==id)
            {
                pi->afficher();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la piece n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void ajouter_stock_piece(garage& g)
{
    int r = 1;
    int id,q,v;
    string msg;
    string msg2="ERREUR - la reference doit etre positive";
    string msg3="ERREUR - reference non valide";
    string msg4="ERREUR - la quantite en stock doit etre positive";
    string msg5="ERREUR - quantite en stock non valide";
    bool indicator = false;
    g.afficher_pieces2();
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        while(true)
                {
                    try
                    {
                        cout<<"------ saisir la reference du piece ------"<<endl;
                        cin>>id;
                        if(cin.fail()) throw 1;
                        else if(q<0)    throw msg2;
                        break;
                    }
                    catch(string msg)
                    {
                        cout<<msg<<endl;
                    }
                    catch(int i)
                    {
                        cout <<msg3<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                }

        for(auto pi :g.pieces)
        {
            if(pi->Get_num()==id)
            {
                while(true)
                {
                    try
                    {
                        cout<<"saisir la quantité a ajouter  : ";
                        cin>>q;
                        if(cin.fail()) throw 1;
                        else if(q<0)    throw msg4;
                        break;
                    }
                    catch(string msg)
                    {
                        cout<<msg<<endl;
                    }
                    catch(int i)
                    {
                        cout <<msg5<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                }
                v = pi->get_stock();
                pi->set_quantiter_stock(q + v);
                cout<<"la nouvelle quantite en stock est:  "<<pi->get_stock()<<endl;
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la piece n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void menu_piece(garage& g)
{
    int choix;
    cout<<" -------------- Menu PIECE---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des pieces "<<endl;
    cout<<"taper 2 pour afficher la liste complete des pieces "<<endl;
    cout<<"taper 3 pour ajouter une piece "<<endl;
    cout<<"taper 4 pour supprimer une  piece"<<endl;
    cout<<"taper 5 pour modifier une piece"<<endl;
    cout<<"taper 6 pour mise a jour la quantité en stock une piece"<<endl;
    cout<<"taper 7 pour rechercher une piece"<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_pieces2() ;break;
            case 2: g.afficher_piece(0);break;
            case 3: ajouter_piece(g);break;
            case 4: supprimer_piece(g);break;
            case 5: modifier_piece(g);break;
            case 6: ajouter_stock_piece(g);break;
            case 7: recherche_piece(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}

//------------------- menu voiture -----------------------------//
void modifier_voiture(garage& g)
{
    int num;
    string msg;
    string msg2="ERREUR - le numero du voiture doit etre positive";
    string msg3="ERREUR - numero non valide";
    string msg4="ERREUR - la reponse doit etre E ou M";
    g.afficher_voitures();
    cout<<"-------+++--------"<<endl;
    while(true)
    {
        try
        {
            cout<<"donner le numero du voiture a changer"<<endl;
            cin>>num;
            if(cin.fail()) throw 1;
            else if(num<0)    throw msg2;
            break;
        }
        catch(string msg)
        {
            cout<<msg<<endl;
        }
        catch(int i)
        {
            cout <<msg3<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }

    for(int i =0;i<g.reparations.size();i++)
    {
        if(g.reparations[i]->getvoiture()==num)
        {
            string a2;
            while(true)
            {
                try
                {
                    cout<<"\nquele type de voiture qui sera choisit E electrique// M mecanque   ";
                    cin>>a2;
                    if(a2!="E" && a2!="M")    throw msg4;
                    break;
                }
                catch(string msg)
                {
                    cout<<msg<<endl;
                }
            }

            if(a2=="E")
            {
                VElectrique ve;
                cin>>ve;
                ve.Set_num(num);
                g.reparations[i]->Set_vehicule(ve);
            }
            if(a2=="M")
            {
                VMecanique vm;
                cin>>vm;
                vm.Set_num(num);
                g.reparations[i]->Set_vehicule(vm);
            }
        }
    }
    g.enregistrer();
}

void recherche_proprietaire(garage& g)
{
    int num,id_client;
    bool indicator = false;
    g.afficher_voitures();
    cout<<"-------+++--------"<<endl;
    cout<<"donner le numero du voiture"<<endl;
    cin>>num;
    id_client = g.voiture_client.val(num);
    for(int i=0;i<g.personnes.size();i++)
    {
        if(g.personnes[i]->Get_id()==id_client && typeid(*g.personnes[i])== typeid(client))
        {
            g.personnes[i]->afficher();
            indicator = true;
        }
    }
    if(indicator == false)
    {
        cout<<"!!! le client n'existe pas !!!"<<endl;
        cout<<endl;
    }


}

void menu_voiture(garage& g)
{
    int choix;
    cout<<" -------------- Menu Voiture---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des voitures en attentes"<<endl;
    cout<<"taper 2 pour afficher la liste complete des voitures en attentes "<<endl;
    cout<<"taper 3 pour ajouter une voiture a la file d'attentes "<<endl;
    cout<<"taper 4 pour rechercher toutes les voitures"<<endl;
    cout<<"taper 5 pour modifier une voiture"<<endl;
    cout<<"taper 6 pour rechercher propritaire"<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_file2() ;break;
            case 2: g.afficher_file();break;
            case 3: g.ajouter_voiture();break;
            case 4: g.afficher_voitures();break;
            case 5: modifier_voiture(g);break;
            case 6: recherche_proprietaire(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}

//-------------- menu reparation ---------------//
void demarrer_reparation(garage& g)
{
    reparation r;
    int num,k=1,m=1;
    string reponse;
    string msg;
    string msg1="ERREUR - le numero de reparation doit etre positive)";
    string msg2="ERREUR - le numero de reparation existe deja)";
    string msg3="ERREUR - numero de reparation non valide)";
    string msg4="ERREUR - la quntité doit etre positive)";
    string msg5="ERREUR - la quantite en stock n'est pas suffissante";
    string msg6="ERREUR - saisir un entier";
    while (m != 0)
    {
        g.file_attente.front()->afficher2();
        cout<<"---------- +++ ----------"<<endl;
        cout<<"demarrer la reparation avec cette voiture? Y/N   :";
        while(1)
        {
            try
            {
                cin>>reponse;
                if(reponse!= "Y" && reponse != "N") throw 1;
                break;
            }
            catch (int i)
            {
                cout<<"ERREUR - reponse non valise (Y/N)"<<endl;
            }
        }
        if(reponse == "Y")
        {
            r.Set_vehicule(*g.file_attente.front());
            g.file_attente.pop();
        }
        if(reponse == "N")
        {
            g.file_attente.pop();
            demarrer_reparation(g);
        }
        while(1)
        {
            try
            {
                cout<<"donner le numero du reparation est : ";
                cin>>num;
                r.Set_num(num);
                if(cin.fail()) throw 1;
                else if(num < 0) throw msg1;
                else
                {
                    for(int i=0;i<g.reparations.size();i++)
                    {
                        if(r.Get_num() == g.reparations[i]->Get_num()) throw msg2;
                    }
                }
                break;
            }
            catch(string msg)
            {
                cout<<msg<<endl;
            }
            catch(int i)
            {
                cout<<msg3<<endl;
            }
        }

        cout<<"donner la date de reparation :     ";
        date d;
        cin>>d;
        r.Set_date(d);
        r.set_etat("active");
        r.Set_num_facture(0);

        bool existe1=false,existe2=false;
        pile<employee> pile1,pile2;
        pile<piece> pile3,pile4;
        g.afficher_employees2();
        cout<<"---------- +++ ----------"<<endl;
        while(k!=0)
        {
            cout<<"choisir l'employee : ";
            cin>>num;

            pile2 = pile1;
            while(!pile2.estVide())
            {
                employee e1;
                e1 = pile2.depiler();
                if(e1.Get_id()==num)
                {
                    existe2 = true;
                }
            }
            for(int i=0; i<g.personnes.size();i++)
            {
                if(g.personnes[i]->Get_id()==num && typeid(*g.personnes[i])== typeid(employee))
                {
                    existe1 = true;
                    if(existe2 == false)
                    {
                        pile1.empiler(static_cast<const employee&>(*g.personnes[i]));
                    }
                }
            }
            cout<<"pour terminer le saisie des employee taper 0 "<<endl;
            cout<<"pour annuler l'employee precedent taper 1 "<<endl;
            cin>>k;
            if(k==1)
            {
                employee e2 = pile1.depiler();
                cout<<"l'employee suivant a ete annulé :"<<endl;
                e2.afficher2();
            }
        }
        while(!pile1.estVide())
        {
            employee e3 = pile1.depiler();
            r.ajouter_employer(e3);
        }

        k=1;
        g.afficher_pieces2();
        cout<<"---------- +++ ----------"<<endl;
        while(k!=0)
        {
            cout<<"choisir les pieces : ";
            cin>>num;

            pile4 = pile3;
            while(!pile4.estVide())
            {
                piece p1;
                p1 = pile4.depiler();
                if(p1.Get_num()==num)
                {
                    existe2 = true;
                }
            }
            for(auto pi :g.pieces)
            {
                if(pi->Get_num()==num)
                {
                    existe1 = true;
                    if(existe2 == false)
                    {
                        piece p1 = *pi;
                        int q;
                        //------------------------- saisie de quantité -----------
                        while(1)
                        {
                            try
                            {
                                cout<<"saisir la quantité qui sera utilisé  : ";
                                cin>>q;
                                if(cin.fail()) throw 1;
                                else if(q<=0) throw msg4;
                                else if(q>p1.get_stock()) throw msg5;
                                break;
                            }
                            catch(string msg)
                            {
                                cout<<msg<<endl;
                            }
                            catch(int i)
                            {
                                cout<<"ERREUR - quantite non valide"<<endl;
                            }
                        }
                        //-------------------------- update contité en stock -------------
                        p1.set_quantiter(q);
                        pi->set_quantiter_stock(pi->get_stock() - q);
                        //-------------------- gestion d'alarm ----------------
                        if(pi->get_stock()<=pi->Get_critique())
                            cout<<"ALARM - la quantité en stock de la piece va bientot expire"<<endl;
                        pile3.empiler(p1);
                    }
                }
            }
            cout<<"pour terminer le saisie des pieces taper 0 "<<endl;
            cout<<"pour annuler la piece precedent taper 1 "<<endl;
            cin>>k;
            if(k==1)
            {
                piece p2 = pile3.depiler();
                cout<<"la piece suivant a ete annule :"<<endl;
                p2.afficher2();
            }
        }
        while(!pile3.estVide())
        {
            piece p3 = pile3.depiler();
            r.ajouter_piece(p3);
        }
        g.ajouter_reparation(r);
        while(1)
        {
            try
            {
                cout<<"taper 0 pour terminer "<<endl;
                cin>>m;
                if(cin.fail()) throw 1;
                break;
            }
            catch(int i)
            {
                cout<<msg6<<endl;
            }
        }
        if(m == 0) break;
    }
}

void terminer_reparation(garage& g)
{
    int id,m=1;
    bool indicator = false;
    while (m != 0)
    {
        g.afficher_reparation2_active();
        cout<<"------------- +++ --------------"<<endl;
        cout<<"choisir le numero du reparation a terminer "<<endl;
        cin>>id;
        for(int i=0;i<g.reparations.size();i++)
            {
                if(g.reparations[i]->Get_num()==id && g.reparations[i]->Get_etat()=="active")
                {
                    facture f;
                    cin>>f;
                    f.Set_etat("non_payee");
                    f.Set_montant(g.reparations[i]->calcul_montant());
                    g.reparations[i]->set_etat("terminé");
                    g.reparations[i]->Set_num_facture(f.Get_num());
                    g.ajouter_facture(f);
                    //g.enregistrer();
                    indicator = true;
                }
            }
        if(indicator == false)
        {
            cout<<"!!! le numero de reparation ne correspond a aucun reparation active !!!"<<endl;
            cout<<endl;
        }
        while(1)
        {
            try
            {
                cout<<"taper 0 pour terminer "<<endl;
                cin>>m;
                if(cin.fail()) throw 1;
                break;
            }
            catch(int i)
            {
                cout<<"ERREUR"<<endl;
            }
        }
        if(m == 0) break;
    }
}

void modifier_reparation(garage& g)
{
    int id;
    bool indicator = false;
    g.afficher_reparation2();
    cout<<"-------------- +++ --------------"<<endl;
    cout<<"saisir le numero de reparation a modifier";
    cin>>id;
    for(int i=0;i<g.reparations.size();i++)
    {
        if(g.reparations[i]->Get_num()==id && g.reparations[i]->Get_etat()=="active")
        {
            cout<<"l'etat actuel de la repartion est :"<<endl;
            cout<<*g.reparations[i];
            g.reparations[i]->modifier_reparation();
            g.enregistrer();
            indicator = true;
        }
        else if(g.reparations[i]->Get_num()==id && g.reparations[i]->Get_etat()=="terminé")
            cout<<"la reparation est terminé - modification impossible"<<endl;
    }
    if(indicator == false)
    {
        cout<<"!!! la reparation n'existe pas !!!"<<endl;
        cout<<endl;
    }
}

void supprimer_reparation(garage& g)
{
    int id;
    bool indicator = false;
    g.afficher_reparation2_active();
    cout<<"-------------- +++ --------------"<<endl;
    cout<<"saisir le numero de reparation a supprimer";
    cin>>id;
    for(int i=0;i<g.reparations.size();i++)
    {
        if(g.reparations[i]->Get_num()==id && g.reparations[i]->Get_etat()=="active")
        {
            cout<<"||| supression de reparation |||"<<endl;
            g.supprimer_reparation(id);
            g.enregistrer();
            indicator = true;
        }
        else if(g.reparations[i]->Get_num()==id && g.reparations[i]->Get_etat()=="terminé")
            cout<<"la reparation est terminé - suppression impossible"<<endl;
    }
    if(indicator == false)
    {
        cout<<"!!! la reparation n'existe pas !!!"<<endl;
        cout<<endl;
    }
}

void recherche_reparation(garage& g)
{
    int r = 1;
    int id;
    bool indicator = false;
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir le numero de reparation a afficher ------"<<endl;
        cin>>id;
        for(int i=0;i<g.reparations.size();i++)
        {
            if(g.reparations[i]->Get_num()==id)
            {
                g.reparations[i]->afficher();
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la reparation n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void menu_reparation(garage& g)
{
    int choix;
    cout<<" -------------- Menu REPARATION---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des reparations"<<endl;
    cout<<"taper 2 pour afficher la liste complete des reparations"<<endl;
    cout<<"taper 3 pour demarrer une reparation"<<endl;
    cout<<"taper 4 pour modifier une reparation"<<endl;
    cout<<"taper 5 pour supprimer une reparation"<<endl;
    cout<<"taper 6 pour rechercher une reparation"<<endl;
    cout<<"taper 7 pour terminer reparation && rediger facture"<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_reparation2() ;break;
            case 2: g.afficher_reparation(0);break;
            case 3: demarrer_reparation(g);break;
            case 4: modifier_reparation(g);break;
            case 5: supprimer_reparation(g);break;
            case 6: recherche_reparation(g);break;
            case 7: terminer_reparation(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}

//-------------------- menu facture -----------------//
void modifier_facture(garage& g)
{
    int id,m=1;
    facture f;
    bool indicator = false;
    string msg;
    string msg2="ERREUR - le numero de facture doit etre positive)";
    string msg3="ERREUR - id non valide)";
    string msg6="ERREUR - saisir un entier";

    while (m != 0)
    {
        g.afficher_factures2();
        cout<<"-------------- +++ --------------"<<endl;
        while(1)
        {
            try
            {
                cout<<"saisir le numero de facture a modifier";
                cin>>id;
                if(cin.fail()) throw 1;
                else if(id < 0) throw msg2;
                break;
            }
            catch(string msg)
            {
                cout<<msg<<endl;
            }
            catch(int i)
            {
                cout<<msg3<<endl;
            }
        }
        for(int i=0;i<g.factures.size();i++)
        {
            if(g.factures[i]->Get_num()==id && g.factures[i]->Get_etat()=="non_payee")
            {
                cout<<"l'etat actuel de la facture est :"<<endl;
                cout<<*g.factures[i];
                cin>>f;
                f.Set_etat("non_payee");
                f.Set_num(g.factures[i]->Get_num());
                g.supprimer_facture(id);
                g.ajouter_facture(f);
                g.enregistrer();
                indicator = true;
            }
            else if(g.factures[i]->Get_num()==id && g.factures[i]->Get_etat()=="payee")
                cout<<"la facture est payee - modification impossible"<<endl;
        }
        if(indicator == false)
        {
            cout<<"!!! la facture n'existe pas !!!"<<endl;
            cout<<endl;
        }
        while(1)
        {
            try
            {
                cout<<"taper 0 pour terminer "<<endl;
                cin>>m;
                if(cin.fail()) throw 1;
                break;
            }
            catch(int i)
            {
                cout<<msg6<<endl;
            }
        }
        if(m == 0) break;
    }
}

void recherche_facture(garage& g)
{
    int r = 1;
    int id;
    bool indicator = false;
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir le numero de facture a afficher ------"<<endl;
        cin>>id;
        for(int i=0;i<g.factures.size();i++)
        {
            if(g.factures[i]->Get_num()==id)
            {
                cout<<*g.factures[i];
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la facture  n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
};

void payer_facture(garage& g)
{
    int id,r=1;
    date d;
    bool indicator = false;
    g.afficher_factures2_non_payee();
    cout<<"----------------+++----------------"<<endl;
    while (r != 0)
    {
        cout<<"------ saisir le numero de facture a payee ------"<<endl;
        cin>>id;
        for(int i=0;i<g.factures.size();i++)
        {
            if(g.factures[i]->Get_num()==id && g.factures[i]->Get_etat()=="non_payee")
            {
                g.factures[i]->Set_etat("payee");
                cin>>d;
                g.factures[i]->Set_date(d);
                cout<<*g.factures[i];
                indicator = true;
                //g.enregistrer();
            }
            else if(g.factures[i]->Get_num()==id && g.factures[i]->Get_etat()=="payee")
            {
                cout<<"la facture est deja payee ";
                indicator = true;
            }
        }
        if(indicator == false)
        {
            cout<<"!!! la facture  n'existe pas !!!"<<endl;
            cout<<endl;
        }
        cout<<"taper 0 pour terminer "<<endl;
        cin>>r;
    }
}

void menu_facture(garage& g)
{
    int choix;
    cout<<" -------------- Menu FACTURE---------------"<<endl;
    cout<<"taper 1 pour afficher la liste rapide des factures"<<endl;
    cout<<"taper 2 pour afficher la liste complete des factures"<<endl;
    cout<<"taper 3 pour modifier une facture"<<endl;
    cout<<"taper 4 pour rechercher une facture "<<endl;
    cout<<"taper 5 pour payee une facture"<<endl;
    cout<<"taper 0 pour retourner au menu principale "<<endl;
    cin>>choix;

    do
    {
        switch (choix)
        {
            case 1: g.afficher_factures2() ;break;
            case 2: g.afficher_facture(0);break;
            case 3: modifier_facture(g);break;
            case 4: recherche_facture(g);break;
            case 5: payer_facture(g);break;
            case 0: afficher_menu_principale(g);break;
        }
         cout<<"nouveau choix     ";
         cin>>choix;
    }while(choix != 0);
}


