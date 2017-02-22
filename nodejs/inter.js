var util = require('util')

function Base(){

	this.name = 'base';
	this.base = 1991;
	this.sayHello = function(){console.log("hello"+this.name);};
}

Base.prototype.showName = function()
{
	console.log(this.name);
}

function Sub()
{
	this.name = 'sub';
}

util.inherits(Sub,Base);
var objBase = new Base();
objBase.showName();
objBase.sayHello();

console.log(objBase);

var objSub = new Sub();
objSub.showName();
console.log(objSub);
//console.sayHello();

console.log(util.inspect(objSub,true));
