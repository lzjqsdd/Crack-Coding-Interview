function exe(someFun,value)
{
	someFun(value);
}

exe(function(word){console.log(word)},"Hello");
