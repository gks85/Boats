#include <iostream>
#include <fstream>
using namespace std;

int maxWeight(int* weight, int n, int index)
{
	int max = 0, temp = 0;
	for (int i = index; i < n; i++) {
		if (weight[i] > max)
			max = weight[i];
		if (weight[i] == max && i != index) {
			temp = weight[index];
			weight[index] = max;
			weight[i] = temp;
		}
	}
	return max;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string inname = "INPUT.TXT"; string outname = "OUTPUT.TXT";

	int n = 0, d = 0, minIndex = 0, maxIndex = 0;
	int boat = 0;
	int* weight = nullptr;

	ifstream in(inname);
	if (in.is_open()) {
		in >> n >> d;
		weight = new int[n];
		for (int i = 0; !in.eof() && i < n; i++) {
			in >> weight[i];
		}
	}
	in.close();

	for (int i = 0; i < n; i++)
		weight[i] = maxWeight(weight, n, i);
	minIndex = n - 1;

	while (maxIndex < minIndex) {
		int inter = d - weight[maxIndex];
		maxIndex++;
		boat++;
		if (inter >= weight[minIndex]) 
			minIndex--;
	}

	ofstream out(outname);
	if (out.is_open())
		out << boat;
	out.close();

	delete[] weight;
	return 0;
}