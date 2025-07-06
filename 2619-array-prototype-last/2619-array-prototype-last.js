/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    let index=this.length-1;
    console.log(index);
    if(index<0){
        return -1;
    }
    return this[index];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */


//  Json.parse => converting a object to a json