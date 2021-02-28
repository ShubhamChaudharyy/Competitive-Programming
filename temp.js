function Calculator(str) { 
    var arithmeticOperators = ['+', '-', '/', '*'];
    console.log("hello",str);
    var replacedStr = str.replace(/(.)\(/g, "hi");
    console.log(replacedStr)
    return eval(replacedStr)
  }
  console.log(Calculator("(6+(3*2)-9+8)"))