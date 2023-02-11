/***************************************************************
 * Name:      connect_fourApp.h
 * Purpose:   Definiuje klasę aplikacji
 * Author:    Igor Nowiński, Szymon Olędzki, Tymoteusz Romanowicz
 * Created:   2022-12-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef CONNECT_FOURAPP_H
#define CONNECT_FOURAPP_H

#include <wx/app.h>

class connect_fourApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CONNECT_FOURAPP_H
