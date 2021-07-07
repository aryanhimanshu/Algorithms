var HashMap = function(){
  this._size = 0;
  this._map = {};
}


HashMap.prototype = {
  put: function(key, value){
    if(!this.containsKey(key)){
      this._size++;
    }
    this._map[key] = value;
  },

  remove:function(key){
    if(this.containsKey(key)){
      this._size--;
      var value = this._map[key];
      delete this._map[key];
      return value;
    }
    else{
      return null;
    }
  },

  containsKey: function(key){
    return this._map.hasOwnProperty(key);
  },

  containsValue: function(value){
    for(var key in this._map){
      if(this._map.hasOwnProperty(key)){
        if(this._map[key] === value){
          return true;
        }
      }
    }
    return false;
  },

  get: function(key){
    return this.containsKey(key) ? this._map[key] : null;
  },

  clear: function(key){
    this.size = 0;
    this._map= {};
  },

  keys: function(){
    var keys = [];
    for(var keys in this._map){
      if(this._map.hasOwnProperty(key)){
        keys.push(key);
      }
    }
    return keys;
  },

  values: function(){
    var values[];
    for(var key in this._map){
      if(this._map.hasOwnProperty(key)){
        values.push(this._map[key]);
      }
    }
  },

  size: function(){
    return this._size;
  }
};
