void bubbleSort(int*, int);
void insertionSort(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void swap(int*, int*);
void quickSort(int*, int, int);
int partition(int*, int, int);
void shellsort(int*, int);

void bubbleSort(int *array, int size){

	int swapVar;
	bool isSwapped = true;

	for(int i = 0; i < size-1; i++){
		
		if(!isSwapped){
			break;
		}

		isSwapped = false;

		for(int j = 0; j < size-1-i; j++){

			if(array[j] > array[j+1]){
				isSwapped = true;
				swapVar = array[j];
				array[j] = array[j+1];
				array[j+1] = swapVar;
			}
		}
	}
}


void insertionSort(int *array, int size){

	int key,j;

	for(int i = 1; i < size; i++){
		key = array[i];
		j = i-1;

	/* now move all elements that are greater than key
	 in array[0]...array[i-1] one position ahead
	*/
	 while(j>=0 && array[j] > key){
	 	array[j+1] = array[j];
	 	j--;
	 }

	 array[j+1] = key;

	}
}



void mergeSort(int *array, int leftIndex, int rightIndex){

	
	if(leftIndex < rightIndex){

		int middleIndex = (leftIndex + rightIndex)/2;

		mergeSort(array, leftIndex, middleIndex);
		mergeSort(array, middleIndex+1, rightIndex);

		merge(array,leftIndex,middleIndex,rightIndex);
	}
}


// merge subroutine 

void merge(int *array, int leftIndex, int middleIndex, int rightIndex){



	int leftArraySize = middleIndex - leftIndex + 1;
	int rightArraySize = rightIndex - middleIndex;

	int leftArray[leftArraySize];
	int rightArray[rightArraySize];

	int i,j,k;

	for(i = 0; i < leftArraySize; i++){
		leftArray[i] = array[leftIndex + i];
	}

	for(j = 0; j < rightArraySize; j++){
		rightArray[j] = array[middleIndex + 1 + j];
	}

	//coping leftArray and rightArray in main array in ascending order

	i = j = 0;
	k = leftIndex;

	while(i < leftArraySize && j < rightArraySize){
		if(leftArray[i] < rightArray[j]){
			array[k] = leftArray[i++];
		}else{
			array[k] = rightArray[j++];
		}
		k++;
	}

	//copying the leftover elements from leftArray and rightArray if any


	while(i < leftArraySize){
		array[k++] = leftArray[i++];
	}

	while(j < rightArraySize){
		array[k++] = rightArray[j++];
	}
}


// quick sort

void quickSort(int *array, int leftIndex, int rightIndex){

	if(leftIndex < rightIndex){

		int pivot = partition(array, leftIndex, rightIndex);

		quickSort(array, leftIndex, pivot - 1);
		quickSort(array, pivot + 1, rightIndex);
	}
}

// partition subroutine
/* we will use two pointers i and j, i will point to the rightmost element smaller than the pivotElement and j 
   will be used to traverse the array
*/

int partition(int *array, int leftIndex, int rightIndex){

	int pivot = rightIndex;
	int pivotElement = array[pivot];

	int i = leftIndex - 1;

	// iterate the array from leftIndext to rightIndex - 1;

	for(int j = leftIndex; j < rightIndex; j++){

		if(array[j] <= pivotElement){
			i++;
			swap(&array[j], &array[i]);
		}
	}

	swap(&array[i+1],&array[pivot]);

	return (i+1);
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

//SHELL SORT
/*at first it will sort the index (size/2) and size .
then it will sortthe indexes (size/4),(size/2),3*size/2
and so on..

for eg: if the size is 5.
then at first it will sort index 4,2 and 0.
 then it will sort index 3,1.
then it will sort all the indexes 4,3,2,1,0.
*/

void shellsort(int *array, int size){
   int i,j,k,tmp;

    for(i=size/2; i>0; i=i/2)
 {
   for(j=i; j<size; j++)
   {
     for(k=j-i; k>=0; k=k-i)
     {
        if(array[k+i]>=array[k])
            break;
        else
        {
            tmp=array[k];
            array[k]=array[k+i];
            array[k+i]=tmp;
        }
     }
   }
 }

 for(k=0; k<size; k++)
     printf("%d\t",array[k]);

}