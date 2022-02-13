#include <iostream>
#include <array>

int * setArray(int a);

//int length{5};
std::array<int, 5> setArray2(int a); // 
int main()
{
	int y{5};
	const int length{5};
	int *array;
	array = setArray(y);

	std::cout << "Array 1: \n";
	for(int i = 0; i < length; i++)
	{
		std::cout << array[i] << "\n";
	}

	int z{10};
	std::array<int, length> arr2; // tamaño tiene que ser const
	arr2 = setArray2(z);

	std::cout << "Array 2:\n";
	for(int i = 0; i < length; i++)
	{
		std::cout << arr2[i] << "\n";
	}
}

// Es necesario declara el array como static dentro de la función
// si no, generaria un "unexpected behavior"
// También, es necesario poner el tamaño del array directo,
// no permite hacerlo con una variable, pide un "constant".

// 'static': la variable se declara una sola vez, su valor se
// conserva aún si la función es llamada más de una vez.
int * setArray(int a)
{
	static int arr[5];
	for(int i = 0; i < 5; i++)
	{
		arr[i] = a + i;
	}
	return arr;
}

// cualquiera de las dos formas funciona, pero el tamaño
// siempre tieene que ser una constante y aun así no me deja
// usarla como parámetro.
std::array<int, 5> setArray2(int a)
{
	std::array<int, 5> arr;
	for(int i = 0; i < 5; i++)
	{
		arr[i] = a + i;
	}
	return arr;
}
