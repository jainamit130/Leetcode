/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let resultArr=[];
    let i=0;
    arr.forEach(n => {
        resultArr.push(fn(n,i));
        i++;
    })
    return resultArr;
};