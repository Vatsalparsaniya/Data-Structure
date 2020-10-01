function fizzBuzz(){
	for(var i=1;i<=100;i++){
		var s=''
		if(i%3 === 0)
		{
			s+='Fizz';
		}
		if(i%5 === 0)
		{
			s+='Buzz';
		}
		if (s=='') 
		{
			console.log(i);
		}
		else
		{
			console.log(s);
		}
	}
}
