#include <iostream>

class Car
{
	std::string color;

	public:
		Car(std::string new_color)
		{
			color = new_color;
		}
		std::string getColor(){
			return color;
		}
};

std::string GetCarColor(Car car)
{
	return car.getColor();
}

int main(){
	Car mustang("red");
	std::cout << GetCarColor(mustang) << "\n";
	return 0;
}
