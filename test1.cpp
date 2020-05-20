#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string>
#define INF 9999
#define V 20
using namespace std;
int findMin(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

int isMarked(int v, int markedVertices[], int markedVerticesIdx) {

	int i = 0;
	for (i = 0; i < markedVerticesIdx; i++) {
		if (v == markedVertices[i]) {
			return 1;
		}
	}

	return 0;
}

void dijkstra(int graph[V][V], int src, int dest ,string locations[20]) {


	string temp;
	int i, r, c,
		tmpC,
		min,
		currVertex,
		edgeWt = 0,
		destValue = 0,
		markedValue = 0,
		wtTableR = 0,
		markedVerticesIdx = 0;

	int shortestPathVertices[V] = {-1};
	int shortestPathVerticesIdx = 0;

	int weightTable[V][V];
	for (r = 0; r < V; r++) {
		for (c = 0; c < V; c++) {
			weightTable[r][c] = INF;
		}
	}
	weightTable[wtTableR++][src] = 0;

	int markedVertices[V] = {-1};
	markedVertices[markedVerticesIdx++] = src;
	currVertex = src;

	while(currVertex != dest) {

		for (i = 0; i < markedVerticesIdx; i++) {
			c = markedVertices[i];
			weightTable[wtTableR][c] = weightTable[wtTableR - 1][c];
		}

		for (c = 0; c < V; c++) {

			if (c != currVertex && !isMarked(c, markedVertices, markedVerticesIdx)) {

				edgeWt = graph[currVertex][c];
				destValue = weightTable[wtTableR - 1][c];
				markedValue = weightTable[wtTableR][currVertex];

				min = findMin(destValue, markedValue + edgeWt);

				weightTable[wtTableR][c] = min;

			}

		}

		min = INF;
		for (c = 0; c < V; c++) {

			if (!isMarked(c, markedVertices, markedVerticesIdx)) {
				if (weightTable[wtTableR][c] < min) {
					min = weightTable[wtTableR][c];
					tmpC = c;
				}
			}

		}

		markedVertices[markedVerticesIdx++] = tmpC;
		currVertex = tmpC;
		wtTableR++;

	}

	c = dest;
	shortestPathVertices[shortestPathVerticesIdx++] = c;
	markedValue = weightTable[wtTableR - 1][dest];
	for (r = wtTableR - 2; r >= 0; r--) {

		if (weightTable[r][c] != markedValue) {
			c = markedVertices[r];
			markedValue = weightTable[r][c];
			shortestPathVertices[shortestPathVerticesIdx++] = c;
		}

	}

	printf("Shortest Path between %d and %d\n", src, dest);
	for (i = shortestPathVerticesIdx-1; i >= 0; i--) {
            temp=locations[shortestPathVertices[i]];
		//printf("%c", temp);
		cout<<temp;
		if (i > 0) {
			printf(" --> ");
		}
	}
	printf("\n");
	printf("Total distance to be covered is: %d\n", weightTable[wtTableR-1][dest]);

}

int main() {

int src,
    dest,
    mode;
int graph_mix[V][V];
int graph_bus[V][V];
int graph_metro[V][V];
string locations[20];
locations[0]="PAPUNYA";
locations[1]="HAASTS BLUFF";
locations[2]="MOUNT ZEIL";
locations[3]="AREYONGA";
locations[4]="MEREENIE";
locations[5]="HERMANNSBURG";
locations[6]="WALLACE ROCKHOLE";
locations[7]="WEST MACDONNELL NATIONAL PARK";
locations[8]="ALICE SPRINGS";
locations[9]="OWEN SPRING RESERVES";
locations[10]="GHAN";
locations[11]="IMANPA";
locations[12]="YULARA";
locations[13]="MUTITJULU";
locations[14]="MARLA ";
locations[15]="COOBER PEDY";
locations[16]="TALLARINGA";
locations[17]="WILLIAM CREEK";
locations[18]="OODNADATTA";
locations[19]="MARREE";


  string line,line1,line2;
  int x;
  int i=0,j=-1;
  ifstream myfile ("graph_mix.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //x=(int*)line;
      stringstream geek(line);
      geek >> x;
      j++;
      graph_mix[i][j]=x;
      //cout << x<<" ";
      //cout<< i <<" "<< j<<endl;
      if(j==19)
      {
        //cout << endl;
        j=-1;
        i++;
      }
    }
    myfile.close();
    //system("CLS");
  }

  else
  {
    cout << "Unable to open mixed graph file";
    cout<<endl;
  }



fflush(stdout);
int x2;
  i=0,j=-1;
  ifstream myfile2 ("graph_bus.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line1) )
    {
      //x=(int*)line;

      stringstream geek(line1);
      geek >> x2;
      j++;
      graph_bus[i][j]=x2;
      //cout << x2<<" ";
      //cout<< i <<" "<< j<<endl;
      if(j==19)
      {
        //cout << endl;
        j=-1;
        i++;
      }
      if(i==20)
        break;
    }
    myfile2.close();
  }

  else
  {
    cout << "Unable to open bus graph file";
    cout<<endl;
  }

    //int x;

  i=0,j=-1;
  ifstream myfile3 ("graph_metro.txt");
  if (myfile3.is_open())
  {
    while ( getline (myfile3,line2) )
    {
      //x=(int*)line;
      stringstream geek(line2);
      geek >> x;
      j++;
      graph_metro[i][j]=x;
      //cout << x<<" ";
      //cout<< i <<" "<< j<<endl;
      if(j==19)
      {
        //cout << endl;
        j=-1;
        i++;
      }
      if(i==20)
        break;
    }


    myfile3.close();
  }

  else
    {
        cout << "Unable to open metro graph file";
        cout<<endl;
    }



    int choice;
    int zoo;


while(true){
    cout<<"Select the location you want to travel to from your source location as :"<<endl;




    for(int i=0;i<20;i++)
    {
        cout<<i<<" for " << locations[i]<<endl;
    }




    cout<<"Enter the source city"<<endl;
    cin>>src;
	//int src = 0;
	cout<<"Enter the destination city"<<endl;
	cin>>dest;
	//int dest = 2;
	if(src>19 || dest>19)
        {
            cout<<"Entered source location or destination is incorrect";
            cout<<endl;
            cout<<"Do you want to enter locations again"<<endl;
            cout<<"IF yes -- Enter 1"<<endl;
            cout<<"Else enter any other key"<<endl;
            cin>>zoo;
            if(zoo==1)
            {
                cout<<"Enter the locations again";
                cout<<endl;
                continue;
            }
            else
            {
                exit(0);
            }
        }
    if(src<0 || dest<0)
    {
        cout<<"Entered source location or destination is incorrect";
        cout<<endl;
        cout<<"Enter the locations again"<<endl;
        //cout<<endl;
        cout<<"IF yes -- Enter 1"<<endl;
        cout<<"Else enter any other key"<<endl;
        cin>>zoo;
        if(zoo==1)
        {
            cout<<"Enter the locations again";
            cout<<endl;
            continue;
        }
        else
        {
                exit(0);
        }
        //continue;
    }
    cout<<"Enter the preferred mode of communocation as:\n 1) FOR CAR \n 2)FOR BUSES \n 3) FOR METRO\n 0)TO EXIT"<<endl;
    cin>>mode;
    switch(mode)
    {
    case 1:


        dijkstra(graph_mix, src, dest, locations);
        break;
    case 2:
        //int a1= g.dijkstra(src, dst);
        dijkstra(graph_bus, src, dest, locations);
        break;

    case 3:
        dijkstra(graph_metro, src, dest,locations);
        break;
    case 0:
        exit(0);
    default:
        cout<<"Entered choice is invalid, please enter a valid choice : \n"<<endl;
        //dijkstra(graph, src, dest);
    }


    cout<<"Enter 0 to exit the program any other key to continue"<<endl;
    cin>>choice;
    if(choice==0)
        exit(0);




}
	return 0;
}
