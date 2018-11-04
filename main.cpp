#include <bits/stdc++.h>

using namespace std;

int custom_array_size = 1e7;

void siftDown(vector<int> &numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду,
			maxChild = root * 2;    // запоминаем левый потомок
		  // иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
void heapSort(vector<int> &numbers, int array_size)
{
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}
void distribute(int bead, std::vector<int> &list1){
    if(bead > list1.size()) list1.resize(bead);
    for(int i = 0; i < bead; i++){
        list1[i]++;
    }
}
void beadSort(vector<int> &arr){

    int n = arr.size();
    std::vector<int> list1, list2;

    for(int i = 0; i < n; i ++)
        distribute(arr[i], list1);
    for(int i = 0; i < list1.size(); i++)
        distribute(list1[i], list2);
}
template<typename RandIter, typename Comp = std::less<typename std::iterator_traits<RandIter>::value_type>>
void bubble_sort(RandIter beg, RandIter end, Comp comp = Comp{})
{
    while (end - beg > 1)
    {
        RandIter  new_iter = beg;
        for (RandIter cpos = beg + 1; cpos != end; ++cpos)
            if (comp(*cpos, *(cpos - 1))) {std::swap(*cpos, *(cpos - 1)); new_iter = cpos;}
        end = new_iter;
    }
}
void merge_(int l, int r, int maxn, vector<int> &a) {
     if (r == l)
      return;
     if (r - l == 1) {
      if (a[r] < a[l])
       swap(a[r], a[l]);
      return;
     }
     int m = (r + l) / 2;
     merge_(l, m, maxn, a);
     merge_(m + 1, r, maxn, a);
     int arr[maxn];
     int xl = l;
     int xr = m + 1;
     int cur = 0;
     while (r - l + 1 != cur) {
      if (xl > m)
       arr[cur++] = a[xr++];
      else if (xr > r)
       arr[cur++] = a[xl++];
      else if (a[xl] > a[xr])
       arr[cur++] = a[xr++];
      else arr[cur++] = a[xl++];

     }
     for (int i = 0; i < cur; i++)
      a[i + l] = arr[i];
}
void CombSort(vector<int> &c){

    double fakt = 1.24;
    double step = c.size () - 1;

    while (step >= 1) {
        for ( int i = 0; i + step < c.size (); ++i ){
            if( c[i] > c[i + step] ){
                swap (c[i], c[i + step]);

            }
        }
        step /= fakt;
    }
    // сортировка пузырьком
    bool swapped = false;
    for ( int i = 0; i < c.size () - 1; i++ ){
        swapped = false;
        for ( int j = 0; j < c.size () - i - 1; j++ ){
            if( c[j] > c[j + 1] ){
                swap (c[j], c[j + 1]);
                swapped = true;
            }
        }

        if( !swapped )
            break;
    }
}
void Get_array(vector<int> &myvect){

    ifstream fin("input1e7.txt");
    for (int i = 0; i < custom_array_size; i++){
		fin >> myvect[i];
    }
	fin.close();

}

void HEAP_SORT(ostream& fout, vector<int> &Sorting_vector){

    Get_array(Sorting_vector);
	auto begin_1 = chrono::high_resolution_clock::now(); // time 1
	heapSort(Sorting_vector, custom_array_size);
	auto end_1 = chrono::high_resolution_clock::now(); // time 2

	fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to HeapSort array with " << custom_array_size << " integers.\n";
	//print_array(Sorting_vector.begin(), Sorting_vector.end());
}
void BEAD_SORT(ostream& fout, vector<int> &Sorting_vector){

    Get_array(Sorting_vector);
    auto begin_1 = chrono::high_resolution_clock::now(); // time 1
    beadSort(Sorting_vector);
    auto end_1 = chrono::high_resolution_clock::now(); // time 2

    fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to BeadSort array with " << custom_array_size << " integers.\n";
}
void BUBBLE_SORT(ostream& fout, vector<int> &Sorting_vector){

    Get_array(Sorting_vector);
    auto begin_1 = chrono::high_resolution_clock::now(); // time 1
    bubble_sort(Sorting_vector.begin(), Sorting_vector.end());
    auto end_1 = chrono::high_resolution_clock::now(); // time 2

    fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to BubbleSort array with " << custom_array_size << " integers.\n";
    //print_array(Sorting_vector.begin(), Sorting_vector.end());
}
void MERGE_SORT(ostream& fout, vector<int> &Sorting_vector){

    Get_array(Sorting_vector);
    auto begin_1 = chrono::high_resolution_clock::now(); // time 1
    merge_(0, custom_array_size-1, custom_array_size, Sorting_vector);
    auto end_1 = chrono::high_resolution_clock::now(); // time 2

    fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to MergeSort array with " << custom_array_size << " integers.\n";
    //print_array(Sorting_vector.begin(), Sorting_vector.end());
}
void COMB_SORT(ostream& fout, vector<int> &Sorting_vector){

    Get_array(Sorting_vector);
    auto begin_1 = chrono::high_resolution_clock::now(); // time 1
    CombSort(Sorting_vector);
    auto end_1 = chrono::high_resolution_clock::now(); // time 2

    fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to CombSort array with " << custom_array_size << " integers.\n";
    //print_array(Sorting_vector.begin(), Sorting_vector.end());
}
void std_sort(ostream& fout, vector<int> &Sorting_vector){
    Get_array(Sorting_vector);
    auto begin_1 = chrono::high_resolution_clock::now(); // time 1
    sort(Sorting_vector.begin(), Sorting_vector.end());
    auto end_1 = chrono::high_resolution_clock::now(); // time 2

    fout << "It took ";
	fout << chrono::duration_cast<chrono::milliseconds>(end_1-begin_1).count() << "ms";
	fout << " to std::sort array with " << custom_array_size << " integers.\n";
    //print_array(Sorting_vector.begin(), Sorting_vector.end());
}

void run(ostream& fout){

    ios::sync_with_stdio(false);
    cin.tie(0);

    auto print_array = [](auto beg, auto end) {
        while (beg != end) std::cout << *beg++ << ' ';
        std::cout << std::endl;
    };

	vector<int> Sorting_vector(custom_array_size);

	//first sort
	HEAP_SORT(fout, Sorting_vector);

    //second sort
    //BEAD_SORT(fout, Sorting_vector);

    //third sort
    BUBBLE_SORT(fout, Sorting_vector);

    //fourth sort
    //MERGE_SORT(fout, Sorting_vector);

    //fifth sort
    COMB_SORT(fout, Sorting_vector);

    //sixth sort
    std_sort(fout, Sorting_vector);
}


int main()
{
    ofstream fout("RightOrder8.txt");

    run(fout);

	return 0;
}
