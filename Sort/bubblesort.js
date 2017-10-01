/*Bubble Sort is a algorithm to sort a array it
* copares adjacent element and swaps thier position
*/
function bubbleSort(items) {
    var length = items.length;
    for (var i = (length - 1); i >= 0; i--) {
        //Number of passes
        for (var j = (length - i); j > 0; j--) {
            //Compare the adjacent positions
            if (items[j] < items[j - 1]) {
                //Swap the numbers
                var tmp = items[j];
                items[j] = items[j - 1];
                items[j - 1] = tmp;
            } 
        }
    }
}

//Implementation of bubbleSort

var ar=[5,6,7,8,1,2,12,14];
//Array before Sort
console.log(ar);
bubbleSort(ar);
//Array after sort
console.log(ar);
