const counter = function (array, key) {
    let result = [];
    const arrayCopy = [...array]; // ES6 way to clone or copy an array to new array

    arrayCopy.sort()
    for (let i = 0; i < arrayCopy.length; i++) {
        if (arrayCopy[i] === key) result.push(arrayCopy[i]);
    }
    return result.length;
}

/*
example use in console:
> const data = [5,6,1,4,5,7,8,2,4,6,3,2,6,6,3,5,5,2,10];
> counter(data, 5);
Output:
<- 4
*/