function matrixPrint(m) {
    for(var i = 0; i < m.length; i++)
    console.log(m[i]);
}

function strset(s, i, c) {
    return s.substr(0, i) + c + s.substr(i+1);
}

function findPath(m, x, y) {
    console.log("------------------------");
    console.log("x=" + x + " y=" + y);
    matrixPrint(m);
    if (x >= 10 || y >= 15)
        return false;
    if (m[x][y] == '=')
        return false;
    if (m[x][y] == 'x')
        return false;
    if (m[x][y] == ' ') m[x] = strset(m[x], y, 'o');
    if (m[x][y] == 'o' && (x == 9 || y == 14)) 
        return true;
    if (y < 14 && m[x][y+1] == ' ') //向右
        if (findPath(m, x, y+1)) return true;
    if (x < 9 && m[x+1][y] == ' ') //向下
        if (findPath(m, x+1, y)) return true;
    if (y > 0 && m[x][y-1] == ' ') //向左
        if (findPath(m, x, y-1)) return true;
    if (x > 0 && m[x-1][y] == ' ') //向上
        if (findPath(m, x-1, y)) return true;
    // m[x][y]='+';  這樣寫不正確，m是字串不能直接改值，要用substr
    m[x] = strset(m[x], y, 'x');
    return false;
}

var m = ["===============", 
         "== =     ======",
         "     === ======",
         "= ===       ===",
         "=  =  == == ===",
         "===== ===== ===",
         "===     === ===",
         "=== ===  == ===",
         "===   == ======",
         "===== ========="];

findPath(m, 2, 0);
console.log("------------------------");
matrixPrint(m);