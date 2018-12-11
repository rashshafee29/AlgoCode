#include<stdio.h>

main()
{
    int size,i,j,mini,minj,k=1,mincost=0,total=0,p,q;
    printf("\nPlease enter the number of elements in graph: ");
    scanf("%d",&size);
    char name[size][10];
    int graph[size][size],visited[size];


    printf("\nPlease enter the elements: \n");
    for(i=0;i<size;i++)
        scanf("%s",&name[i]);

    printf("\nPlease enter the adjacency matrix:\n");
    for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
                {
                    scanf("%d",&graph[i][j]);

                    if(graph[i][j]==0)
                        graph[i][j]=999;

                }
                visited[i]=0;
        }
        visited[0]=1;

    while(k<size)
    {
        mini=0;
        minj=0;
        for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                    {
                        if(graph[i][j]<graph[mini][minj] && visited[i]!=0)
                        {
                            mini=i;
                            minj=j;
                            mincost=graph[i][j];
                        }
                    }
            }

            if(visited[mini]==0 || visited[minj]==0)
            {
                printf("\n%d-edge (%s,%s) =%d\n",k++,name[mini],name[minj],mincost);
                total+=mincost;
                visited[minj]=1;
            }

             graph[mini][minj]=999;
             graph[minj][mini]=999;

    }
    printf("\nTotal minimum cost=%d.\n",total);
}
