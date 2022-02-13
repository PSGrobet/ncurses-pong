#include <iostream>

void move(int *arr, int chg, int arrSize );
void printArr(int arr[], int length);

int main(){
	
	int position[5] = {1, 2, 3, 4, 5};
	printArr(position, 5);
	position[4] = 10;
	std::cout << position[4] << "\n";
	int size { sizeof position / sizeof position[0] };
	
	std::cout << "Before move():\n";
	printArr(position, 5);

	move(position, -1, 5);

	std::cout << "After move():\n";
	printArr(position, 5);

}

void move(int *arr, int chg, int arrSize )
{
	for( int i = 0; i < arrSize; i++ )
	{
		arr[i] += chg;
	}
	std::cout << "Inside function: \n";
	printArr(arr, 5);
}

void printArr(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << "[" << i << "] = "
					<< arr[i] << "\n";
	}
}
