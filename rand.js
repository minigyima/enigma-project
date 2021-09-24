function shuffle(array) {
    var i = array.length,
        j = 0,
        temp;

    while (i--) {

        j = Math.floor(Math.random() * (i + 1));

        // swap randomly chosen element with current element
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

    }

    return array;
}

var ranNums = shuffle([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26]);

var obj = [];

for (i = 0; i < 26; i = i + 2) {
    let numPair = ranNums.slice(i, i + 2);
    obj[numPair[0]] = numPair[1];
    obj[numPair[1]] = numPair[0];
}

console.log(JSON.stringify(obj));