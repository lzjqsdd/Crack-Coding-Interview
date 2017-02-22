var clc = require('cli-color');
console.log(clc.red('Text in red'));

console.log(clc.red.bgWhite.underline('Underline red text on white'));

console.log(clc.red('red')+'plain'+clc.blue('blue'));

console.log(clc.red('red'+clc.blue('blue')+'red'));
