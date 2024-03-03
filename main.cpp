#include <iostream>
#include "header10.h"

int main()
{

    garage g;
    g.recuperer();



    afficher_menu_principale(g);


    cout<<"terminé"<<endl;
}


/*

 employee e;
    client c;

    date d1(14,12,2015);
    date d2(20,3,2012);
    date d3(7,1,2017);
    date d4(0,0,0);

    employee e1(1,25,"ayoub","zerdoum",50718137,700,"mec","tunis");
    employee e2(2,23,"aziz","ben_massoud",50265411,600,"elec","bizerte");
    employee e3(3,29,"mohamed","kouki",50456187,850,"tol","nabeul");


    client c1(1,32,"hafeth","gadacha",26748961,789,d1,"nabeul");
    client c2(2,40,"mahmoud","elfelhaoui",26785632,502,d2,"beja");
    client c3(3,26,"mehdi","bouzid",50756148,425,d3,"mehdia");

    facture f1(1,d1,500,"payee");
    facture f2(2,d4,650,"non_payee");
    facture f3(3,d3,210,"payee");

    piece p1(1001,"AZ300",200,15,50,12);
    piece p2(1002,"M40",500,5.2,100,25);
    piece p3(1003,"G120",20,120,10,1);
    piece p4(1004,"LH50",800,2.3,200,56);

    VElectrique ve1(2001,"T200",4,100,242,"tesla",d2,"bleu","batterie1",10);
    VElectrique ve2(2002,"ALG7500",4,250,52,"telsa",d1,"noir","batterie2",15);

    VMecanique vm1(3001,"EGY56324",4,300,156,"audi",d3,"gris","essence");
    VMecanique vm2(3002,"T752",4,140,458,"audi",d4,"vert","essence");

    cout<<endl;



    g.ajouter_facture(f1);
    g.ajouter_facture(f2);
    g.ajouter_facture(f3);


    g.ajouter_personne(e1);
    g.ajouter_personne(e2);
    g.ajouter_personne(e3);

    g.ajouter_personne(c1);
    g.ajouter_personne(c2);
    g.ajouter_personne(c3);

    g.ajouter_piece(p1);
    g.ajouter_piece(p2);
    g.ajouter_piece(p3);






    reparation r1(1,d1,"active");
    reparation r2(2,d2,"active");

    r1.ajouter_employer(e1);
    r1.ajouter_employer(e2);

    r1.ajouter_piece(p1);
    r1.ajouter_piece(p2);
    r1.ajouter_piece(p3);

    r2.ajouter_employer(e2);
    r2.ajouter_employer(e3);

    r2.ajouter_piece(p1);
    r2.ajouter_piece(p3);



    r2.Set_vehicule(vm1);
    r1.Set_vehicule(ve1);

    g.ajouter_reparation(r1);
    g.ajouter_reparation(r2);

    g.ajouterCV(ve1.getvoiture(),c1.Get_id());
    g.ajouterCV(vm1.getvoiture(),c2.Get_id());



    g.enregistrer();
*/
