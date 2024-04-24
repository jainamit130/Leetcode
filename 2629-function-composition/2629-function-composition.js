/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    if(functions.length===0)
        return x;
    return functions.reduceRight(function(prevFunc,currFunc) {
        return function(x) {
            return currFunc(prevFunc(x));
    };
    });
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */