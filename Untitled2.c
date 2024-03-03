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
