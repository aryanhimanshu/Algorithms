int BinarySearch(string arr[], int size, string value) {
	int first = 0,last = size - 1, middle, position = -1;
	/* Sets position to -1 so returns -1 if value not found*/
	bool found = false;
	//While the value isn't found and there are indexs left to search the function will continue
	while (!found && first <= last) { 
		//Sets middle as the middle index between first and last
		middle = (first + last) / 2;
		//if value equals the index middle in the array
		if (arr[middle] == value){
			//found is set to true to no longer continue the while loop
			found = true; 
			//position is set to the index at which value was first found
			position = middle;
		//Checks to see if value is less that searched index
		} else if (arr[middle] > value){
			//sets last as the index below the middle index
			 last = middle - 1;
		//Checks to see if the value is greater than searched index
		} else {
			//sets first as the index above the middle index
			first = middle + 1;
		}
		//returns position which is the index of the found value
	} return position;
}