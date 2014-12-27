/*
WORKS APP ASSIGNMENT
---
NAME - Subham Modi
BRANCH/PROGRAMME - CSE/Dual(BT-MT)
URN - 10327729
COLLEGE - IIT Kanpur

Question-1 - Orienteering Game
*/

/*Header files required to use C++ standard library*/
#include <cstdio> //stdin stdout
#include <vector> //vector STL container
#include <cstring> //memset
#include <ctype.h> //isspace
#include <cstdlib> //exit status in case of wrong input argument
#include <queue> //queue STL container for bfs
#include <map> //map STl container
#include <climits> //INT_MAX use

using namespace std;

typedef pair<int, int> point; //type defining each point in 2D matrix by "point"

/*
Orienteering class which inputs orienteering game and comes up with the answer if the game
satisfies all the specifications
*/
class Orienteering {
	/*
	main function needs to call only Orienteering::main so rest all class methods and variables are private
	*/
	private:
		int w, h, checkpoint_count; //widht, height and number of checkpoints in game
		vector<vector<char> > game; //2D character array for storing board configuration
		point start, goal; //indexes of 'S' and 'G'
		map<int, point> checkpoints_by_ordering; //associate a unique ordering over checkpoints and maps it their indexes in game
		map<point, int> checkpoints_by_indexes; //maps indexes of checkpoints to their unique ordering
		int orienteering_utility_func(int **shortest_distance);
		bool check_ifPossible(int **shortest_distance);
		void bfs(int **shortest_distance, int **flag, int source);
	public:
		Orienteering();
	    void main();
};

/*
Unparametrized constructor of class Orienteering which inputs the game specification and configuration
and initializes class private members such as h, w, game, checkpoint_by_ordering etc with input.
Called as soon as an object of this class is created.
@param void
*/
Orienteering::Orienteering() {
	checkpoint_count = 0;
	vector<char> dummy_vector;	//dummy vector of int to intialize each row of game
	char temp_input;
	//input width and height of game
	if( scanf( "%d%d", &w, &h ) != 2 ) 
	{
	   printf("Expected two numbers as input.\n");
	   exit(1);
	}
	for(int i=0; i<h; i++) {
		game.push_back(dummy_vector);
		for(int j=0; j<w; j++) {
            do{
                temp_input = getchar();
            }while(isspace(temp_input));
			game[i].push_back(temp_input);	//inputting configuration of game map into 2D char vector game
			/*
			Checks for various possibility of inputted character and initializes various private members
			depending on their value.
			Both maps "checkpoints_by_ordering" and "checkpoints_by_numbering" keeps data about checkpoints, 'S'
			and 'G' only as other two characters won't contribute in the final answer.
			*/
			if(temp_input == 'S') {
				start.first = i;
				start.second = j;
				checkpoints_by_ordering[0] = make_pair(i, j);
				checkpoints_by_indexes[make_pair(i, j)] = 0;
			}
			else if(temp_input == 'G') {
				goal.first = i;
				goal.second = j;
			}
			else
				if(temp_input == '@') {
					checkpoints_by_ordering[++checkpoint_count] = make_pair(i, j);
					checkpoints_by_indexes[make_pair(i, j)] = checkpoint_count;
				}
		}
	}
	/*
	Maps "checkpoints_by_ordering" stores start('S') at 0 position. Then all the checkpoints are stored from 1 to
	"checkpoint_count" position. Then finally goal('G') is inserted at "checkpoint_count+1" position.
	*/
	checkpoints_by_ordering[checkpoint_count+1] = make_pair(goal.first, goal.second);
	checkpoints_by_indexes[make_pair(goal.first, goal.second)] = checkpoint_count+1;
}

/*
Private method of class Orienteering which checks wether the player can reach G or not by covering all the
checkpoints.
Called from Orienteering::main() method.
@param shortest_distance - (checkpoint_count+2)*(checkpoint_count+2) matrix storing shortest distance between
							each of 'S', '@' and 'G'
@return bool - True if possible, false o.w.
*/
bool Orienteering::check_ifPossible(int **shortest_distance) {
	for(int i=1; i<(checkpoint_count+2); i++)
		if(shortest_distance[0][i] == -1)
			return false;
	return true;
}

/*
Private method of class Orienteering which solves for the minimum distance path from 'S' to 'G' visiting all 
checkpoints atleast one. Approach is similar to dynamic programming formulation of TSP problem by considering
all subsets bin_subset of size 2 to (checkpoints+1) and subproblems as calculating minimum distance from 'S'
to each of the element in {bin_subset-'S'}.
Called by Orienteering::main method.
@param shortest_distance - (checkpoint_count+2)*(checkpoint_count+2) matrix storing shortest distance between
							each of 'S', '@' and 'G'
@param flag - To check whether an (i,j)th element of game is visited or not
@param source - source vertex from where bfs traversal starts
@return void
*/
void Orienteering::bfs(int **shortest_distance, int **flag, int source) {
	int adj_H, adj_W; //variables to consider valid neighbours
	point current_node;	//to store dequeued node from bfs queue

	shortest_distance[source][source] = 0; //initializing self diatance to 0
	flag[checkpoints_by_ordering[source].first][checkpoints_by_ordering[source].second] = 0; //initializing same as aboce

	queue<point> bfs_queue;	//bfs queue to implement bfs traversal. Stores indices of each element
	//inserting source node into queue
	bfs_queue.push(make_pair(checkpoints_by_ordering[source].first, checkpoints_by_ordering[source].second));

	while(!bfs_queue.empty()) {
		current_node = bfs_queue.front(); //front element in queue
		bfs_queue.pop();
		//All the possible vertical and horizontal neighbours of popped element. Validity is checked in the next step
		point adjs[4] = {make_pair(current_node.first-1, current_node.second), make_pair(current_node.first+1, current_node.second), make_pair(current_node.first, current_node.second-1), make_pair(current_node.first, current_node.second+1)};

		/*
		Considering all the neighbours one by one. If they are valid and not visited yet then we update their flag distance
		and insert them into the bfs queue. Along with these if they are one of {'S', '@', 'G'} then we set the current flag
		distance as the distance between the source and that node in apsp matrix "shortest_distance". Note we don't need to 
		do this for "." as they are not considered in our final problem solving function"
		*/
        for (int i=0; i<4; i++)
        {
            adj_H = adjs[i].first; //row index of ith neighbour
            adj_W = adjs[i].second; //column index of ith neighbour
            //checking validity
            if ((adj_H >= 0) && (adj_H < h) && (adj_W >= 0) && (adj_W < w) && (flag[adj_H][adj_W]==-1)  && (game[adj_H][adj_W] != '#')) {
                //inserting into queue and setting distance if valid node.
                bfs_queue.push(make_pair(adj_H, adj_W));
                flag[adj_H][adj_W] = flag[current_node.first][current_node.second] + 1;
	            if(game[adj_H][adj_W] != '#' && game[adj_H][adj_W] != '.')
					shortest_distance[source][checkpoints_by_indexes[adjs[i]]] = flag[adj_H][adj_W];
			}
        }
	}
	return;
}

/*
Private method of class Orienteering which solves for the minimum distance path from 'S' to 'G' visiting all 
checkpoints atleast one. Approach is similar to dynamic programming formulation of TSP problem by considering
all subsets bin_subset of size 2 to (checkpoints+1) and subproblems as calculating minimum distance from 'S'
to each of the element in {bin_subset-'S'}.
Called by Orienteering::main method.
@param shortest_distance - (checkpoint_count+2)*(checkpoint_count+2) matrix storing shortest distance between
							each of 'S', '@' and 'G'
@return int - minimum distance of out path satisfying all the configuration
*/
int Orienteering::orienteering_utility_func(int **shortest_distance) {
	//Base case when there are no checkpoints. Answer will just be the shortest distance between 'S' and 'G'
	if(checkpoint_count == 0)
		return shortest_distance[0][1];

	int i, j;	//loop variables
	/*
	nodes - number of nodes in TSP graph to calculate for minimum distance. 'G' not considered as it's the final node
			in our path
	bin_subset(always include node 'S') - binary representation having nodes bits. LSB as 'S' and rest as '@'.
										  Value 1 on a bit means that node is considered in the subset. Thus LSB = 1 always.
	*/
	int nodes = checkpoint_count+1, bin_subset; 

	//C(i, S) = The cost of the minimum cost path visiting each vertex in set S atleast once, starting at 'S' and ending at i.
	int **cost_array = new int*[nodes];
	for(i=0; i<nodes; i++)
		cost_array[i] = new int[1<<nodes];

	//Base case initialization for subset size of 2
	for(i=1; i<nodes; i++)
		cost_array[i][1^(1<<i)] = shortest_distance[0][i];

	//subset - integer array keeping track of elements which are currently considered
	int *subset = new int[nodes];
   	for(int size=3; size<=nodes; size++)	//size denoting size of considered subset
   	{
	   	for(i=1; i<size; i++)	//considering first |size-1| element in nodes for our subset
	   	    subset[i] = i;

		while(true)
		{
		    bin_subset = 1;
		    /*
		    Calculating binary representation of current subset. Ex- when size is 3 and nodes is 5, binset = 00111
		    telling that first two '@' and 'S' is considered in the subset
		    */
		    for(i=1; i<size; i++)
		    	bin_subset = bin_subset^(1<<subset[i]);	

		    //Go through all nodes in subset
			for(i=1; i<size; i++)
			{
				cost_array[subset[i]][bin_subset] = INT_MAX;
				for(j=1; j<size; j++)	//find second node connection in subset
				{
					if(subset[j] == subset[i])
						continue;
					//C(i, S) = min { C(j, S-{i}) + dis(j, i)} where j belongs to S, j != i and j != 'S'
					cost_array[subset[i]][bin_subset] = min(cost_array[subset[j]][bin_subset^(1<<(subset[i]))]+shortest_distance[subset[j]][subset[i]], cost_array[subset[i]][bin_subset]);
				}
			}

			//Computing next combination
			i = size-1;
			subset[i]++;
			/*
			In case when ith node considered in subset exceeds the worst possible position
			Example: nodes = 5, size =3 and bin_subset = 10011. When we do subset[i]++, 1 at MSB goes left and
			thus goes out of bound. Therefore we have to increase middle 1 and then again take the base combination, i.e.,
			01101
			*/
			while ((i > 1) && (subset[i] > (nodes-size+i))) {
				i--;
				subset[i]++;
			}

			//if the final combination for current sizeis computed the end while loop and increse the size of subset
			if (subset[1] > (nodes-size+1))
				break;
			//considering base combination again after recovering from above stated out of bound problem
			for (j=i+1; j<size; j++)
				subset[j] = subset[j-1] + 1;
		}
	}

	//Calculating final optimum from subset of size "nodes" and considering distance from each '@' to 'G'
	int minimum_distance = INT_MAX;
	for(i=1; i<nodes; i++)
		minimum_distance = min(cost_array[i][(1<<(nodes))-1]+shortest_distance[i][checkpoint_count+1], minimum_distance);

   	return minimum_distance;
}

/*
Public method of class Orienteering which reduces the given game into apsp matrix "shortest distance" of 
'@', 'S' and 'G' using bfs traversal in the given 2D character array "game". It then checks whether it is possible
to satisfy all the specifications and lastly, if yes, it calls Orienteeing game solver function 
"orienteering_utility_func" on this apsp matrix and solves the game.
Called by object of Orienteering class from main function.
@param void
@return void
*/
void Orienteering::main() {
	int **shortest_distance = new int*[checkpoint_count+2];	//for toring shortest distance between '@', 'S' and 'G'
	for(int i=0; i<(checkpoint_count+2); i++) {
		shortest_distance[i] = new int[checkpoint_count+2];
		memset(shortest_distance[i], -1, sizeof(int)*(checkpoint_count+2));
	}

	int **flag = new int*[h];	//flag array used in bfs traversal to check whether an (i,j)th element of game is visited or not
	for(int i=0; i<h; i++)
		flag[i] = new int[w];
	/*
	We don't need to call bfs from 'G' as tour ends there and we have to find minimum weight hamiltonian path
	from 'S' to 'G' instead of minimum weight hamiltonian cycle
	*/
	for(int i=0; i<(checkpoint_count+1); i++) {
		for(int j=0; j<h; j++)
			memset(flag[j], -1, sizeof(int)*w); //initialized flag to -1 at the start of bfs traversal for '@' and'S'
		bfs(shortest_distance, flag, i);
		/*
		Checking if according to the given configuration, is it possible to solve a game.
		We just check this only for 'S' whether there's a path from 'S' to all '@' and 'G' because if it's there
		then we can can always find the hamiltonian path satisfying all the specifications.
		*/
		if(i==0 && !check_ifPossible(shortest_distance)) {
			printf("-1\n");
			return;
		}
	}

	//calling orienteering game solver function which calculates minimum distance and outputs on STDOUT
	printf("%d\n", orienteering_utility_func(shortest_distance));
	return;
}

/*
Main function
*/
int main(int argc, char *argv[])
{
	Orienteering o; //An object of class Orienteering
	o.main(); //Calling orienteering game for solving it
	return 0;
}