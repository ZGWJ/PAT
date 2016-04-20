#include <stdio.h>

struct Node{
    int before;
    int data;
    int next;
}Node[100000];

int main(){
    int first_ad,N,K,address,j=0,last=-1,temp=0,flag=0;
    scanf("%d %d %d",&first_ad,&N,&K);
    for (int i=0; i<N; i++) {
        scanf("%d",&address);
        scanf("%d %d",&Node[address].data,&Node[address].next);
        if(Node[address].next!=-1){
            Node[Node[address].next].before=address;
        }
    }
    for (int i=1; i<=N; i++) {
        if (i==1) {
            j=first_ad;
        }else{
            if (flag==1) {
                if (temp==-1) {
                    break;
                }
                j=temp;
                flag=0;
            }else{
                if (j==-1) {
                    break;
                }
                j=Node[j].next;
            }
        }
        if (i%K==0) {
            if (j==-1) {
                break;
            }
            int l=j;
            temp=Node[j].next;
            flag=1;
            for (int k=1; k<=K; k++) {
                Node[l].next=Node[l].before;
                if (k==K) {
                    Node[l].next=temp;
                }
                if (Node[l].next==-1) {
                    printf("%05d %d %d\n",l,Node[l].data,Node[l].next);
                }else{
                    printf("%05d %d %05d\n",l,Node[l].data,Node[l].next);
                }
                l=Node[l].before;
            }
            last=temp;
        }
    }
    if (last==-1) {
        last=first_ad;
    }
    do{
        if (flag==1) {
            break;
        }
        if (Node[last].next==-1) {
            printf("%05d %d %d\n",last,Node[last].data,Node[last].next);
        }else{
            printf("%05d %d %05d\n",last,Node[last].data,Node[last].next);
        }
        last=Node[last].next;
    }while (last!=-1);
}