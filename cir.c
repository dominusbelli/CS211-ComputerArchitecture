#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void buildTree(node **root, node *target)
{
  if(*root == NULL)
    {
      return;
    }
  if((*root)->name==target->name)
    {
      printf("Node Replaced: %c\nBy Target: %c\n", (*root)->name,target->name);
      *root = target;
      return;
    }
  buildTree(&(*root)->left,target);
  printf("Current Node: %c\n", (*root)->name);
  buildTree(&(*root)->right,target);
}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%c\n",tree->name);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("Inorder: %c\n",tree->name);
        print_inorder(tree->right);
    }
}

struct node* createNode(char name)
{
  node *theNode;
  char nameC;
  theNode->name = &nameC;
  theNode->name = name;
  return theNode;
}

struct node* buildNode(char gateStr[])
{
  char gateT = gateStr[0];
  node *gate = malloc(sizeof(struct node));
  if(gateStr[0]=='A')
	{
	  printf("AND STATEMENT\n");
	  node *gateL = malloc(sizeof(struct node));
	  node *gateR = malloc(sizeof(struct node));
	  gate->name = gateStr[8];
	  printf("Current Gate Build: %c\n", gateStr[8]);
	  gateL->name = gateStr[4];
	  gateR->name = gateStr[6];
	  gate->left = gateL;
	  gate->right = gateR;
	  printf("Gate Name: %c\nGateLeft: %c\nGateRight: %c\n", gate->name, gate->left->name, gate->right->name);
	}
      else if(gateStr[0]=='O')
	{
	  printf("OR STATEMENT\n");
	  node *gateL = malloc(sizeof(struct node));
	  node *gateR = malloc(sizeof(struct node));
	  char nameC;
	  gate->name = &nameC;
	  gate->name = gateStr[7];
	  printf("Current Gate Build: %c\n", gate->name);
	  //gateL = createNode('G');
	  //printf("gateL: %c\n", gateL->name);
	  char typeC;
	  //printf("Still OKAY!\n");
	  gate->type = &typeC;
	  //printf("Still OKAY!\n");
	  gate->type = '+';
	  //printf("type: %c\n", gate->type);
	  char nameL;
	  gateL->name = &nameL;
	  char nameR;
	  gateR->name = &nameR;
	  gateL->name = gateStr[3];
	  gateR->name = gateStr[5];
	  //printf("%c\n", gateL->name);
	  //printf("%c\n", gateR->name);
	  gate->left = gateL;
	  gate->right = gateR;
	  printf("Gate Name: %c\nGateLeft: %c\nGateRight: %c\n", gate->name, gate->left->name, gate->right->name);
	}
      else if(gateStr[0]=='N')
	{
	  printf("NOT STATEMENT\n");
	  node *gateL = malloc(sizeof(struct node));
	  gate->name = gateStr[8];
	  printf("Current Gate Build: %c\n", gateStr[8]);
	  gate->type = '_';
	  gateL->name = gateStr[4];
	  gate->left = gateL;
	  printf("Gate Name: %c\nGateLeft: %c\n", gate->name, gate->left->name);
	}
  return gate;
}

/*int evaluate(node *root, inputvar *list[], int inputamt)
{
  int a, b;
  a=evaluate(root->left, list, inputamt);
  b=evaulate(root->right, list, inputamt);
  if(root->type=='*')
    {
      return andGate(a,b);
    }
  else if(root->type=='+')
    {
      return orGate(a,b);
    }
  else if(root->type=='_')
    {
      return notGate(a);
    }
  else
    {
      int i;
      for(i = 0; i<inputamt; i++)
	{
	  if(root->name == list[i]->name)
	    {
	      return list[i]->val;
	    }
	}
    }
    }*/

int andGate(int a, int b)
{
  if(a==1 && b==1)
    {
      return 1;
    }
  else
    return 0;
}
int orGate(int a, int b)
{
  if(a==1 && b==1)
    {
      return 0;
    }
  else
    return 1;
}
int notGate(int a)
{
  if(a==1)
    {
      return 0;
    }
  else
    return 1;
}

//struct node * buildTree(

int main(int argc, char * argv[])
{
  FILE *theCircuit;
  FILE *theInput;
  theCircuit = fopen(argv[1], "r");
  char circuit[100];
  char *allGates[100];
  int gateCount=0;
  //Creates an Array of Strings for the circuit.txt file
  while(fgets(circuit, sizeof circuit, theCircuit)!=NULL)
    {
      allGates[gateCount] = malloc(sizeof circuit);
      strcpy(allGates[gateCount],circuit);
      printf("%d , %s", gateCount, allGates[gateCount]);
      gateCount++;
    }
  gateCount--;
  int i;
  for(i = 0; i < gateCount; i++) {
        printf("Gate %d: %s\n", i, allGates[i]);
    }
  node *root;
  root = NULL;
  //printf("%d\n",gateCount);
  i = gateCount;
  if(root==NULL)
    {
      printf("YES\n");
    }
  //Builds the tree by sending lines to buildTree()
  while(i!=1)
    {
      printf("Sending line: %d\n", i);
      node *temp = NULL;
      temp = buildNode(allGates[i]);
      if(root == NULL)
	{
	  root=temp;
	}
      else
	{
	  buildTree(&root, temp);
	}
      i--;
    }
  //print_preorder(root);
  print_inorder(root);

  //Input File Stream is read here and is evaulated per line
  printf("%c\n", allGates[0][9]);
  int inputnum = allGates[0][9] - '0';
  printf("Input Num: %d\n", inputnum);
  int max = inputnum;
  inputvar list[3];
  inputnum = 11;
  i = 0;
  char inputLine[100];
  while(i<max)
    {
      inputvar *temp = malloc(sizeof(inputvar));
      temp->name = allGates[0][inputnum];
      list[i] = *temp;
      i++;
      inputnum+=2;
    }
  i--;
  printf("i == %d\n", i);
  for(i = 0; i < max; i++) {
        printf("Input %d: %c\n", i, list[i].name);
	printf("%d\n", i);
    }

  //Actual FILE Input Stream Evaluation
  char inputFile[100];
  theInput = fopen(argv[2], "r");
  while(fgets(inputFile, sizeof inputFile, theInput)!=NULL)
   {
      int count = 0;
      i=0;
      do
	{
	  list[i].val = inputFile[count]-'0';
	  printf("Value: %d\n", list[i].val);
	  count+=2;
	  i++;
	}while(i<max);
      int ans;
      //ans = evaluate(root,list,max);
      //printf("%d\n",ans);
    }
}

/*
while(i!=1)
    {
      char *gateStr= allGates[i];
      printf("%s", gateStr);
      if(gateStr[0]=='A')
	{
	  struct node * gate;
	  struct node * gateL;
	  struct node * gateR;
	  gate->name = gateStr[8];
	  printf("%c", gateStr[8]);
	  gate->type ='*';
	  gateL->name = gateStr[4];
	  gateR->name = gateStr[6];
	  gate->left = gateL;
	  gate->right = gateR;
	}
      else if(gateStr[0]=='O')
	{
	  struct node * gate;
	  struct node * gateL;
	  struct node * gateR;
	  gate->name = gateStr[7];
	  printf("%c", gateStr[7]);
	  //gate->type = '+';
	  //gateL->name = gateStr[3];
	  //gateR->name = gateStr[5];
	  //gate->left = gateL;
	  //gate->right = gateR;
	}
      else if(gateStr[0]=='N')
	{
	  struct node * gate;
	  struct node * gateL;
	  gate->name = gateStr[8];
	  printf("%c", gateStr[8]);
	  gate->type = '_';
	  gateL->name = gateStr[4];
	  gate->left = gateL;
	}
      //buildTree(allGates[i]);
      i--;
      }
*/
