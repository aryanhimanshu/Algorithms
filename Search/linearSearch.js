function(list, target){
  var result = null, t = 0, i = 0, value;
  for(; i < list.length; i++){
    value = list[i];
    if(value === target){
      t=1;
      result = i;
      break;
    }
  }
  if(t == 0 ) 
     return(-1)
  return result;
};
