/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let resultArr=[];
    let i=0;
    arr.forEach(n => {
        if(fn(arr[i],i))
            resultArr.push(n);
        i++
    });
    return resultArr;
};