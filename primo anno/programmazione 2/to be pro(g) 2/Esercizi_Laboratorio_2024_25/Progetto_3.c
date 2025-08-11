#include "contactOpq.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


struct contact {
   char* name; 
   char* surname;
   char* mobile;
   char* url;
};

ContactPtr mkContact(char* name, char* surname, char* mobile, char* url){
    if (name == NULL || surname == NULL) {
        return NULL;
    }
    
    ContactPtr ctp = (ContactPtr)malloc(sizeof(Contact));
    if(ctp == NULL){
        return NULL;
    }
    
    ctp->name = name;
    ctp->surname = surname; 
    ctp->mobile = mobile; 
    ctp->url = url; 
    return ctp;
}

void dsContact(ContactPtr* cntptr){
    if(cntptr == NULL){
        return;
    }
    if(*cntptr == NULL){
        return;
    }

    free(*cntptr);
    *cntptr = NULL;
}

void updateMobile(ContactPtr cnt, char* newMobile){
    cnt->mobile = newMobile;
}

void updateUrl(ContactPtr cnt, char* newUrl){
    cnt->url = newUrl;
}

char* getName(const ContactPtr cnt){
    if(cnt == NULL){
        return NULL;
    }
    return cnt->name;
}

char* getSurname(const ContactPtr cnt){
    if(cnt == NULL){
        return NULL;
    }
    return cnt->surname;
}

char* getMobile(const ContactPtr cnt){
    if(cnt == NULL){
        return NULL;
    }
    return cnt->mobile;
}

char* getUrl(const ContactPtr cnt){
    if(cnt == NULL){
        return NULL;
    }
   return cnt->url; 
}

_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2){
    if(strcasecmp(cnt1->name, cnt2->name) == 0 && strcasecmp(cnt1->surname, cnt2->surname) == 0){
        return 1;
    }
    else{
        return 0;
    } 
}    

int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2){ 
    int surname = strcasecmp(cnt1->surname, cnt2->surname);

    if(surname < 0){
        return -1;
    }
    else if(surname > 0){
        return 1;
    }
    else{
        int name = strcasecmp(cnt1->name, cnt2->name);

        if(name < 0){
            return -1;
        }
        else if(name > 0){
            return 1;
        }
        else{
            return 0;
        }
    }  
}