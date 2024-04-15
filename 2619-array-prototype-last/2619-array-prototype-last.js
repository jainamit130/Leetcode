/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    let index=this.length-1;
    if(this[index])
        return this[index];
    else
        return -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */


//  Json.parse => converting a object to a json