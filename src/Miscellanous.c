#include "Miscellanous.h"

int RNG(int min, int max)
{
    return ( ( rand() % (max - min + 1) ) + min );
}

int CoordCompare(int** matrice_map, int int_x, int int_y, char constant_rep)
{
    return (matrice_map[int_x][int_y] == constant_rep);
}

int IsBetween(int int_Comp, int int_min, int int_max){
    return (int_Comp >= int_min && int_Comp <= int_max);
}

void printf_center(const char* str)
{
    unsigned int n;
    for (n = 0; n < (204-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}

void InitRNG()
{
    srand(time(NULL)); //init RNG
}


////////////////////////////////////////
// FONCTIONS POUR LES LISTES CHAINEES //
////////////////////////////////////////

Node* CreateNode(coordonnees coord) // Créer une nouvelle node à ajouter dans la liste
{
    Node *node = malloc(sizeof(*node));
    if(!node){
        free(node);
        exit(EXIT_FAILURE);
    }
    node->coordonnees = coord;
    node->next = NULL;
    return node;
}

List* InitList()  // Initialise la liste chainée
{
    List *list_new = malloc(sizeof(*list_new));
    Node *node_new = malloc(sizeof(*node_new));
    if(list_new == NULL || node_new == NULL){
        free(list_new);
        free(node_new);
        puts("Error in InitList");
        exit(EXIT_FAILURE);
    }
    node_new->next = NULL;
    node_new->coordonnees.x=-1;
    node_new->coordonnees.y=-1;
    list_new->firstnode = node_new;
    return(list_new);
}


void AddNode(List* p_list, coordonnees coord) // Ajoute une node en début de liste (fonctionne comme une pile)
{       
    /*creation de la nouvel node*/
    Node *node_new = CreateNode(coord);
    if(p_list == NULL){
        puts("Error in AddNode");
        exit(EXIT_FAILURE);
    }
    /*insert new node in the list*/
    node_new->next = p_list->firstnode;
    p_list->firstnode = node_new;
}

void RemoveNode(List* p_list) // retire la dernière node de la liste
{
    if(p_list == NULL){
        puts("Error in RemoveNode");
        exit(EXIT_FAILURE);
    }
    if(p_list->firstnode != NULL){
        Node* node_toRemove =  p_list->firstnode;
        p_list->firstnode = p_list->firstnode->next;
        free(node_toRemove);
    }
}

long LengthList(List *p_list) // Permet d'obtenir la taille de la liste
{
    long long_taille = 0;
    Node* node_current = p_list->firstnode;
    while(node_current != NULL)
    {
        long_taille = long_taille + 1;
        node_current = node_current->next;
    }
    return long_taille;
}

void GetfirstNode(List* p_list, int* p_last_x, int* p_last_y) // renvoit les coordonnées de la dernière node ajoutée
{   
    if(p_list == NULL){
        exit(EXIT_FAILURE);
    }
    Node* node_current = p_list->firstnode;
    *p_last_x = node_current->coordonnees.x;
    *p_last_y = node_current->coordonnees.y;
}

void PrintList(List* p_list) // Permet d'afficher la liste chainée
{
    if(p_list == NULL){
        exit(EXIT_FAILURE);
    }
    Node* node_current = p_list->firstnode;
    printf("List: |");
    while(node_current != NULL)
    {
        printf("x=%d, y=%d |", node_current->coordonnees.x, node_current->coordonnees.y);
        node_current = node_current->next;
    }
    printf("\n");
}

void FreeList(List* p_list) // Libère la mémoire alloué à la liste
{
    if(p_list == NULL){
        free(p_list);
        return;
    }
    Node* node_current = p_list->firstnode;
    while(node_current != NULL){
        free(node_current);
        node_current = node_current->next;
    }
    free(node_current);
}

