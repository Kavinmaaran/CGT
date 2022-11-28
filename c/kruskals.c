#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 20
int vertex,edge;
int weights[max][3];

void swap(int* a, int* b){
    int temp=(*b);
    *b=(*a);
    *a=temp;
}
void sort(int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(weights[min][2]>weights[j][2]){
                min=j;
            }
        }
        if(min!=i){
            swap(&weights[i][0],&weights[min][0]);
            swap(&weights[i][1],&weights[min][1]);
            swap(&weights[i][2],&weights[min][2]);
        }
    }
}
int check_loop(int list[vertex],int a,int b){
    if(list[b]==list[a]){
        return 1;
    }
    return 0;
}
int print(int a[vertex][vertex]){
    FILE *p;
    p = fopen("MST.txt","w");
    for(int i=0;i<vertex;i++){
        for(int j=i+1;j<vertex;j++){
            if(a[i][j]!=0){
                fprintf(p,"%d %d %d\n",i,j,a[i][j]);
            }
        }
    }
    fclose(p);
}
int kruskals(){
    int mst[vertex][vertex];
    for(int i=0;i<vertex;i++){
        for(int j=i;j<vertex;j++){
            mst[i][j]=mst[j][i]=0;
        }
    }
    sort(edge);
    FILE *p;
    p = fopen("MG.txt","w");
    for(int i=0;i<edge;i++){
        fprintf(p,"%d %d %d\n",weights[i][0],weights[i][1],weights[i][2]);
    }
    fclose(p);
    int mst_edge=0,count=0;
    int vertex_list[vertex];
    for(int i=0;i<vertex;i++){
        vertex_list[i]=i;
    }
    while(mst_edge<(vertex-1)){
        mst[weights[count][0]][weights[count][1]]=weights[count][2];
        
        if(check_loop(vertex_list,weights[count][1],weights[count][0])){
            mst[weights[count][0]][weights[count][1]]=0;
        }
        else{
            mst_edge++;
            int min=fmin(vertex_list[weights[count][1]],vertex_list[weights[count][0]]);
            int mx=fmax(vertex_list[weights[count][1]],vertex_list[weights[count][0]]);
            for(int i=0;i<vertex;i++){
                if(vertex_list[i]==mx){
                    vertex_list[i]=min;
                }
            }
        }
        count++;
    }
    print(mst);
}
int main(){
    printf("Enter the number of vertices ");
    scanf("%d",&vertex);
    printf("Enter the number of edges: ");
    scanf("%d",&edge);
    int count=0;
    printf("v1 v2 weight\n");
    while(count<edge){
        int v1,v2,w;
        scanf("%d %d %d",&v1,&v2,&w);
        if(v1<v2){
            weights[count][0]=v1;
            weights[count][1]=v2;
        }
        else{
            weights[count][0]=v2;
            weights[count][1]=v1;
        }
        weights[count][2]=w;
        count++;
    }
    printf("\n");   
    kruskals();
    // system("python3 net.py");
}
// 0 1 2
// 0 2 3
// 3 4 9
// 2 4 13
// 1 2 15
// 1 3 2
