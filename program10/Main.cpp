/*************************
 Name: Mubasshir Karim
 WSU ID : G498M939
 Program: Chapter 10
 *************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <limits.h>
#include <stdio.h>
#include <sstream>
#include <string>


#define V 6
//initializing array function
void sort(int arr[], int l)
{
    //initializing variables
        int a, b;
        int temp;
        //for loop
        for(a = 0;a < (l - 1);a++)
        {
            for(b = (a + 1); b < l; b++)
            {
                if(arr[a] < arr[b])
                {
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                }
            }

        }
    
}
//initializing letters and numbers
int t(char symb)
{

    //switch statement
	switch(symb)
    {

        case 'a': return 0;
                    break;

        case 'b': return 1;
                    break;

        case 'c': return 2;
                    break;

        case 'd': return 3;
                    break;

        case 'e': return 4;
                    break;

        case 'f': return 5;
                    break;

        case '1': return 0;
                    break;

        case '2': return 1;
                    break;

        case '3': return 2;
                    break;

        case '4': return 3;
                    break;

        case '5': return 4;
                    break;

        case '6': return 5;
                    break;
	
        default: return 0;
                    break;

	}


}
//initializing getinput function
int get_in(char* d, int a_graph1[][V], int a_graph2[][V], int deg1[], int deg2[], int &ver1, int &ver2, int &bed1, int &bed2)
{
    //type definitions
	std::string li1;
	std::string edg1;
	std::string li2;
	std::string edg2;
    
    //type definitions for if stream
	std::ifstream matrixfile(f);
	char u_li1[256];
	char u_edg1[256];
	char u_li2[256];
	char u_edg2[256];
    
    //getline function
	matrixfile.getline(u_li1,256);
	matrixfile.getline(u_edg1,256);
	matrixfile.getline(u_li2,256);
	matrixfile.getline(u_edg2,256);
    
    //equalising list and edges
	li1 = u_li1;
	li2 = u_li2;
	edg1 = u_edg1;
	edg2 = u_edg2;
    
    //for loop
	for(int a = 0; a < 100; a++)
    {
        //if conditions inside for loops
		if(u_edg1[m] == '(') bed1++;
		if(u_li1[m] == ',' ) ver1++;
		if(u_edg1[m] == 'a') deg1[t('a')] ++;
		if(u_edg1[m] == 'b') deg1[t('b')] ++;
		if(u_edg1[m] == 'c') deg1[t('c')] ++;
		if(u_edg1[m] == 'd') deg1[t('d')] ++;
		if(u_edg1[m] == 'e') deg1[t('e')] ++;
		if(u_edg1[m] == 'f') deg1[t('f')] ++;

		if(u_edg2[m] == '(') bed2++;
		if(u_li1[m] == ',' ) ver2++;

		if(u_edg2[m] == '1') deg2[t('1')] ++;
		if(u_edg2[m] == '2') deg2[t('2')] ++;
		if(u_edg2[m] == '3') deg2[t('3')] ++;
		if(u_edg2[m] == '4') deg2[t('4')] ++;
		if(u_edg2[m] == '5') deg2[t('5')] ++;
		if(u_edg2[m] == '6') deg2[t('6')] ++;


    }
//removing and beginning for the edges
    edg1.erase(std::remove(edg1.begin(), edg1.end(), '('), edg1.end());
    edg1.erase(std::remove(edg1.begin(), edg1.end(), ','), edg1.end());
    edg1.erase(std::remove(edg1.begin(), edg1.end(), ')'), edg1.end());
    edg1.erase(std::remove(edg1.begin(), edg1.end(), ';'), edg1.end());

    edg2.erase(std::remove(edg2.begin(), edg2.end(), '('), edg2.end());
	edg2.erase(std::remove(edg2.begin(), edg2.end(), ','), edg2.end());
	edg2.erase(std::remove(edg2.begin(), edg2.end(), ')'), edg2.end());
	edg2.erase(std::remove(edg2.begin(), edg2.end(), ';'), edg2.end());


//using stream buffer
    std::stringbuf edg1_buf(edg1);
    std::istream edg1format(&edg1_buf);

    std::stringbuf edg2_buf(edg2);
    std::istream edg2format(&edg2_buf);
    
//for loop with new char variables
    for(int a = 0; a < bed1; a++)
    {
    	char x;
    	char y;
    	edg1format >> x;
    	edg1format >> y;

    	a_graph1[t(x)][t(y)] = 1;
    	a_graph1[t(y)][t(x)] = 1;
    }

    for(int a = 0; a < bed2; a++)
    {
      	char x;
      	char y;
      	edg2format >> x;
      	edg2format >> y;

      	a_graph2[t(x)][t(y)] = 1;
      	a_graph2[t(y)][t(x)] = 1;
      }

}
//array copy is initialized here
void arr_cpy(int ar1[], int ar2[], int size)
{

	for(int a = 0; a < size; a++ )
    {

		ar1[a] = ar2[a];
	}

}
//comparing array
int cmp_arr(int ar1[], int ar2[])
{
	for(int a = 0; a < V ; a++) if(ar1[a] != ar2[a]) return 0;
	return 1;

}
//bool function for T or F
bool cmp_mat(int ar1[][V], int ar2[][V])
{

	int matched1[V] = {0};
	int matched2[V] = {0};

	for(int a = 0; a < V; a++)
    {

		for(int b = 0; b < V; b++)
        {

			if( (cmp_arr (ar1[a], ar2[b]) == 1 )&& (matched1[b] != 1) && (matched2[a] != 1))
            {
				matched1[b] = 1;
				matched2[a] = 1;
			}
		}

	}
	for(int a = 0; a < V; a++)
    {

		if(matched2[a] == 0) return 0;

	}
	return 1;


}


int a_dis(int dis[], bool sptSet[])
{
   //min value initialized
   int min = INT_MAX, a_in;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dis[v] <= min)
         min = dis[v], a_in = v;

   return a_in;
}

//initializing graph, src and distance
void cac(int graph[V][V], int src, int dis[])
{
    //bool function for T or F
     bool sptSet[V];
     for (int a = 0; a < V; a++)
        dis[a] = INT_MAX, sptSet[a] = false;
     dis[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = a_dis(dis, sptSet);

       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dis[u] != INT_MAX
                                       && dis[u]+graph[u][v] < dis[v])
            dis[v] = dis[u] + graph[u][v];
     }


}
//initializing main
int main(int comm, char * vocc[])
{
    //initializing matrixes with 1 and 0
	int ver1 = 1;
	int ver2 = 1;
	int edg1 = 0;
	int edg2 = 0;
	int deg1[V] = {0};
	int deg2[V] = {0};
	int dis1[V][V] = {0};
	int dis2[V][V] = {0};

   int graph1[V][V] = {0};
   int graph2[V][V] = {0};

   get_in(vocc[1], graph1,graph2,ver1,ver2, edg1, edg2, deg1, deg2);

   for(int a = 0; a < V; a++)
   {
    cac(graph1, a, dis1[a]);
    cac(graph2, a, dis2[a]);
   }
//conditions for output
   	if(edg1 != edg2)
    {
        
   		std::cout << "YES" ;

   		return 0;
   	}

	if(ver1 != ver2)
    {

   		std::cout << "YES" ;

   		return 0;
   	}
	sort(deg1,V);
	sort(deg2,V);
	if(cmp_arr(deg1, deg2) == 0)
    {

		std::cout << "YES" << std::endl;
		return 0;

	}

	for(int a = 0; a < V; a++ )
    {
		sort(dis1[a], V);
		sort(dis2[a], V);

	}

    if( cmp_mat(dis1,dis2) == 1) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}

