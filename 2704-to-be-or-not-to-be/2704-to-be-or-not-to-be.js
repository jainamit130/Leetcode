/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    let value = val;
    const toBe = (testVal) => { 
        if (testVal === value) 
            return true;
        else 
            throw new Error("Not Equal")
        };
    const notToBe = (testVal) => { 
        if (testVal !== value) 
            return true;
        else 
            throw new Error("Equal")
        };
    return {
        toBe,
        notToBe
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */