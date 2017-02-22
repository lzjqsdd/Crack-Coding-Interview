var events = require('events');
var eventEmitter = new events.EventEmitter();
var connectHandler = function connected(){
	console.log('connected success!');
	eventEmitter.emit('data_rece');
}

eventEmitter.on('connection',connectHandler);
eventEmitter.on('data_rece',function(){
	console.log('rece success');		
});

eventEmitter.emit('connection');
console.log('Done.');
