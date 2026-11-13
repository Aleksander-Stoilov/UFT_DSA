#include <stdio.h>

int main(){
	FILE *file;

	file = fopen("input.txt", "r");

	if(file == NULL){
		perror("Failed opening input.txt file");
		return 1;
	}

	float adjacency_matrix[8][8];
	float edge_weight;
	int in_valence = 0, out_valence = 0;

        for(int i = 0; i < 8; i++){
            // printf("Enter edge wegiths for vertex %d [15-17] ", i);
            for(int j = 0; j < 8; j++){
                if(fscanf(file, "%f", &edge_weight) == 1) adjacency_matrix[i][j] = edge_weight;
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
		// resetting valence count
		in_valence = 0;
		out_valence = 0;
	}
	return 0;
}
