#include <iostream>
#include <stdio.h>
class KnapSack{
/**
 *This function compares two integers and returns the max of the two
 */
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
/**
 *Returns the max val that can be put in a knapsack that has a max 
 * Weight 
 */
	int knapSack(int maxW, int weight[], int val[], int n){
		int i;
		int w;
		int k[n+1][maxW+1];
		//This builds table k[][]
		for(i=0; i<=n; i++){
			for(w=0; w<=maxW; w++){
				if(i==0 || w==0){
					k[i][w] = 0;
				}
				else if(weight[i-1] <= w){
					k[i][w]=max(val[i-1] + k[i-1][w-weight[i-1]], k[i-1][w]);
				}
				else{
					k[i][w]=k[i-1][w];	
				}
			}
		}
			return k[n][maxW];
	}
/**
 * This tries the algorithm with sample values and weights 
 * and then prints the max value that can be put in the knapsack
 */
	int main(){
		int val[] = {100,350,225,67,275,168};
		int weight[] = {15,25,45,30,23,37};
		int maxW = 50;
		int n = sizeof(val)/sizeof(val[0]);
		std::cout<<"%d", knapSack(maxW, weight, val, n<<endl;
		return 0;
	}
}; 
