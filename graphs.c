#include <stdio.h>

int main(){
	float adjacency_matrix[5][5];
	float edge_weight;
	int in_valence = 0, out_valence = 0;

	FILE *file = fopen("input.txt", "r");
	
	for(int i = 0; i < 8; i++){
		printf("Enter edge wegiths for vertex %d [15-17] ", i);
		for(int j = 0; j < 8; j++){
			fscanf(file, "%f", &edge_weight);
			adjacency_matrix[i][j] = edge_weight;
		}
	}

	for(int i = 0; i < 8; i++){
		printf("graph row[%d]", i+1);
		for(int j = 0; j < 8; j++) printf(" %.2f", adjacency_matrix[i][j]);
		printf(";\n");
	}

	// Calculate in valence
	for (int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(adjacency_matrix[j][i] != 0) in_valence++;
			if(adjacency_matrix[i][j] != 0) out_valence++;
		}
		printf("\nIn_valence for vertex %d - %d", i+1, in_valence);
		printf("\nOut_valence for vertex %d - %d", i+1, out_valence);
	}
	return 0;
}
