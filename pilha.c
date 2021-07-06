#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 60

struct stack
{
  char item[MAXTAM];
  struct stack *next;
};  
typedef struct stack pilha;

typedef struct Tpilha
{
  pilha *topo;
  pilha *tail;
}_pilha;

void Tpilha_inicia (_pilha *p) 
{
  p->topo = NULL;
  p->tail = NULL;
  return;
}

_pilha insere_item (_pilha stack, char S[MAXTAM])
{
  pilha * site;
  site=(pilha *)malloc(sizeof(pilha));
  strcpy (site->item,S);
  site->next=NULL;
    if (stack.tail==NULL)
    {
        stack.topo=site;
        stack.tail=site;
    }
    else{
        site->next=stack.tail;
        stack.tail=site;
    }
    return stack;
}



_pilha deletitem(_pilha Verify)
{
  pilha *delet;
  delet=Verify.tail;
    if(Verify.tail!= NULL)
    {
      printf("%s\n",Verify.tail->item);
      Verify.tail = Verify.tail->next;
      free(delet);
    }
    else
    {
      printf("Vazio\n");
    }
    return Verify;
}

int main(void)
{
 _pilha _new;
    Tpilha_inicia(&_new);
    char url[MAXTAM];
    scanf("%s", url);
    while (strcmp(url,"E")!=0)
    {
        if(strcmp(url,"B")==0)
        {
          _new=deletitem(_new);
          scanf("%s",url);
        }
        else
        {
          _new=insere_item(_new,url);
          scanf("%s",url);
        }
    }
    pilha *s;
    if(_new.tail==NULL)
    {
      printf("!");
    }
    else
    {
        while (_new.tail!=NULL)
        {
          s=_new.tail;
          _new.tail=_new.tail->next;
          free(s);
          printf("@");
        }
    }
    printf("\n");
  return 0;
}
