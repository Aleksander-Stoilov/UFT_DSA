#include <stdio.h>

#define FK_NUM_SUM 15

int main(){
	int adjacency_matrix[5][5];
	int edge_weight, in_valence, out_valence;

	for(int i = 0; i < 5; i++){
		printf("Enter edge wegiths for vertex %d [15-17] ", i);
		for(int j = 0; j < 5; j++){
			scanf("%d", &edge_weight);
			adjacency_matrix[i][j] = edge_weight;
		}
	}


	for(int i = 0; i < 5; i++){
		printf("graph row[%d]", i+1);
		for(int j = 0; j < 5; j++){
			printf(" %d", adjacency_matrix[i][j]);
		}
		printf(";\n");
	}

	// Calculate in valence
	for (int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(adjacency_matrix[j][i] != 0){
				in_valence++;
			}
			if(adjacency_matrix[i][j] != 0){
				out_valence++;
			}
		}
		printf("\nIn_valence for vertex %d - %d", i+1, in_valence);
		printf("\nOut_valence for vertex %d - %d", i+1, out_valence);
	}

	return 0;
}
