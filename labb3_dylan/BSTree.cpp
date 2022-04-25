#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "BSTree.h"

/*Det är helt tillåtet att lägga till egna hjälpfunktioner men de befintliga funktionerna får inte ändras*/

/* Statiska hjalpfunktioner anvands av andra funktioner i tradet och ska inte ligga i interfacet (anvandaren behover inte kanna till dessa) */


/* Skapar en tradnod med det givna datat genom att allokera minne for noden. Glom inte att initiera pekarna*/
static struct treeNode* createNode(int data)
{
    // Glom inte att testa sa att allokeringen lyckades
    treeNode *newNode = emptyTree();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void testCreate(int data){
    treeNode* tree = createNode(data);
    printf("%d", tree->data);
}


/* Returnerar en dynamiskt allokerad array som innehaller tradets data sorterat */
static int* writeSortedToArray(const BSTree tree)
{

    /* Skapa en dynamisk array men ratt storlek

       Skriv datat från tradet sorterat till arrayen (minsta till storsta)
       - till detta kanske du behover en hjalpfunktion */

    return NULL; //Ersatt med korrekt returvarde
}

/* Bygger upp ett sorterat, balanserat trad fran en sorterad array */
static void buildTreeSortedFromArray(BSTree* tree, const int arr[], int size)
{
    /* Bygg rekursivt fran mitten.
       Mittenelementet i en delarray skapar rot i deltradet
       Vanster delarray bygger vanster deltrad
       Hoger delarray bygger hoger deltrad*/
}


/* Implementation av tradet, funktionerna i interfacet */

/* Skapar ett tomt trad - denna funktion ar fardig */
BSTree emptyTree(void)
{
    return NULL;
}

/* Returnerar 1 ifall tradet ar tomt, 0 annars */
int isEmpty(const BSTree tree)
{
    if(tree==nullptr)
        return 1;
    else
        return 0;
}

/* Satter in 'data' sorterat i *tree
 Post-condition: data finns i tradet*/
void insertSorted(BSTree* tree, int data)
{
    if(isEmpty(*tree)){
        printf("Inserted");
        *tree = createNode(data);
    }
    if((*tree)->data==data)
        return;
    if((*tree)->data>data)
        return insertSorted((&(*tree)->left), data);
    if((*tree)->data<data)
        return insertSorted((&(*tree)->right), data);
}

/* Utskriftsfunktioner
   Vid anrop: anvand stdio som andra argument for att skriva ut på skarmen
   Det racker att ni implementerar LR ordningarna*/
void printPreorder(const BSTree tree, FILE *textfile)
{
    if(isEmpty(tree))
        return;
    printf("%d", tree->data);
    if(!isEmpty(tree->left))
        return printPreorder(tree->left, stdout);
    if(!isEmpty(tree->right))
        return printPreorder(tree->right, stdout);
}

void printInorder(const BSTree tree, FILE *textfile)
{
    if(isEmpty(tree))
        return;
    if(!isEmpty(tree->left))
        return printPreorder(tree->left, stdout);
    printf("%d", tree->data);
}

void printPostorder(const BSTree tree, FILE *textfile)
{
    if(isEmpty(tree))
        return;
    if(!isEmpty(tree->left))
        return printPreorder(tree->left, stdout);
    if(!isEmpty(tree->right))
        return printPreorder(tree->right, stdout);
    printf("%d", tree->data);
}

/* Returnerar 1 om 'data' finns i tree, 0 annars */
int find(const BSTree tree, int data)
{
    // Tank pa att tradet kan vara tomt
    if(isEmpty(tree))
        return 0;
    if(tree->data==data)
        return 1;
    if(tree->data>data)
        return find(tree->left, data);
    else
        return find(tree->right, data);
}

/* Tar bort 'data' fran tradet om det finns */
void removeElement(BSTree* tree, int data)
{
    /* Inget data ska/kan tas bort fran ett tomt trad
     Tre fall: Ett lov (inga barn), ett barn (vanster eller hoger), tva barn

     Glom inte att frigora noden nar den lankats ur tradet*/
    if(isEmpty(*tree))
        return;
    if((*tree)->data==data){
        if((*tree)->right==NULL || (*tree)->left==NULL)
                return;
        else if((*tree)->left==NULL)
            free((*tree));
        else if((*tree)->right==NULL)
            free((*tree));
    }
    if((*tree)->data>data)
        return removeElement(&(*tree)->left, data);
    if((*tree)->data<data)
        return removeElement(&(*tree)->right, data);
}

/* Returnerar hur manga noder som totalt finns i tradet */
int numberOfNodes(const BSTree tree)
{
    if(isEmpty(tree))
        return 0;
    int num = 0;
    if(!isEmpty(tree->left))
        return num+numberOfNodes(tree->left);
    if(!isEmpty(tree->right))
        return num+numberOfNodes(tree->right);
    else return 1;
}

/* Returnerar hur djupt tradet ar */
int depth(const BSTree tree)
{
    if(isEmpty(tree))
        return 0;
    else {
        int leftDepth = depth(tree->left);
        int rightdepth = depth(tree->right);
        if(leftDepth>rightdepth)
            return leftDepth;
        else
            return rightdepth;
    }
}

/* Returnerar minimidjupet for tradet
   Se math.h for anvandbara funktioner*/
int minDepth(const BSTree tree)
{
    if(isEmpty(tree))
        return 0;
    else {
        int leftDepth = depth(tree->left);
        int rightdepth = depth(tree->right);

        if(leftDepth<rightdepth)
            return leftDepth+1;
        else
            return rightdepth+1;
    }
}

/* Balansera tradet sa att depth(tree) == minDepth(tree) */
void balanceTree(BSTree* tree)
{
    /* Forslag pa algoritm:
       - overfor tradet till en dynamiskt allokerad array med writeSortedToArray()
       - tom tradet med freeTree()
       - bygg upp tradet rekursivt fran arrayen med buildTreeSortedFromArray()
       - frigor minne for den dynamiskt allokerade arrayen


       Post-conditions:
       - tree har lika manga noder som tidigare
       - djupet for tradet ar samma som minimumdjupet for tradet */
}

/* Tom tradet och frigor minnet for de olika noderna */
void freeTree(BSTree* tree)
{
    // Post-condition: tradet ar tomt
}


