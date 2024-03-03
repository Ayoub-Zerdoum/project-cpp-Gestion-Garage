#ifndef HEADER10_H_INCLUDED
#define HEADER10_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include<algorithm>
#include<stack>
#include<list>
#include<exception>
#include <limits>



using namespace std;
// --------- class date -------------- //
class date
{
    int jour;
    int mois;
    int annee;
public:
    date(int,int,int);
    date(){};
    friend ostream& operator<<(ostream&,date&);
    friend istream& operator>>(istream&,date&);

    friend ostream& operator<<(ostream&,date*);
    friend istream& operator>>(istream&,date*);
};

// --------- class personne -------------- //
class personne
{
protected:
    int id;
    int age;
    string nom;
    string prenom;
    int telephone;
public:
    personne(int,int,string,string,int);
    personne(){};
    personne(const personne&);
    int Get_id(){return id;};
    void Set_id(int i){this->id =i;};
    virtual void afficher();
    virtual void afficher2()= 0;
    void Set_telephone(int t){this->telephone=t;};
    friend ostream& operator<<(ostream&,personne&);
    friend istream& operator>>(istream&,personne&);

    friend ostream& operator<<(ostream&,personne*);
    friend istream& operator>>(istream&,personne*);
};

// --------- class client -------------- //
class client:public personne
{
    int num_permis;
    date date_obtention;
    string ville;
public:
    client(int,int,string,string,int,int,date,string);
    client(){};
    void afficher();
    void afficher2(){cout<<id<<"  "<<nom<<"   "<<prenom<<"    "<<num_permis<<endl;};
    friend ostream& operator<<(ostream&,client&);
    friend istream& operator>>(istream&,client&);

    friend ostream& operator<<(ostream&,client*);
    friend istream& operator>>(istream&,client*);
};

// --------- class emplyee -------------- //
class employee:public personne
{
    float salaire;;
    string specialite;
    string address;
public:
    employee(int,int,string,string,int,float,string,string);
    employee(){};
    void afficher();
    void afficher2(){cout<<id<<"  "<<nom<<"   "<<prenom<<"    "<<salaire<<"   "<<specialite<<endl;};
    bool operator==(const employee& e) const {return (id == e.id);}
    bool operator<(const employee& e) const {return salaire < e.salaire;}
    float Get_salaire(){return salaire;};
    void Set_salaire(float s){this->salaire=s;};
    friend ostream& operator<<(ostream&,employee&);
    friend istream& operator>>(istream&,employee&);

    friend ostream& operator<<(ostream&,employee*);
    friend istream& operator>>(istream&,employee*);
};

// --------- class facture -------------- //
class facture
{
    int num_facture;
    date date_payement;
    float montant;
    string etat;
public:
    facture(int,date,float,string);
    facture(){};
    void afficher2(){cout<<num_facture<<"  "<<montant<<"   "<<date_payement<<"    "<<etat<<endl;};
    int Get_num(){return num_facture;};
    void Set_num(int i){num_facture = i;};
    void Set_etat(string e){this->etat=e;};
    string Get_etat(){return etat;};
    void Set_date(date& d){date_payement = d;}
    void Set_montant(float m){montant=m;};
    friend ostream& operator<<(ostream&,facture&);
    friend istream& operator>>(istream&,facture&);

    friend ostream& operator<<(ostream&,facture*);
    friend istream& operator>>(istream&,facture*);
};

//----------- template pile --------------//
template<class T>
struct element
{
    T info;
    element* suivant;
};

template<class T>
class pile
{
    element<T>* sommet;
public:
    pile(){sommet=NULL;};
    ~pile()
    {
        while(sommet!=NULL)
            depiler();
    };

    void empiler(T t)
    {
        element<T> *e = new element<T>;
        e->suivant=sommet;
        e->info=t;
        sommet=e;
    };

    T depiler()
    {
        if(sommet != NULL )
        {
            element<T>*e =sommet;
            T data=e->info;
            sommet=sommet->suivant;
            delete e;
            return data;
        }
    };

    bool estVide(){return(sommet==NULL);};

    int NbElements()
    {
        element<T>*e=sommet;
        int n=0;
        while(e!=NULL)
        {
            e=e->suivant;
            n++;
        }
    };

    void afficher()
    {
        if(sommet==NULL)
            cout<<"\n la pile est vide"<<endl;
        else
        {
            element<T>*e=sommet;
            while(e!=NULL)
            {
                cout<<e<<"  "<<e->info<<endl;
                e=e->suivant;
            }
        }
    };

    pile(const pile<T>& w)
    {
        sommet = NULL;
        element<T>*e;
        element<T>*courant;
        element<T>*tmp = NULL;
        courant =w.sommet;
        while(courant!=NULL)
        {
            e =new element<T>(*courant);
            if(sommet == NULL)
                sommet =e;
            else
                tmp->suivant=e;
            tmp = e;
            courant=courant->suivant;
        }
    };
    pile& operator=(pile<T>& w)
    {
        if(this!=&w)
        {
            while(sommet!=NULL)
                depiler();
            sommet = NULL;
            element<T>*e;
            element<T>*courant;
            element<T>*tmp = NULL;
            courant =w.sommet;
            while(courant!=NULL)
            {
                e =new element<T>(*courant);
                if(sommet == NULL)
                    sommet =e;
                else
                    tmp->suivant=e;
                tmp = e;
                courant=courant->suivant;
            }
        }
        return *this;
    };
};
// --------- class voiture -------------- //
class voiture
{
protected:
    int id;
    string immatricule;
    int nb_place;
    int puissance;
    int kilometrage;
    string marque;
    date d;//date_mise_en_service
    string couleur;
public:
    voiture(int,string,int,int,int,string,date,string);
    voiture(){};
    voiture(const voiture&);
    int getvoiture(){return id;};
    void Set_num(int i){id = i;};
    void  set_kilometrage(int a){kilometrage=a;};
    virtual void afficher();
    virtual void afficher2() = 0;

    virtual void ecrire(fstream&);

    friend ostream& operator<<(ostream&,voiture*);
    friend istream& operator>>(istream&,voiture*);

    friend ostream& operator<<(ostream&,voiture&);
    friend istream& operator>>(istream&,voiture&);
};
// --------- class voitureElectrique -------------- //
class VElectrique :public voiture
{
    string batterie;
    int temps_charge;
public:
    VElectrique(){};
 //   VElectrique(const VElectrique&);
    void afficher();
    void afficher2(){cout<<id<<"  "<<immatricule<<"   "<<marque<<"    "<<batterie<<endl;};
    VElectrique(int,string,int,int,int,string,date,string,string,int);
    void set_kilometrage(int a){kilometrage=a;};
    void ecrire(fstream&);
    friend ostream& operator<<(ostream&,VElectrique*);
    friend istream& operator>>(istream&,VElectrique*);

    friend ostream& operator<<(ostream&,VElectrique&);
    friend istream& operator>>(istream&,VElectrique&);
};

// --------- class voitureMecanique -------------- //
class VMecanique : public voiture
{
    string type_carburant;
public:
    VMecanique(){};
    void afficher();
    void afficher2(){cout<<id<<"  "<<immatricule<<"   "<<marque<<"    "<<type_carburant<<endl;};
    VMecanique(int,string,int,int,int,string,date,string,string);
    friend ostream& operator<<(ostream&,VMecanique*);
    friend istream& operator>>(istream&,VMecanique*);
    friend ostream& operator<<(ostream&,VMecanique&);
    friend istream& operator>>(istream&,VMecanique&);
};

// --------- class  piece -------------- //
class piece
{
    int reference_piece;
    string designation ;
    int quantiter_stock;
    float prix;
    int critique;
    int quantiter;
public:
    piece(){};
    piece(int,string,int,float,int,int);
    void afficher();
    void afficher2(){cout<<reference_piece<<"  "<<designation<<"   "<<quantiter_stock<<"    "<<prix<<endl;};
    void afficher3(){cout<<reference_piece<<"  "<<designation<<"   "<<prix<<"    "<<quantiter<<endl;};
    bool operator==(const piece& p) const {return reference_piece == p.reference_piece ;}
    bool operator<(const piece& p) const {return prix< p.prix;}
    int get_quantiter(){return quantiter;};
    int get_stock(){return quantiter_stock;};
    int Get_critique(){return critique;};
    float get_prix(){return prix;};
    int Get_num(){return reference_piece;};
    void Set_reference(int i){this->reference_piece=i;};
    void set_quantiter_stock(int a){quantiter_stock=a;};
    void set_quantiter(int a)
    {   if (quantiter_stock-a<0)
            cout<<"\n\ncette piece est n'a pas available";
        else
            {
            quantiter =a;
            set_quantiter_stock(quantiter_stock-a);
            }
    };
    void set_critique(int a){critique=a;};
    void set_prix(float a){prix=a;};
    friend ostream& operator<<(ostream&,piece&);
    friend istream& operator>>(istream&,piece&);
    friend ostream& operator<<(ostream&,piece*);
    friend istream& operator>>(istream&,piece*);
};
//---------- class map ------------------------//
class vc
{
public:
    map<int,int> a;
    map<int,int>::iterator it;
public:
    vc(){};
    vc(const vc& );
    void ajoutermap(int,int);
    void affichermap();
    void modifiermap(int,int);
    int val(int v){return a[v];};
    void recherchermap(int);
    friend ostream& operator<<(ostream& os, const vc& obj) {
        for (auto & [key, val] : obj.a) {
            os <<"id voiture :"<< key << " : " << "id client :"<<val << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, vc& obj) {
    int x,key, value;

     do{
        cout<<"donner id voiture/client   ";
        is >> key >> value;
        obj.a[key] = value;
    cout<<"\ntapez 1 pour ajouter autre couple  ";
    is>>x;
    }while (x);
    return is;
    }

    friend ostream& operator<<(ostream& os, const vc* obj)
    {
        for (auto & [key, val] : obj->a) {
            os <<"0  "<< key <<"  "<<val << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, vc* obj)
    {
        int val,key,value;
        if(val == 0)
        {
            is >> key >> value;
            obj->a[key] = value;
        }
    }
    void suprimmap(int);
};

//------------ template file -------------//
template<typename T>
class Queue {
private:
    vector<T> data;
public:
    void push(const T& item) {data.push_back(item);}

    void pop() {
        if (!empty()) {data.erase(data.begin());}}
    T& front() {return data.front();}
    T& back() {return data.back();}
    bool empty() const {return data.empty();}
    size_t size() const {return data.size();}

    void copy(Queue<voiture*>& source, Queue<voiture*>& destination)
    {
        while (!source.empty())
        {
            destination.push(source.front());
            source.pop();
        }
    }
};

// --------- class  reparation -------------- //
class reparation
{
    int num_reparation;
    vector <employee*>employer;
    vector <piece*> piec;
    voiture* v;
    date d;
    int num_facture;
    string etat;
public:
    reparation(){};
    reparation(const reparation& );
    reparation(int,date,string);

    void Set_vehicule(voiture &);

    void set_etat(string e){etat =e;};
    string Get_etat(){return etat;};
    void Set_date(date d){this->d = d;};
    int Get_num(){return num_reparation;};
    void Set_num(int n){this->num_reparation = n;};
    int Get_facture(){return num_facture;};
    void Set_num_facture(int i){this->num_facture = i;};
    int getvoiture(){return v->getvoiture();};
    void afficher();
    void afficher_v2();
    void afficher2(){cout<<num_reparation<<"    "<<v->getvoiture()<<"   employees:"<<employer.size()<<"   pieces:"<<piec.size()<<"  "<<etat<<endl;;};

    void enregistrer(int);
    void recuperer(int);
    void creer_fichier_reparation(fstream &);

    void ajouter_employer(employee&);
    friend istream& operator>>(istream&,reparation*);
    friend ostream& operator<<(ostream&,reparation*);
    friend istream& operator>>(istream&,reparation &);
    friend ostream& operator<<(ostream&,reparation &);
    void afficher_employees();
    void ajouter_piece(piece&);
    void afficher_pieces();
    void afficher_voiture();
    float calcul_montant();
    ~reparation();

    void modifier_reparation_fichier(int);
    void modifier_reparation();

};

// --------- class garage -------------- //
class garage
{
    vector<personne*> personnes;
    vector<facture*> factures;
    list<piece*> pieces;
    vector<reparation*> reparations;
    map<int,string> fichier_reparation;
    vc voiture_client;
    Queue<voiture*> file_attente;
public:
    garage(){};
    ~garage();
    garage(const garage&);

    virtual void ajouter_personne(personne&);


    void enregistrer();
    void recuperer();
    static void creer_fichier_personne(fstream &);
    static void creer_fichier_factures(fstream &);
    static void creer_fichier_piece(fstream &);
    static void creer_fichier_reparations(fstream &);
    static void creer_fichier_vc(fstream &);

    void ajouterCV(int v,int c){voiture_client.ajoutermap(v,c);};

    void supprimer_personne(int);
    void afficher_clients(int);
    void afficher_employees(int);

    void afficher_clients2();
    void afficher_employees2();
    void afficherVC(){voiture_client.affichermap();};

    void ajouter_facture(facture&);
    void supprimer_facture(int);
    void afficher_facture(int);
    void afficher_factures2();
    void afficher_factures2_non_payee();

    void ajouter_piece(piece&);
    void supprimer_piece(int);
    void afficher_piece(int);
    void afficher_pieces2();

    void ajouter_reparation(reparation&);
    void supprimer_reparation(int);
    void afficher_reparation(int);
    void afficher_reparation2();
    void afficher_reparation2_active();

    void afficher_file2();
    void afficher_file();
    void ajouter_voiture();
    void afficher_voitures();


    friend void ajouter_client(garage &g);
    friend void supprimer_client(garage &g);
    friend void modifier_client(garage &g);
    friend void recherche_client(garage &g);

    friend void ajouter_employee(garage &g);
    friend void supprimer_employee(garage &g);
    friend void modifier_employee(garage &g);
    friend void recherche_employee(garage &g);

    friend void ajouter_piece(garage &g);
    friend void supprimer_piece(garage &g);
    friend void modifier_piece(garage &g);
    friend void ajouter_stock_piece(garage &g);
    friend void recherche_piece(garage &g);


    friend void modifier_voiture(garage&g);
    friend void recherche_proprietaire(garage&g);

    friend void demarrer_reparation(garage& g);
    friend void supprimer_reparation(garage& g);
    friend void modifier_reparation(garage& g);
    friend void recherche_reparation(garage& g);
    friend void terminer_reparation(garage& g);

    friend void modifier_facture(garage& g);
    friend void recherche_facture(garage& g);
    friend void payer_facture(garage& g);
    friend void menu_facture(garage& g);

    friend void afficher_menu_principale(garage&g);


};

void ajouter_client(garage &g);
void supprimer_client(garage &g);
void modifier_client(garage &g);
void recherche_client(garage &g);
void menu_client(garage& g);

void ajouter_employee(garage &g);
void supprimer_employee(garage &g);
void modifier_employee(garage &g);
void recherche_employee(garage &g);
void menu_employee(garage& g);

void ajouter_piece(garage &g);
void supprimer_piece(garage &g);
void modifier_piece(garage &g);
void ajouter_stock_piece(garage &g);
void recherche_piece(garage &g);
void menu_piece(garage& g);

void modifier_voiture(garage&g);
void recherche_proprietaire(garage&g);
void menu_voiture(garage& g);

void demarrer_reparation(garage& g);
void supprimer_reparation(garage& g);
void modifier_reparation(garage& g);
void recherche_reparation(garage& g);
void terminer_reparation(garage& g);
void menu_reparation(garage& g);

void modifier_facture(garage& g);
void recherche_facture(garage& g);
void payer_facture(garage& g);
void menu_facture(garage& g);

void afficher_menu_principale(garage& g);

#endif // HEADER10_H_INCLUDED
