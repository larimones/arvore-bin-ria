#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinTreeNode {
    char key;
    struct BinTreeNode *left;
    struct BinTreeNode *right;
} BinTreeNode;
void createTree(BinTreeNode **root)
{
  *root = NULL;
}
BinTreeNode *BinTreeRebuild(char preordemEst[], int rootIndex, int *qtdNos) 
{
  BinTreeNode *root;
  int qtdNosSubarv;
  if (rootIndex < 0) 
  {
    return NULL;
  }
  else
  {
    root = malloc(sizeof(BinTreeNode));
    root->key = preordemEst[rootIndex];
    root->left = NULL;
    root->right = NULL;
    *qtdNos = 1;
  }
  if (preordemEst[rootIndex + 1] != '0') 
  {
    root->left = BinTreeRebuild(preordemEst, rootIndex + 3, &qtdNosSubarv);
    *qtdNos += qtdNosSubarv;
  }
  if (preordemEst[rootIndex + 2] != '0')
  {
    root->right = BinTreeRebuild(preordemEst, rootIndex + (*qtdNos * 3), &qtdNosSubarv);
    *qtdNos += qtdNosSubarv;
  }
    return root;
}
void posOrdemprint(BinTreeNode *root)
{
  if(root != NULL)
  {
    posOrdemprint(root->left);
    posOrdemprint(root->right);
    printf("%c", root->key);
  }
}
void printOrdem(BinTreeNode * root)
{
  if(root != NULL)
  {
    printOrdem(root->left);
    printf("%c", root->key);
    printOrdem(root->right);
  }
}
 BinTreeNode * treeFree(BinTreeNode * root)
{
  if (root != NULL)
  {
  treeFree(root->left);
  treeFree(root-> right);
  free(root);
  printf("0");
  }
  return NULL;
} 
int main() {
  int qtdNos;
  int tamPreordemEst;
  char *preordemEst = NULL;
  BinTreeNode *root;
  
  scanf("%d", &qtdNos);
  tamPreordemEst = qtdNos * 3;
  preordemEst = malloc((tamPreordemEst + 1) * sizeof(char));
  scanf("\n");
  fgets(preordemEst, tamPreordemEst + 1, stdin);
  preordemEst[strcspn(preordemEst, "\n")] = '\0';
  if (qtdNos > 0) 
  {
    root = BinTreeRebuild(preordemEst, 0, &qtdNos);
    printOrdem(root);
    printf("\n");
    posOrdemprint(root);
    printf("\n");
    treeFree(root);
    printf("\n");
  }
  else
  {
    root = NULL;
  }
  return 0;
}
