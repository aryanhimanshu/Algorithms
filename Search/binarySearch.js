function binarySearch(sortedArray, value){
	var midIndex = Math.floor(sortedArray.length/2);
    var midValue = sortedArray[midIndex];
	
	if(sortedArray == null || sortedArray.length == 0 ){
		return -1; 
	}else if (midIndex == 0){
        if (midValue == value){
            return midValue;
        }else{
            return -1;
        }
    }else if(midValue == value){
	    return midValue;
	}else if (value < midValue){
		return binarySearch(sortedArray.slice(0, midIndex), value);
	}else{
		return binarySearch(sortedArray.slice(midIndex, sortedArray.length), value);
	}
}

