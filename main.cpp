#include <QApplication>
#include "Controller/Header/controller.h"

#include "Entities/Header/cvector.h"
#include "Entities/Header/unique_ptr.h"

#include "Entities/Header/tunnel.h"
#include "Entities/Header/blocco.h"
#include "Entities/Header/crollo.h"
#include "Enums/obstructiontype.h"

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);

    Controller c;
    c.ShowMainWindow();

    return a.exec();
*/

    CVector<unique_ptr<Card>*> vec(10);

    //vec[0]=a;
    //vec[1]= new unique_ptr<Tunnel>(new Tunnel());
    //vec[0]=vec[1];
    //delete vec[1];

    /*for(int i=0;i<10;i++){
        if(*(vec[i]))
            std::cout<<i<<" ok"<<std::endl;
        else
            std::cout<<i<<" no"<<std::endl;
    }

*/

    vec[0]= new unique_ptr<Card>(new Tunnel());
    vec[1]= new unique_ptr<Card>(vec[0]->get()->clone());
    delete vec[0];


    for(int i=0;i<10;i++){
        if(vec[i] && *(vec[i]))
            std::cout<<i<<" ok"<<std::endl;
        else
            std::cout<<i<<" no"<<std::endl;
    }
    std::cout<<std::endl;


    //Crollo()

    vec[9]= new unique_ptr<Card>(new Blocco());
    vec[7]= new unique_ptr<Card>(new Crollo());


   /* if(vec[7] && *vec[7])
        std::cout<<"ciao"<<std::endl;

   switch (dynamic_cast<Obstruction*>(vec[7]->get())->getType()) {
    case 0:
        std::cout<<"blocco"<<std::endl;
        break;
    case 1:
        std::cout<<"crollo"<<std::endl;
        break;
    }
*/

    if(dynamic_cast<Tunnel*>((vec[7]->get())))
        std::cout<<"tunnel"<<std::endl;
    if(dynamic_cast<Blocco*>((vec[7]->get())))
        std::cout<<"blocco"<<std::endl;
    if(dynamic_cast<Crollo*>((vec[7]->get())))
        std::cout<<"crollo"<<std::endl;


    for(int i=0;i<10;i++){
        if(vec[i] && *(vec[i]))
            std::cout<<i<<" ok"<<std::endl;
        else
            std::cout<<i<<" no"<<std::endl;
    }

    return 0;
}
