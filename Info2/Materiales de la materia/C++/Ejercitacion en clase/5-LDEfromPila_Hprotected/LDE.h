/*
  Name: 
  Copyright: 
  Author: 
  Date: 14/11/10 18:17
  Description: 
*/

#ifndef LDE_H
#define LDE_H

    #include "Pila.h"
    #include "datos.h"
    #include <iostream>
    using namespace std;


    class LDE: public Pila {   
       private:
          bool insert (NODO*,DATO&);
        
       public:
          bool enlisto (DATO&);

          friend ostream& operator<< (ostream& , LDE& );
          friend ostream& operator>> (ostream& , LDE& );
    };
    
    
#endif
