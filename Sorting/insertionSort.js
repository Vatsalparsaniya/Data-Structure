function insertionSort(arr){
    var i, len = arr.length, el, j;
  
    for(i = 1; i<len; i++){
      el = arr[i];
      j = i;
  
      while(j>0 && arr[j-1]>toInsert){
        arr[j] = arr[j-1];
        j--;
     }
  
     arr[j] = el;
    }
  
    return arr;
  }
       