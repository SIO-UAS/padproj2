#include "depen.h"

typedef struct Node{

    desti Stadt;
    struct Node* next;
    struct Node* prev;

}Node;

int lenList(Node* head);

//### still needs to be made
Node* broot_force(Node* head);//######
void print_route(Node* head);
void csv_route(Node* head); //########
void free_List(Node* head);


Node* create_List(desti* Staedte, int count);
Node* two_opt(Node* head);
Node* switch_List(Node* head,int node1 ,int node2);
Node* find_node(Node* head, int index);
Node* add_back(Node* head,desti Staedte);

double length_of_route(Node* head);

int routen_planer(desti* Staedte, int count);// die pulic funktion erhalät das array und ruft die anderen funktionen auf, ertzeigt die csv datei und printet die routen zur console

int zufall(int a, int b){ //Bereich
    return a+rand()%b;

}

void print_route(Node*head){
    double len = length_of_route(head);
    printf("The Optimal Route is:\n");

    while(head != NULL){
        printf("%30s... %3s\n",head->Stadt.city_n,head->Stadt.iso);
        head = head->next;
    }
    printf("With a total Distance of %10f km",len);
}
void csv_route(Node*head){
    FILE *csv_Safe;

    csv_Safe = fopen("route.csv","w");

    if( csv_Safe == NULL){
        printf("Fehler beim Erstellen der Datei");
    }
    while(head != NULL){
        fprintf(csv_Safe,"%s,%s,%s,%d,%d,%f,%f\n",head->Stadt.city_n,head->Stadt.country,head->Stadt.iso,head->Stadt.pop,head->Stadt.id,head->Stadt.lat,head->Stadt.lng);
        head = head->next;
    }
    fclose(csv_Safe);


}
void free_List(Node* head){

   Node *tmp;
    if (head == NULL){
        return ;
    }

    while(head->next != NULL){
        //free(head->Stadt);
        tmp = head;
        head = head->next;
        free(tmp);
    }
    //free(&head->Stadt);
    free(head);
    //*tail = NULL; //welcher Tail?
    return ;


}

int routen_planer(desti* Staedte, int count){
    if(Staedte == NULL){printf("Computer says NO!!!! #Staedte empty");return 0;}
    Node* head = NULL;
    head = create_List(Staedte, count);
    head = two_opt(head);
    print_route(head);
    csv_route(head);
    free_List(head);
    return 1;
}
int lenList(Node* head){ // #done lv1
    int len =0;
    printf("len start");
    if(head == NULL){
        //printf("liste leer")
        return 0;
    }
    while(head->next != NULL){
       len++;
       head = head->next;
    }
    printf("len end");
    return len;
}

double length_of_route(Node* head){

    double Route_len = 0;
    //int L_len = lenList(head);
    double len = 0;
    Node* tmp = head;

    if(head == NULL){
        //printf("liste lehr")
        return 0;
    }

    while(tmp->next != NULL){

        len = len + DistanceAB(tmp->Stadt.lat,tmp->next->Stadt.lat,tmp->Stadt.lng,tmp->next->Stadt.lng);
        tmp = tmp->next;

    }
    len = len + DistanceAB(head->Stadt.lat,tmp->Stadt.lat,head->Stadt.lng,tmp->Stadt.lng);

    return len;
}

Node* create_List(desti* Staedte, int count){
    int len= count;
    Node* head = NULL;
    for(int x=0; x<len; x++){
        head = add_back(head,Staedte[x]);
    }
    return head;
}
Node* two_opt(Node* head){// need testing and tooning
    int i = 0,e = 0, len = lenList(head), run = 1, changes = 0, actions = 0;
    double lenght_now = 0, length_after = 0;


    while(run){


            i = zufall(1,len);
            e = zufall(1,len);
            if (e == i){continue;}
            lenght_now = length_of_route(head);//check len of rout before switch
            head = switch_List(head,i,e); // switch to random elements
            length_after = length_of_route(head);//check len of rout after switch
            if (length_after>=lenght_now){ // if change is not helpful undo
                head = switch_List(head,i,e);
                changes--;
            }
            changes++;
            actions++;


        if (actions > changes*5 && actions > len*3 ){ // if after the ####### nochmal anschauen und optimieren
            break;
        }
    }
    return head;
}
Node* switch_List(Node* head,int node1 ,int node2){
    Node* tmp_node1 = find_node(head,node1);
    Node* tmp_node2 = find_node(head,node2);
    /*Node* tmp_np1 = find_node(head,node1-1);
    Node* tmp_np2 = find_node(head,node2-1);
    Node* tmp_nn1 = find_node(head,node1+1);
    Node* tmp_nn2 = find_node(head,node2+1);*/
    Node* tmp = NULL;

    if(head == NULL){
        //printf("liste lehr")
        return NULL;
    }


    /*
    tmp_node1->next = tmp_nn2;
    tmp_node2->next = tmp_nn1;
    tmp_node1->prev = tmp_np2;
    tmp_node2->prev = tmp_np1;

    tmp_nn1->prev = tmp_node2;
    tmp_nn2->prev = tmp_node1;

    tmp_np1->next = tmp_node2;
    tmp_np2->next = tmp_node1;
     */


    tmp = tmp_node1->next;
    tmp_node1->next = tmp_node2->next;
    tmp_node1->next->prev = tmp_node1;
    tmp_node2->next = tmp;

    tmp_node2->next->prev = tmp_node2;
    tmp = tmp_node1->prev;
    tmp_node1->prev = tmp_node2->prev;
    if(tmp_node1->prev != NULL){
        tmp_node1->prev->next = tmp_node1;
    }
    tmp_node2->prev = tmp;
    if(tmp != NULL){
      tmp_node2->prev->next = tmp_node2;
    }


    if (tmp_node1 == head){
        return tmp_node2;
    }
    if (tmp_node2 == head){
        return tmp_node1;
    }
    return head;
}
Node* find_node(Node* head, int index){

    for(int x=1; x<index; x++){
        head = head->next;
    }
    return head;
}
Node* add_back(Node* head,desti Staedte){ //add Back #### kann man stsedte einfach kopieren als ganzes ????????
    Node *p;
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {return NULL;}

    newNode->Stadt = Staedte;

    if (head == NULL){

        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    for (p=head; p->next !=NULL; p = p->next);
    newNode->next = NULL;
    newNode->prev = p;
    p->next = newNode;
    return head;
}




